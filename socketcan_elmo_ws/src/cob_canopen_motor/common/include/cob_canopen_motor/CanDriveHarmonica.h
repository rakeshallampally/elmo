

#ifndef CANDRIVEHARMONICA_INCLUDEDEF_H
#define CANDRIVEHARMONICA_INCLUDEDEF_H

//-----------------------------------------------
#include <cob_canopen_motor/CanDriveItf.h>


class CanDriveHarmonica : public CanDriveItf
{
public:



	/**
	 * Identifier of the CAN messages.
	 */
	struct ParamCanOpenType
	{
		int iTxPDO1;
		int iTxPDO2;
		int iRxPDO2;
		int iTxSDO;
		int iRxSDO;
	};

	// ------------------------- Interface
	/**
	 * Sets the CAN interface.
	 */
	void setCanItf(CanItf* pCanItf){ m_pCanCtrl = pCanItf; }
	void setCanItff(CanItff* sCanItf){ m_sCanCtrl = sCanItf; }





	/**
	 * Enables the motor.
	 * After calling the drive accepts velocity and position commands.
	 */
	void start();

	/**
	 * Disables the motor.
	 * After calling the drive won't accepts velocity and position commands.
	 */
	void stop();
	void shutdown();

	CanDriveHarmonica();


	void setCanOpenParam( int iTxPDO1, int iTxPDO2, int iRxPDO2, int iTxSDO, int iRxSDO);


	void IntprtSetInt(int iDataLen, char cCmdChar1, char cCmdChar2, int iIndex, int iData);




protected:
	// ------------------------- Parameters
	ParamCanOpenType m_ParamCanOpen;



	// ------------------------- Variables
	CanItf* m_pCanCtrl;
	CanItff* m_sCanCtrl;



};
//-----------------------------------------------
#endif
