

#ifndef CANITF_INCLUDEDEF_H
#define CANITF_INCLUDEDEF_H
//-----------------------------------------------
#include <cob_generic_can/CanMsg.h>
//-----------------------------------------------

/**
 * General interface of the CAN bus.
 * \ingroup DriversCanModul
 */
class CanItf
{
public:


	/**
	 * The destructor does not necessarily have to be overwritten.
	 * But it makes sense to close any resources like handles.
	 */
	virtual ~CanItf() {
	}

	/**
	 * Initializes the CAN bus.
	 */


	/**
	 * Sends a CAN message.
	 * @param pCMsg CAN message
	 * @param bBlocking specifies whether send should be blocking or non-blocking
	 */
	virtual void transmitMsg(CanMsg CMsg) = 0;

	/**
	 * Reads a CAN message.
	 * @return true if a message is available
	 */
	virtual void receiveMsg(CanMsg* pCMsg) = 0;

	/**
	 * Reads a CAN message.
	 * The function blocks between the attempts.
	 * @param pCMsg CAN message
	 * @param iNrOfRetry number of retries
	 * @return true if a message is available
	 */

};
//-----------------------------------------------

#endif
