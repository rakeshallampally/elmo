
#ifndef COBCANCTRL_INCLUDEDEF_H
#define COBCANCTRL_INCLUDEDEF_H



#include <cob_canopen_motor/CanDriveItf.h>
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <cob_generic_can/CanItf.h>

// Headers provided by cob-packages which should be avoided/removed


class cobcanctrl // : public CanCtrlPltfItf
{
public:
	ros::NodeHandle n;

	//--------------------------------- Basic procedures

	/**
	 * Default constructor.
	 */
	cobcanctrl();

	/**
	 * Default destructor.
	 */
	~cobcanctrl();
	void intializing();

protected:

  void readingparams();
	void sendNetStartCanOpen();

	struct CanOpenIDType
	{
		// Wheel 1
		// can adresse motor 1
		int TxPDO1_W1Drive;
		int TxPDO2_W1Drive;
		int RxPDO2_W1Drive;
		int TxSDO_W1Drive;
		int RxSDO_W1Drive;
		// can adresse motor 2
		int TxPDO1_W1Steer;
		int TxPDO2_W1Steer;
		int RxPDO2_W1Steer;
		int TxSDO_W1Steer;
		int RxSDO_W1Steer;

		// Wheel 2
		// can adresse motor 7
		int TxPDO1_W2Drive;
		int TxPDO2_W2Drive;
		int RxPDO2_W2Drive;
		int TxSDO_W2Drive;
		int RxSDO_W2Drive;
		// can adresse motor 8
		int TxPDO1_W2Steer;
		int TxPDO2_W2Steer;
		int RxPDO2_W2Steer;
		int TxSDO_W2Steer;
		int RxSDO_W2Steer;

		// Wheel 3
		// can adresse motor 5
		int TxPDO1_W3Drive;
		int TxPDO2_W3Drive;
		int RxPDO2_W3Drive;
		int TxSDO_W3Drive;
		int RxSDO_W3Drive;
		// can adresse motor 6
		int TxPDO1_W3Steer;
		int TxPDO2_W3Steer;
		int RxPDO2_W3Steer;
		int TxSDO_W3Steer;
		int RxSDO_W3Steer;

		// Wheel 4
		// can adresse motor 3
		int TxPDO1_W4Drive;
		int TxPDO2_W4Drive;
		int RxPDO2_W4Drive;
		int TxSDO_W4Drive;
		int RxSDO_W4Drive;
		// can adresse motor 4
		int TxPDO1_W4Steer;
		int TxPDO2_W4Steer;
		int RxPDO2_W4Steer;
		int TxSDO_W4Steer;
		int RxSDO_W4Steer;
	};

	struct ParamType
	{
		// Platform config

		int iHasWheel1DriveMotor;
		int iHasWheel1SteerMotor;
		int iHasWheel2DriveMotor;
		int iHasWheel2SteerMotor;
		int iHasWheel3DriveMotor;
		int iHasWheel3SteerMotor;
		int iHasWheel4DriveMotor;
		int iHasWheel4SteerMotor;

		double dWheel1SteerDriveCoupling;
		double dWheel2SteerDriveCoupling;
		double dWheel3SteerDriveCoupling;
		double dWheel4SteerDriveCoupling;

		int iRadiusWheelMM;
		int iDistSteerAxisToDriveWheelMM;

		int iHasRelayBoard;
		int iHasIOBoard;
		int iHasUSBoard;
		int iHasGyroBoard;
		int iHasRadarBoard;

		double dCanTimeout;
	};

	//--------------------------------- Parameter
	ParamType m_Param;
//	CanNeoIDType m_CanNeoIDParam;
	CanOpenIDType m_CanOpenIDParam;
	// Can-Interface
	CanItf* m_pCanCtrl;

	int m_iNumMotors;
	int m_iNumDrives;
	std::vector<CanDriveItf*> m_vpMotor;



};


//-----------------------------------------------
#endif
