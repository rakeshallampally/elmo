#include <ros/ros.h>
#include <neo_kinematics_omnidrive/NeoKinematicsOmniDrive.h>


/*
 *loading all the neccesary parameters from yaml file
 */

int loadingParams(const ros::NodeHandle &n)
{


  if (n.hasParam("Time/Sleeptime"))
  {
    n.getParam("Time/Sleeptime", iSleepTime);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-Modulo parameter from parameter server");
    return 1;
  }

  //-----------------------------steer1---------------------------------------------------------
  // loading steer1 params
  if (n.hasParam("CanOpenIDs/TxPDO1_W1Steer"))
  {
    n.getParam("CanOpenIDs/TxPDO1_W1Steer", m_MotorSteer1.iTxPDO1);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxPDO1_W1Steer parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/TxPDO2_W1Steer"))
  {
    n.getParam("CanOpenIDs/TxPDO2_W1Steer", m_MotorSteer1.iTxPDO2);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxPDO2_W1Steer parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/RxPDO2_W1Steer"))
  {
    n.getParam("CanOpenIDs/RxPDO2_W1Steer", m_MotorSteer1.iRxPDO2);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-RxPDO2_W1Steer parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/TxSDO_W1Steer"))
  {
    n.getParam("CanOpenIDs/TxSDO_W1Steer", m_MotorSteer1.iTxSDO);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxSDO_W1Steer parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/RxSDO_W1Steer"))
  {
    n.getParam("CanOpenIDs/RxSDO_W1Steer", m_MotorSteer1.iRxSDO);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-RxSDO_W1Steer parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/EncIncrPerRevMot"))
  {
    n.getParam("Steer1/EncIncrPerRevMot", m_MotorSteer1.iEncIncrPerRevMot);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-EncIncrPerRevMot parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/VelMeasFrqHz"))
  {
    n.getParam("Steer1/VelMeasFrqHz", m_MotorSteer1.dVelMeasFrqHz);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-VelMeasFrqHz parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/BeltRatio"))
  {
    n.getParam("Steer1/BeltRatio", m_MotorSteer1.dBeltRatio);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-BeltRatio parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/GearRatio"))
  {
    n.getParam("Steer1/GearRatio", m_MotorSteer1.dGearRatio);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-GearRatio parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/Sign"))
  {
    n.getParam("Steer1/Sign", m_MotorSteer1.iSign);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-Sign parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/VelMaxEncIncrS"))
  {
    n.getParam("Steer1/VelMaxEncIncrS", m_MotorSteer1.dVelMaxEncIncrS);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-VelMaxEncIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/AccIncrS"))
  {
    n.getParam("Steer1/AccIncrS", m_MotorSteer1.dAccIncrS2);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-AccIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/DecIncrS"))
  {
    n.getParam("Steer1/DecIncrS", m_MotorSteer1.dDecIncrS2);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-DecIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/EncOffsetIncr"))
  {
    n.getParam("Steer1/EncOffsetIncr", m_MotorSteer1.iEncOffsetIncr);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-EncOffsetIncr parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/IsSteering"))
  {
    n.getParam("Steer1/IsSteering", m_MotorSteer1.bIsSteer);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-IsSteering parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/CurrentToTorque"))
  {
    n.getParam("Steer1/CurrentToTorque", m_MotorSteer1.dCurrentToTorque);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-CurrentToTorque parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/CurrMax"))
  {
    n.getParam("Steer1/CurrMax", m_MotorSteer1.dCurrMax);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-CurrMax parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/CurrMax"))
  {
    n.getParam("Steer1/CurrMax", m_MotorSteer1.dCurrMax);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-CurrMax parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/HomingDigIn"))
  {
    n.getParam("Steer1/HomingDigIn", m_MotorSteer1.iHomingDigIn);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-HomingDigIn parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/HomingTimeout"))
  {
    n.getParam("Steer1/HomingTimeout", m_MotorSteer1.iHomingTimeout);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-HomingTimeout parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Steer1/Modulo"))
  {
    n.getParam("Steer1/Modulo", m_MotorSteer1.iModulo);
  }
  else   
  {
    ROS_ERROR("FAILED to load Steer1-Modulo parameter from parameter server");
    return 1;
  }






//---------------------drive1------------------------------------------------------------------------
  //loading drive params

  if (n.hasParam("CanOpenIDs/TxPDO1_W1Drive"))
  {
    n.getParam("CanOpenIDs/TxPDO1_W1Drive", m_MotorDrive1.iTxPDO1);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxPDO1_W1Drive parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/TxPDO2_W1Drive"))
  {
    n.getParam("CanOpenIDs/TxPDO2_W1Drive", m_MotorDrive1.iTxPDO2);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxPDO2_W1Drive parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/RxPDO2_W1Drive"))
  {
    n.getParam("CanOpenIDs/RxPDO2_W1Drive", m_MotorDrive1.iRxPDO2);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-RxPDO2_W1Drive parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/TxSDO_W1Drive"))
  {
    n.getParam("CanOpenIDs/TxSDO_W1Drive", m_MotorDrive1.iTxSDO);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-TxSDO_W1Drive parameter from parameter server");
    return 1;
  }


  if (n.hasParam("CanOpenIDs/RxSDO_W1Drive"))
  {
    n.getParam("CanOpenIDs/RxSDO_W1Drive", m_MotorDrive1.iRxSDO);
  }
  else   
  {
    ROS_ERROR("FAILED to load CanOpenID-RxSDO_W1Drive parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/EncIncrPerRevMot"))
  {
    n.getParam("Drive1/EncIncrPerRevMot", m_MotorDrive1.iEncIncrPerRevMot);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-EncIncrPerRevMot parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/VelMeasFrqHz"))
  {
    n.getParam("Drive1/VelMeasFrqHz", m_MotorDrive1.dVelMeasFrqHz);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-VelMeasFrqHz parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/BeltRatio"))
  {
    n.getParam("Drive1/BeltRatio", m_MotorDrive1.dBeltRatio);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-BeltRatio parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/GearRatio"))
  {
    n.getParam("Drive1/GearRatio", m_MotorDrive1.dGearRatio);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-GearRatio parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/Sign"))
  {
    n.getParam("Drive1/Sign", m_MotorDrive1.iSign);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-Sign parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/VelMaxEncIncrS"))
  {
    n.getParam("Drive1/VelMaxEncIncrS", m_MotorDrive1.dVelMaxEncIncrS);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-VelMaxEncIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/AccIncrS"))
  {
    n.getParam("Drive1/AccIncrS", m_MotorDrive1.dAccIncrS2);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-AccIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/DecIncrS"))
  {
    n.getParam("Drive1/DecIncrS", m_MotorDrive1.dDecIncrS2);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-DecIncrS parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/EncOffsetIncr"))
  {
    n.getParam("Drive1/EncOffsetIncr", m_MotorDrive1.iEncOffsetIncr);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-EncOffsetIncr parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/IsSteering"))
  {
    n.getParam("Drive1/IsSteering", m_MotorDrive1.bIsSteer);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-IsSteering parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/CurrentToTorque"))
  {
    n.getParam("Drive1/CurrentToTorque", m_MotorDrive1.dCurrentToTorque);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-CurrentToTorque parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/CurrMax"))
  {
    n.getParam("Drive1/CurrMax", m_MotorDrive1.dCurrMax);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-CurrMax parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/HomingDigIn"))
  {
    n.getParam("Drive1/HomingDigIn", m_MotorDrive1.iHomingDigIn);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-HomingDigIn parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/HomingTimeout"))
  {
    n.getParam("Drive1/HomingTimeout", m_MotorDrive1.iHomingTimeout);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-HomingTimeout parameter from parameter server");
    return 1;
  }


  if (n.hasParam("Drive1/Modulo"))
  {
    n.getParam("Drive1/Modulo", m_MotorDrive1.iModulo);
  }
  else   
  {
    ROS_ERROR("FAILED to load Drive1-Modulo parameter from parameter server");
    return 1;
  }

   


//------------------------------------------------------------------------------------------------------------
 return 0;
}



int driveErrors(int iErrorNum)
{
  if((iErrorNum==m_DriveError.iOverHeating) || (iErrorNum==m_DriveError.iOverVoltage) || (iErrorNum==m_DriveError.iUnderVoltage) || (iErrorNum==m_DriveError.iMotorOff) || 
     (iErrorNum==m_DriveError.iCurrentLimintOn) || (iErrorNum==m_DriveError.iFeedbackLoss) || (iErrorNum==m_DriveError.iPeakCurrentExced) || (iErrorNum==m_DriveError.iSpeedTrack) ||
     (iErrorNum==m_DriveError.iPositionTrack) || (iErrorNum==m_DriveError.iSpeedLimit) || (iErrorNum==m_DriveError.iMotorStuck) )
  {
    return 1;
  }

  else if(iErrorNum==m_DriveError.iShortCircuit)
  {
    return -1;
  }

  return 0;
}


void displayErrors(int iErrorNum)
{
  if(iErrorNum==m_DriveError.iInitPosNotSet)
  {
    ROS_ERROR("Intitial positon is not set");
  }

  else if(iErrorNum==m_DriveError.iStatusReqFail)
  {
    ROS_ERROR("No answer on status request");
  }


  else if(iErrorNum==m_DriveError.iOverHeating)
  {
    ROS_ERROR("Over heating");
    ROS_INFO("The environment is too hot, or lacks heat removal or there may be a large thermal resistance between the drive and its mounting.");
  }

  else if(iErrorNum==m_DriveError.iShortCircuit)
  {
    ROS_ERROR("Drive error short cirucit");
    ROS_INFO("The motor or its wiring may be defective.");
  }

  else if(iErrorNum==m_DriveError.iOverVoltage)
  {
    ROS_ERROR("Drive error over voltage");
    ROS_INFO("The power supply voltage is too large, or the servo drive did not succeed in absorbing the kinetic energy while braking a load. A shunt resistor may be needed.");
  }

  else if(iErrorNum==m_DriveError.iUnderVoltage)
  {
    ROS_ERROR("Drive error under voltage");
    ROS_INFO("The power supply is shut off or it has too high an impedance.");
  }

  else if(iErrorNum==m_DriveError.iMotorOff)
  {
    ROS_ERROR("Motor is still Off");
  }

  else if(iErrorNum==m_DriveError.iCurrentLimintOn)
  {
    ROS_ERROR("Motor current limit on");
  }

  else if(iErrorNum==m_DriveError.iFeedbackLoss)
  {
    ROS_ERROR("feedback loss");
    ROS_INFO("No match between encoder and Hall location.Available in encoder + Hall feedback systems..");
  }

  else if(iErrorNum==m_DriveError.iPeakCurrentExced)
  {
    ROS_ERROR("Peak current excced");
    ROS_INFO("Possible reasons are drive malfunction or bad tuning of the current controller.");
  }

  else if(iErrorNum==m_DriveError.iSpeedTrack)
  {
    ROS_ERROR("Speed track error");
    ROS_INFO("Bad tuning of the speed controller (or)  Too tight a speed error tolerance (or) Inability of motor to accelerate to the required speed due to too low a line voltage or not a powerful enough motor");
  }

  else if(iErrorNum==m_DriveError.iPositionTrack)
  {
    ROS_ERROR("position track error");
    ROS_INFO("Bad tuning of the position or speed controller (or) Too tight a position error tolerance (or) Abnormal motor load, or reaching a mechanical limit");
  }

  else if(iErrorNum==m_DriveError.iSpeedLimit)
  {
    ROS_ERROR("speed limit exceeded");
    ROS_INFO("speed has exceedded the limits");
  }
 
  else if(iErrorNum==m_DriveError.iMotorStuck)
  {
    ROS_ERROR("motor stuck");
    ROS_INFO("A stuck motor is a motor that does not respond to the applied current command, due to failure of the motor, the drive system or the motion sensor.");
  }

}



bool srvCallback_Homing(neo_kinematics_omnidrive::Homing::Request  &req, neo_kinematics_omnidrive::Homing::Response &res )
{
  bService_called=true;                         //bService_called stores the boolean used this to make stop function execuate only once
  
  res.success.data=true;
  
  return true;
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "NeoKinOmnidrive");                    //initialize ros node  
  ros::NodeHandle n;                                           //ros node handle
  std::vector <int> viRet;                                     //vector that stores the return value of recMessages() function
  int iTimeElapsed,iTimeSleep;                                 //variable to store elapsed time
  std::chrono::steady_clock::time_point aStart,aStartTime;     //aStart stores the start time for homing
  int iNumOfMotors=2;                                          //total no of motors
  bool bDriveError;                                            //boolean variable that tells presence of drive error
  //creating a vectors to store positoin and velocity of steer and drive motors of DM1
  std::vector<double> vdPosGearRad,vdVelGearRadS;
  vdPosGearRad.resize(2,0);
  vdVelGearRadS.resize(2,0);
  

  //loading all the required params from yaml file
  if(!(loadingParams(n) == 0))
  {
    ROS_ERROR("Error occured while loading the params");
    return -1;
  }
 
   m_iDriveState=ST_DRIVE_NOT_INIT;

   //declaring variable to store ther return value of init funciton
   int iErrorVal;



   // starting the canopen network using network mangaement protocol
   DM1.sendNetStartCanOpen();


   //function which initializes the drive module and turns on motor
   iErrorVal= DM1.init(
                       m_MotorSteer1.iTxPDO1,m_MotorSteer1.iTxPDO2,m_MotorSteer1.iRxPDO2,m_MotorSteer1.iTxSDO,m_MotorSteer1.iRxSDO,m_MotorSteer1.iEncIncrPerRevMot,
                       m_MotorSteer1.dVelMeasFrqHz, m_MotorSteer1.dBeltRatio, m_MotorSteer1.dGearRatio,  m_MotorSteer1.iSign,  m_MotorSteer1.dVelMaxEncIncrS,
                       m_MotorSteer1.dAccIncrS2,  m_MotorSteer1.dDecIncrS2 ,m_MotorSteer1.iEncOffsetIncr, m_MotorSteer1.bIsSteer, m_MotorSteer1.dCurrentToTorque,
                       m_MotorSteer1.dCurrMax, m_MotorSteer1.iHomingDigIn,m_MotorSteer1.iHomingTimeout,m_MotorSteer1.iModulo,
                       m_MotorDrive1.iTxPDO1,m_MotorDrive1.iTxPDO2,m_MotorDrive1.iRxPDO2,m_MotorDrive1.iTxSDO,m_MotorDrive1.iRxSDO, m_MotorDrive1.iEncIncrPerRevMot,
                       m_MotorDrive1.dVelMeasFrqHz, m_MotorDrive1.dBeltRatio, m_MotorDrive1.dGearRatio,  m_MotorDrive1.iSign, m_MotorDrive1.dVelMaxEncIncrS,
                       m_MotorDrive1.dAccIncrS2 ,m_MotorDrive1.dDecIncrS2, m_MotorDrive1.iEncOffsetIncr, m_MotorDrive1.bIsSteer, m_MotorDrive1.dCurrentToTorque,
                       m_MotorDrive1.dCurrMax,m_MotorDrive1.iHomingDigIn, m_MotorDrive1.iHomingTimeout,m_MotorDrive1.iModulo
                      );

   //it displays if there is any error
   displayErrors(iErrorVal);
   if(iErrorVal==0)
   {
     m_iDriveState=ST_DRIVE_INIT;
   }

   //ros serviceserver for homing
   ros::ServiceServer srvServer_Homing = n.advertiseService("start_homing", srvCallback_Homing);

   //loop rate 100HZ
   ros::Rate loop_rate(100);
   while (ros::ok())
   {  
      //receiving the messages and  stores it in vector
      viRet= DM1.recMessages(); 
      for (int i = 0; i < viRet.size(); i++) 
      {
        //checking if any error present in the received vector by passing vector to the driveErrors function
        if((driveErrors(viRet[i])==1))
        {
          //displayErrors function displays the error obtained
          displayErrors(viRet[i]);
          //storing our current state of drive in variable m_iStoreState
          m_iStoreState=m_iDriveState;
          //in case of errors present changing the state of drive to ST_DRIVE_ERROR
          ROS_INFO("Rectify the above error");
          //chaning it to the state ST_DRIVE_ERROR because of error presence
          m_iDriveState=ST_DRIVE_ERROR;
        }
        
        //checking if any error obtained in vector is critical
        if((driveErrors(viRet[i])==-1))
        {
          displayErrors(viRet[i]);
          //in case of critical errors it exits the program
          return -1;
        }
      
      }
      //if the dirve state is  ST_DRIVE_ERROR
      if(m_iDriveState==ST_DRIVE_ERROR)
      {
        bDriveError=false;
        for (int i = 0; i < viRet.size(); i++) 
        {
          //checking if any errors present in received vector by passing it through driveErrors function
          if((driveErrors(viRet[i])==1))
          {
            //in case if any error present changing the boolean value of bDriveError as true
            bDriveError=true;
          }

        }

        if(bDriveError!=true)
        {
          //if no error present then going back to our previous state by retriving it from m_iStoreState variable
          m_iDriveState=m_iStoreState;
        }
      }

      //state Drive initialized
      else if(m_iDriveState==ST_DRIVE_INIT)
      {
        ROS_INFO("Drive initialized succesfully!");
        ROS_INFO("Use ROS Service start_homing to start homing the drives.");
        // state updated as not homed
        m_iDriveState=ST_NOT_HOMED;   
      }

      else if(m_iDriveState==ST_DRIVE_NOT_INIT)
      {
        //state drive not initialized
        ROS_ERROR("Failed to initialize drives, check hardware and CAN bus connection");
        m_iDriveState=ST_NOT_HOMED;
      }


      else if(bService_called==true)
      {
        DM1.stopMotion();                      //stops the robot motion to perform homing
        m_iDriveState=ST_SERVICE_CALLED;       //changing the state as ST_SERVICE_CALLED   
        bService_called=false;                 //making the bService_called variable as false
      }


      // state changed as service called
      else if(m_iDriveState==ST_SERVICE_CALLED)
      {
        // variables for drive and steer velocities
        double dDriveVel, dSteerVel;         
        //receives all the messages and gets the velocity of drive and steer motors
        int iNumOfMotors=2;      //total no of motors steer as well as drive

        for (int i=0;i<iNumOfMotors;i++)
        {
          //gets velocities of steer and drive motors
          DM1.getGearVel(i,&vdVelGearRadS[i]);
          printf("i=%d velocity=%1f\n",i,vdVelGearRadS[i]);
          if(i==0)
          {
            //getting drive velocity
            dDriveVel=vdVelGearRadS[i];
          }
          else if(i==1)
          {
            //getting steer velocity
            dSteerVel=vdVelGearRadS[i];
          }
        }

        if(dDriveVel <= 0.02 && dSteerVel <= 0.02)
        {
          //change state to start homing
          m_iDriveState=ST_START_HOMING;
                  
        }
      }

      else if(m_iDriveState==ST_START_HOMING)
      {
        //configuring the homing
        DM1.configureHoming();  
        ROS_INFO("Wait for Homing to be finished");
        //changing the drive state as arm homings
        m_iDriveState=ST_ARM_HOMING;
        aStartTime = std::chrono::steady_clock::now();
             
      }

      else if(m_iDriveState==ST_ARM_HOMING)
      {
        auto aEndTime = std::chrono::steady_clock::now();

        iTimeSleep = std::chrono::duration_cast<std::chrono::microseconds>( aEndTime - aStartTime ).count();
        //if time elapsed less than the give time for arm homing
        //waiting for 0.5 seconds before arming 
        if(iTimeSleep>iSleepTime)
        {        
          //arm the homing
          DM1.armHoming();   
          //changing the state as wait for homing
          m_iDriveState=ST_WAIT_FOR_HOMING;
          //starting the timer
          aStart = std::chrono::steady_clock::now();
        }
      }

      else if(m_iDriveState==ST_WAIT_FOR_HOMING)
      {
        //calling the homingDone function to completet homing procedure
        DM1.homingDone();   
        // ending the timer
        auto aEnd = std::chrono::steady_clock::now();
        //calculating the elapsed time
        iTimeElapsed = std::chrono::duration_cast<std::chrono::microseconds>( aEnd - aStart ).count();
        //if return value is not 17 and time elapsed is less than given timeout, change back the state to ST_WAIT_FOR_HOMING
        for (int i = 0; i<viRet.size(); i++) 
        {

          if((viRet[i])!=DISARM && iTimeElapsed<m_MotorDrive1.iHomingTimeout)
          {
            m_iDriveState=ST_WAIT_FOR_HOMING;
          }

          //if return value is 17 & elapsed time is with in given time out, change the state as ST_RUNNING
          else if((viRet[i])==DISARM && iTimeElapsed<m_MotorDrive1.iHomingTimeout)
          {
            m_iDriveState=ST_RUNNING;
          }

          //if return value is not 17 and elapsed time is greater than timeout ,then change the state to ST_NOT_HOMED
          else if((viRet[i])!=DISARM && iTimeElapsed>m_MotorDrive1.iHomingTimeout)
          {
             m_iDriveState=ST_HOMING_FAILED;            
          }    
        }    
      }
      
      else if(m_iDriveState==ST_HOMING_FAILED)
      {
        ROS_ERROR("Homing failed, restart the Homing");
        m_iDriveState=ST_NOT_HOMED;
      }
      //changing the drive state as ST_RUNNING
      else if(m_iDriveState==ST_RUNNING)
      {
       
        //sending the velocity to steer and drive motors of DM1
        DM1.setVelInRadS(0.3);

        //receives all the messages and gets the positoin and velocity of drive and steer motors
        for (int i=0;i<iNumOfMotors;i++)
        {
          DM1.getGearPosAndVel(i,&vdPosGearRad[i], &vdVelGearRadS[i]);
          printf("i=%d positoin=%1f velocity=%1f\n",i, vdPosGearRad[i], vdVelGearRadS[i]);
        }

      }

      loop_rate.sleep();   
      ros::spinOnce();

    }

  return 0;

}


