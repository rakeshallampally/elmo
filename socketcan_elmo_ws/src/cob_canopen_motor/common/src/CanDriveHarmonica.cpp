
#include <assert.h>
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <unistd.h>

//-----------------------------------------------
CanDriveHarmonica::CanDriveHarmonica()
{
	// Parameter


	// Variables
	m_pCanCtrl = NULL;

	m_iStatusCtrl = 0;
	m_dPosGearMeasRad = 0;
	m_dAngleGearRadMem  = 0;
	m_dVelGearMeasRadS = 0;

	m_VelCalcTime.SetNow();

	m_bLimSwLeft = false;
	m_bLimSwRight = false;

	m_bLimitSwitchEnabled = false;

	m_iCountRequestDiv = 0;

	m_iMotorState = ST_PRE_INITIALIZED;
	m_bCurrentLimitOn = false;

	m_iNumAttempsRecFail = 0;

	m_SendTime.SetNow();
	m_StartTime.SetNow();

	m_bOutputOfFailure = false;

	m_bIsInitialized = false;




}

//-----------------------------------------------
void CanDriveHarmonica::setCanOpenParam( int iTxPDO1, int iTxPDO2, int iRxPDO2, int iTxSDO, int iRxSDO )
{
	m_ParamCanOpen.iTxPDO1 = iTxPDO1;
	m_ParamCanOpen.iTxPDO2 = iTxPDO2;
	m_ParamCanOpen.iRxPDO2 = iRxPDO2;
	m_ParamCanOpen.iTxSDO = iTxSDO;
	m_ParamCanOpen.iRxSDO = iRxSDO;

}

bool CanDriveHarmonica::stop()
{
	bool bRet = true;
	// motor off
	IntprtSetInt(8, 'M', 'O', 0, 0);
	usleep(20000);
	return bRet;
}
//-----------------------------------------------
bool CanDriveHarmonica::start()
{
	// motor on
	IntprtSetInt(8, 'M', 'O', 0, 1);
	usleep(20000);

	// ------------------- request status
	int iCnt;
	bool bRet = true;
	int iStatus;
	CanMsg Msg;

	//  clear the can buffer
	do
	{
		bRet = m_pCanCtrl->receiveMsg(&Msg);
	}
	while(bRet == true);

	// send request
	IntprtSetInt(4, 'S', 'R', 0, 0);

	iCnt = 0;
	while(true)
	{
		m_pCanCtrl->receiveMsg(&Msg);

		if( (Msg.getAt(0) == 'S') && (Msg.getAt(1) == 'R') )
		{
			iStatus = (Msg.getAt(7) << 24) | (Msg.getAt(6) << 16)
				| (Msg.getAt(5) << 8) | (Msg.getAt(4) );

			bRet = evalStatusRegister(iStatus);
			break;
		}

		if ( iCnt > 300 )
		{
			std::cout << "CanDriveHarmonica::enableMotor(): No answer on status request" << std::endl;
			bRet = false;
			break;
		}

		usleep(10000);
		iCnt++;
	}

	// ------------------- start watchdog timer

	return bRet;
}

//-----------------------------------------------
bool CanDriveHarmonica::reset()
{
	// repeat initialization

	// start network
	CanMsg msg;
	msg.m_iID  = 0;
	msg.m_iLen = 2;
	msg.set(1,0,0,0,0,0,0,0);
	m_pCanCtrl->transmitMsg(msg);

	// init and start
	bool bRet = init();
	bRet |= start();

	return bRet;
}
//-----------------------------------------------
bool CanDriveHarmonica::shutdown()
{
	std::cout << "shutdown drive " << m_DriveParam.getDriveIdent() << std::endl;

	IntprtSetInt(8, 'M', 'O', 0, 0);

	return true;
}

//-----------------------------------------------

//-----------------------------------------------

//-----------------------------------------------

//-----------------------------------------------
void CanDriveHarmonica::setGearPosVelRadS(double dPosGearRad, double dVelGearRadS)
{
	int iPosEncIncr;
	int iVelEncIncrPeriod;

	m_DriveParam.PosVelRadToIncr(dPosGearRad, dVelGearRadS, &iPosEncIncr, &iVelEncIncrPeriod);

	if(iVelEncIncrPeriod > m_DriveParam.getVelMax())
	{
		iVelEncIncrPeriod = (int)m_DriveParam.getVelMax();
	}

	if(iVelEncIncrPeriod < -m_DriveParam.getVelMax())
	{
		iVelEncIncrPeriod = (int)-m_DriveParam.getVelMax();
	}

	if(m_iTypeMotion == MOTIONTYPE_POSCTRL)
	{
			//new: set VELOCITY for PTP Motion
			IntprtSetInt(8, 'S', 'P', 0, iVelEncIncrPeriod);

			// Position Relativ ("PR") , because of positioning of driving wheel
			// which is not initialized to zero on a specific position
			// only when command is for homed steering wheel set absolute
			if (m_DriveParam.getIsSteer() == true)
				IntprtSetInt(8, 'P', 'A', 0, iPosEncIncr);
			else
				IntprtSetInt(8, 'P', 'R', 0, iPosEncIncr);

			IntprtSetInt(4, 'B', 'G', 0, 0);

	}

	if(m_iTypeMotion == MOTIONTYPE_VELCTRL)
	{
		iVelEncIncrPeriod *= m_DriveParam.getSign();
		IntprtSetInt(8, 'J', 'V', 0, iVelEncIncrPeriod);
		IntprtSetInt(4, 'B', 'G', 0, 0);
	}

	// request pos and vel by TPDO1, triggered by SYNC msg
	// (to request pos by SDO usesendSDOUpload(0x6064, 0) )
	CanMsg msg;
	msg.m_iID  = 0x80;
	msg.m_iLen = 0;
	msg.set(0,0,0,0,0,0,0,0);
	m_pCanCtrl->transmitMsg(msg);
}

//-----------------------------------------------
void CanDriveHarmonica::setGearVelRadS(double dVelGearRadS)
{
	int iVelEncIncrPeriod;

	// calc motor velocity from joint velocity
	iVelEncIncrPeriod = m_DriveParam.getSign() * m_DriveParam.VelGearRadSToVelMotIncrPeriod(dVelGearRadS);

	if(iVelEncIncrPeriod > m_DriveParam.getVelMax())
	{
		std::cout << "SteerVelo asked for " << iVelEncIncrPeriod << " EncIncrements" << std::endl;
		iVelEncIncrPeriod = (int)m_DriveParam.getVelMax();
	}

	if(iVelEncIncrPeriod < -m_DriveParam.getVelMax())
	{
		std::cout << "SteerVelo asked for " << iVelEncIncrPeriod << " EncIncrements" << std::endl;
		iVelEncIncrPeriod = -1 * (int)m_DriveParam.getVelMax();
	}

	IntprtSetInt(8, 'J', 'V', 0, iVelEncIncrPeriod);
	IntprtSetInt(4, 'B', 'G', 0, 0);

	// request pos and vel by TPDO1, triggered by SYNC msg
	// (to request pos by SDO use sendSDOUpload(0x6064, 0) )
	// sync msg is: iID 0x80 with msg (0,0,0,0,0,0,0,0)
	CanMsg msg;
	msg.m_iID  = 0x80;
	msg.m_iLen = 0;
	msg.set(0,0,0,0,0,0,0,0);
	m_pCanCtrl->transmitMsg(msg);

	// send heartbeat to keep watchdog inactive
	msg.m_iID  = 0x700;
	msg.m_iLen = 5;
	msg.set(0x00,0,0,0,0,0,0,0);
	m_pCanCtrl->transmitMsg(msg);

	m_CurrentTime.SetNow();
	double dt = m_CurrentTime - m_SendTime;
	if ((dt > 1.0) && m_bWatchdogActive)
	{
		std::cout << "Time between send velocity of motor " << m_DriveParam.getDriveIdent()
			<< " is too large: " << dt << " s" << std::endl;
	}
	m_SendTime.SetNow();


	// request status
	m_iCountRequestDiv++;
	if (m_iCountRequestDiv > m_Param.iDivForRequestStatus)
	{
		requestStatus();
		m_iCountRequestDiv = 0;
	}
}

//-----------------------------------------------


//-----------------------------------------------
void CanDriveHarmonica::IntprtSetInt(int iDataLen, char cCmdChar1, char cCmdChar2, int iIndex, int iData)
{
	char cIndex[2];
	char cInt[4];
	CanMsg CMsgTr;

	CMsgTr.m_iID = m_ParamCanOpen.iRxPDO2;
	CMsgTr.m_iLen = iDataLen;

	cIndex[0] = iIndex;
	cIndex[1] = (iIndex >> 8) & 0x3F;  // The two MSB must be 0. Cf. DSP 301 Implementation guide p. 39.

	cInt[0] = iData;
	cInt[1] = iData >> 8;
	cInt[2] = iData >> 16;
	cInt[3] = iData >> 24;

	CMsgTr.set(cCmdChar1, cCmdChar2, cIndex[0], cIndex[1], cInt[0], cInt[1], cInt[2], cInt[3]);
	m_pCanCtrl->transmitMsg(CMsgTr);
}



//-----------------------------------------------
