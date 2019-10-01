
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <unistd.h>

//-----------------------------------------------
CanDriveHarmonica::CanDriveHarmonica()
{

	m_pCanCtrl = NULL;
	m_sCanCtrl = NULL;

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

void CanDriveHarmonica::stop()
{

	// motor off
	IntprtSetInt(8, 'M', 'O', 0, 0);
	usleep(20000);

}
//-----------------------------------------------
void CanDriveHarmonica::start()
{
	// motor on
	std::cout << "m175445" << std::endl;
	int iVelEncIncrPeriod=5;
	IntprtSetInt(8, 'M', 'O', 0, 1);
	usleep(20000);
	std::cout << "mjdjdj" << std::endl;


	// ------------------- request status

	CanMsg Msg;




	while(true)
	{
		std::cout << "motor is on  555"  << std::endl;
		m_sCanCtrl->receiveMsg(&Msg);
		std::cout << "motor is on 888 "  << std::endl;

		if( (Msg.getAt(0) == 'M') && (Msg.getAt(1) == 'O') )
		{
			if( (Msg.getAt(4) == 1))
			{
				std::cout << "motor is on "  << std::endl;
				break;

			}

		}
		usleep(10000);
 }


IntprtSetInt(8, 'J', 'V', 0, iVelEncIncrPeriod);
std::cout << "motor is on 999999"  << std::endl;
	// ------------------- start watchdog timer
usleep(50000);


IntprtSetInt(8, 'M', 'O', 0, 0);

}

//-----------------------------------------------

//-----------------------------------------------
void CanDriveHarmonica::shutdown()
{
	std::cout << "shutdown drive " << std::endl;

	IntprtSetInt(8, 'M', 'O', 0, 0);


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
