
#include <ros/ros.h>
#include <cob_canctrl/cobcanctrl.h>
#include <cob_generic_can/cansocketdriver.h>
#include <cob_generic_can/cansocketreceiver.h>

cobcanctrl::cobcanctrl()
{

  if (n.hasParam("NumberOfMotors"))
	{
		n.getParam("NumberOfMotors", m_iNumMotors);
		ROS_INFO("NumberOfMotors loaded from Parameter-Server is: %i", m_iNumMotors);
	}
  else
	{
		m_iNumMotors = 0;
		ROS_WARN("NumberOfMotors not found on Parameter-Server, using default value: 0");
	}



  if (n.hasParam("NumberOfWheels"))
	{
		n.getParam("NumberOfWheels", m_iNumDrives);
		ROS_INFO("NumberOfWheels loaded from Parameter-Server is: %i", m_iNumDrives);
	}
	else
	{
		m_iNumDrives = 0;
		ROS_WARN("NumberOfWheels not found on Parameter-Server, using default value: 0");
	}
  m_pCanCtrl = NULL;
  m_sCanCtrl = NULL;

  m_vpMotor.resize(m_iNumMotors);

  for(int i=0; i<m_iNumMotors; i++)
	{
		m_vpMotor[i] = NULL;
	}


}



cobcanctrl::~cobcanctrl()
{

	if (m_pCanCtrl != NULL)
	{
		delete m_pCanCtrl;
	}
  if (m_sCanCtrl != NULL)
  {
    delete m_sCanCtrl;
  }

	for(unsigned int i = 0; i < m_vpMotor.size(); i++)
	{
		if (m_vpMotor[i] != NULL)
		{
			delete m_vpMotor[i];
		}
	}

}


void cobcanctrl::readingparams()
{
  ros::NodeHandle n;
  int iTypeCan = 0;

  if (n.hasParam("TypeCan/Can"))
	{
		n.getParam("TypeCan/Can", iTypeCan);
		ROS_INFO("TypeCan/Can loaded from Parameter-Server is: %i", iTypeCan);
	}
	else
	{
		iTypeCan = 1;
		ROS_WARN("TypeCan/Can not found on Parameter-Server, using default value: 1 (can-socket)");
	}



  if (iTypeCan == 1)
	{

		m_pCanCtrl = new cansocketdriver();
    m_sCanCtrl = new cansocketreceiver();
		ROS_INFO("Uses cansocket driver");
	}

  else
	{
		ROS_ERROR("Unknown value for TypeCan/Can!\n Should be 1 sockt can driver");
	}


  ROS_INFO("Loading CanOpenIDs from Parameter-Server");



  //Wheel 1
	// DriveMotor
	if(m_iNumDrives >= 1)
	{
		n.getParam("CanOpenIDs/TxPDO1_W1Drive", m_CanOpenIDParam.TxPDO1_W1Drive);
		n.getParam("CanOpenIDs/TxPDO2_W1Drive", m_CanOpenIDParam.TxPDO2_W1Drive);
		n.getParam("CanOpenIDs/RxPDO2_W1Drive", m_CanOpenIDParam.RxPDO2_W1Drive);
		n.getParam("CanOpenIDs/TxSDO_W1Drive", m_CanOpenIDParam.TxSDO_W1Drive);
		n.getParam("CanOpenIDs/RxSDO_W1Drive", m_CanOpenIDParam.RxSDO_W1Drive);
	}
	// SteerMotor
	if(m_iNumDrives >= 1)
	{
		n.getParam("CanOpenIDs/TxPDO1_W1Steer", m_CanOpenIDParam.TxPDO1_W1Steer);
		n.getParam("CanOpenIDs/TxPDO2_W1Steer", m_CanOpenIDParam.TxPDO2_W1Steer);
		n.getParam("CanOpenIDs/RxPDO2_W1Steer", m_CanOpenIDParam.RxPDO2_W1Steer);
		n.getParam("CanOpenIDs/TxSDO_W1Steer", m_CanOpenIDParam.TxSDO_W1Steer);
		n.getParam("CanOpenIDs/RxSDO_W1Steer", m_CanOpenIDParam.RxSDO_W1Steer);
	}
	// Wheel 2
	// DriveMotor
	if(m_iNumDrives >= 2)
	{
		n.getParam("CanOpenIDs/TxPDO1_W2Drive", m_CanOpenIDParam.TxPDO1_W2Drive);
		n.getParam("CanOpenIDs/TxPDO2_W2Drive", m_CanOpenIDParam.TxPDO2_W2Drive);
		n.getParam("CanOpenIDs/RxPDO2_W2Drive", m_CanOpenIDParam.RxPDO2_W2Drive);
		n.getParam("CanOpenIDs/TxSDO_W2Drive", m_CanOpenIDParam.TxSDO_W2Drive);
		n.getParam("CanOpenIDs/RxSDO_W2Drive", m_CanOpenIDParam.RxSDO_W2Drive);
	}
	// SteerMotor
	if(m_iNumDrives >= 2)
	{
		n.getParam("CanOpenIDs/TxPDO1_W2Steer", m_CanOpenIDParam.TxPDO1_W2Steer);
		n.getParam("CanOpenIDs/TxPDO2_W2Steer", m_CanOpenIDParam.TxPDO2_W2Steer);
		n.getParam("CanOpenIDs/RxPDO2_W2Steer", m_CanOpenIDParam.RxPDO2_W2Steer);
		n.getParam("CanOpenIDs/TxSDO_W2Steer", m_CanOpenIDParam.TxSDO_W2Steer);
		n.getParam("CanOpenIDs/RxSDO_W2Steer", m_CanOpenIDParam.RxSDO_W2Steer);
	}
	// Wheel 3
	// DriveMotor
	if(m_iNumDrives >= 3)
	{
		n.getParam("CanOpenIDs/TxPDO1_W3Drive", m_CanOpenIDParam.TxPDO1_W3Drive);
		n.getParam("CanOpenIDs/TxPDO2_W3Drive", m_CanOpenIDParam.TxPDO2_W3Drive);
		n.getParam("CanOpenIDs/RxPDO2_W3Drive", m_CanOpenIDParam.RxPDO2_W3Drive);
		n.getParam("CanOpenIDs/TxSDO_W3Drive", m_CanOpenIDParam.TxSDO_W3Drive);
		n.getParam("CanOpenIDs/RxSDO_W3Drive", m_CanOpenIDParam.RxSDO_W3Drive);
	}
	// SteerMotor
	if(m_iNumDrives >= 3)
	{
		n.getParam("CanOpenIDs/TxPDO1_W3Steer", m_CanOpenIDParam.TxPDO1_W3Steer);
		n.getParam("CanOpenIDs/TxPDO2_W3Steer", m_CanOpenIDParam.TxPDO2_W3Steer);
		n.getParam("CanOpenIDs/RxPDO2_W3Steer", m_CanOpenIDParam.RxPDO2_W3Steer);
		n.getParam("CanOpenIDs/TxSDO_W3Steer", m_CanOpenIDParam.TxSDO_W3Steer);
		n.getParam("CanOpenIDs/RxSDO_W3Steer", m_CanOpenIDParam.RxSDO_W3Steer);
	}
	// Wheel 4
	// DriveMotor
	if(m_iNumDrives >= 4)
	{
		n.getParam("CanOpenIDs/TxPDO1_W4Drive", m_CanOpenIDParam.TxPDO1_W4Drive);
		n.getParam("CanOpenIDs/TxPDO2_W4Drive", m_CanOpenIDParam.TxPDO2_W4Drive);
		n.getParam("CanOpenIDs/RxPDO2_W4Drive", m_CanOpenIDParam.RxPDO2_W4Drive);
		n.getParam("CanOpenIDs/TxSDO_W4Drive", m_CanOpenIDParam.TxSDO_W4Drive);
		n.getParam("CanOpenIDs/RxSDO_W4Drive", m_CanOpenIDParam.RxSDO_W4Drive);
	}
	// SteerMotor
	if(m_iNumDrives >= 4)
	{
		n.getParam("CanOpenIDs/TxPDO1_W4Steer", m_CanOpenIDParam.TxPDO1_W4Steer);
		n.getParam("CanOpenIDs/TxPDO2_W4Steer", m_CanOpenIDParam.TxPDO2_W4Steer);
		n.getParam("CanOpenIDs/RxPDO2_W4Steer", m_CanOpenIDParam.RxPDO2_W4Steer);
		n.getParam("CanOpenIDs/TxSDO_W4Steer", m_CanOpenIDParam.TxSDO_W4Steer);
		n.getParam("CanOpenIDs/RxSDO_W4Steer", m_CanOpenIDParam.RxSDO_W4Steer);
	}

  // ------ WHEEL 1 ------ //
	// --- Motor Wheel 1 Drive
	if(m_iNumDrives >= 1)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel1DriveMotor", &m_Param.iHasWheel1DriveMotor, true);
		n.getParam("Config/Wheel1DriveMotor", m_Param.iHasWheel1DriveMotor);
		if (m_Param.iHasWheel1DriveMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel1DriveMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel1DriveMotor available = type version 2");
			m_vpMotor[0] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[0])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W1Drive, m_CanOpenIDParam.TxPDO2_W1Drive, m_CanOpenIDParam.RxPDO2_W1Drive,
				m_CanOpenIDParam.TxSDO_W1Drive, m_CanOpenIDParam.RxSDO_W1Drive);
			m_vpMotor[0]->setCanItf(m_pCanCtrl);
      m_vpMotor[0]->setCanItff(m_sCanCtrl);

		}


    // --- Motor Wheel 1 Steer
	if(m_iNumDrives >= 1)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel1SteerMotor", &m_Param.iHasWheel1SteerMotor, true);
		n.getParam("Config/Wheel1DriveMotor", m_Param.iHasWheel1SteerMotor);
		if (m_Param.iHasWheel1SteerMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel1SteerMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel1SteerMotor available = type version 2");
			m_vpMotor[1] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[1])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W1Steer, m_CanOpenIDParam.TxPDO2_W1Steer, m_CanOpenIDParam.RxPDO2_W1Steer,
				m_CanOpenIDParam.TxSDO_W1Steer, m_CanOpenIDParam.RxSDO_W1Steer);
			m_vpMotor[1]->setCanItf(m_pCanCtrl);
      m_vpMotor[1]->setCanItff(m_sCanCtrl);


		}
	}

	// ------ WHEEL 2 ------ //
	// --- Motor Wheel 2 Drive
	if(m_iNumDrives >= 2)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel2DriveMotor", &m_Param.iHasWheel2DriveMotor, true);
		n.getParam("Config/Wheel2DriveMotor", m_Param.iHasWheel2DriveMotor);
		if (m_Param.iHasWheel2DriveMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel2DriveMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel2DriveMotor available = type version 2");
			m_vpMotor[2] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[2])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W2Drive, m_CanOpenIDParam.TxPDO2_W2Drive, m_CanOpenIDParam.RxPDO2_W2Drive,
				m_CanOpenIDParam.TxSDO_W2Drive, m_CanOpenIDParam.RxSDO_W2Drive);
			m_vpMotor[2]->setCanItf(m_pCanCtrl);
      m_vpMotor[2]->setCanItff(m_sCanCtrl);

		}
	}

	// --- Motor Wheel 2 Steer
	if(m_iNumDrives >= 2)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel2SteerMotor", &m_Param.iHasWheel2SteerMotor, true);
		n.getParam("Config/Wheel2SteerMotor", m_Param.iHasWheel2SteerMotor);
		if (m_Param.iHasWheel2SteerMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel2SteerMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel2SteerMotor available = type version 2");
			m_vpMotor[3] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[3])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W2Steer, m_CanOpenIDParam.TxPDO2_W2Steer, m_CanOpenIDParam.RxPDO2_W2Steer,
				m_CanOpenIDParam.TxSDO_W2Steer, m_CanOpenIDParam.RxSDO_W2Steer);
			m_vpMotor[3]->setCanItf(m_pCanCtrl);
      m_vpMotor[3]->setCanItff(m_sCanCtrl);


		}
	}

	// ------ WHEEL 3 ------ //
	// --- Motor Wheel 3 Drive
	if(m_iNumDrives >= 3)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel3DriveMotor", &m_Param.iHasWheel3DriveMotor, true);
		n.getParam("Config/Wheel3DriveMotor", m_Param.iHasWheel3DriveMotor);
		if (m_Param.iHasWheel3DriveMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel3DriveMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel3DriveMotor available = type version 2");
			m_vpMotor[4] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[4])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W3Drive, m_CanOpenIDParam.TxPDO2_W3Drive, m_CanOpenIDParam.RxPDO2_W3Drive,
				m_CanOpenIDParam.TxSDO_W3Drive, m_CanOpenIDParam.RxSDO_W3Drive);
			m_vpMotor[4]->setCanItf(m_pCanCtrl);
      m_vpMotor[4]->setCanItff(m_sCanCtrl);

		}
	}

	// --- Motor Wheel 3 Steer
	if(m_iNumDrives >= 3)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel3SteerMotor", &m_Param.iHasWheel3SteerMotor, true);
		n.getParam("Config/Wheel3SteerMotor", m_Param.iHasWheel3SteerMotor);
		if (m_Param.iHasWheel3SteerMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel3SteerMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel3SteerMotor available = type version 2");
			m_vpMotor[5] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[5])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W3Steer, m_CanOpenIDParam.TxPDO2_W3Steer, m_CanOpenIDParam.RxPDO2_W3Steer,
				m_CanOpenIDParam.TxSDO_W3Steer, m_CanOpenIDParam.RxSDO_W3Steer);
			m_vpMotor[5]->setCanItf(m_pCanCtrl);
      m_vpMotor[5]->setCanItff(m_sCanCtrl);


		}
	}

	// ------ WHEEL 4 ------ //
	// --- Motor Wheel 4 Drive
	if(m_iNumDrives == 4)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel4DriveMotor", &m_Param.iHasWheel4DriveMotor, true);
		n.getParam("Config/Wheel4DriveMotor", m_Param.iHasWheel4DriveMotor);
		if (m_Param.iHasWheel4DriveMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel4DriveMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel4DriveMotor available = type version 2");
			m_vpMotor[6] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[6])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W4Drive, m_CanOpenIDParam.TxPDO2_W4Drive, m_CanOpenIDParam.RxPDO2_W4Drive,
				m_CanOpenIDParam.TxSDO_W4Drive, m_CanOpenIDParam.RxSDO_W4Drive);
			m_vpMotor[6]->setCanItf(m_pCanCtrl);
      m_vpMotor[6]->setCanItff(m_sCanCtrl);

		}
	}

	// --- Motor Wheel 4 Steer
	if(m_iNumDrives == 4)
	{
		//m_IniFile.GetKeyInt("Config", "Wheel4SteerMotor", &m_Param.iHasWheel4SteerMotor, true);
		n.getParam("Config/Wheel4SteerMotor", m_Param.iHasWheel4SteerMotor);
		if (m_Param.iHasWheel4SteerMotor == 0)
		{
			// No motor
			ROS_INFO("node Wheel4SteerMotor available = 0");
		}
		else
		{
			// Motor Harmonica
			ROS_INFO("Wheel4SteerMotor available = type version 2");
			m_vpMotor[7] = new CanDriveHarmonica();
			((CanDriveHarmonica*) m_vpMotor[7])->setCanOpenParam(
				m_CanOpenIDParam.TxPDO1_W4Steer, m_CanOpenIDParam.TxPDO2_W4Steer, m_CanOpenIDParam.RxPDO2_W4Steer,
				m_CanOpenIDParam.TxSDO_W4Steer, m_CanOpenIDParam.RxSDO_W4Steer);
			m_vpMotor[7]->setCanItf(m_pCanCtrl);
      m_vpMotor[7]->setCanItff(m_sCanCtrl);


		}
	}

	}



}

  void cobcanctrl::sendNetStartCanOpen()
  {
    CanMsg msg;

    msg.m_iID  = 0;
    msg.m_iLen = 2;
    msg.set(1,0,0,0,0,0,0,0);
    m_pCanCtrl->transmitMsg(msg);

    usleep(100000);
  }








void cobcanctrl::intializing()
{
  readingparams();

  // Start can open network
	std::cout << "StartCanOpen" << std::endl;
	sendNetStartCanOpen();
  std::cout << "m5" << std::endl;

  for(int i=0; i<m_iNumMotors; i++){
    std::cout << "m1" << std::endl;
    m_vpMotor[i]->start();


  }


}










int main(int argc, char** argv)
{
	// initialize ROS, spezify name of node
	ros::init(argc, argv, "cobcanctrl");
  ROS_INFO("raddfd");

	cobcanctrl ctrl;

	// specify looprate of control-cycle
 	ros::Rate loop_rate(100); // Hz

	while (ctrl.n.ok())
	{
    ROS_INFO("rad");

		ctrl.intializing();

		loop_rate.sleep();
		ros::spinOnce();
	}

	return 0;
}
