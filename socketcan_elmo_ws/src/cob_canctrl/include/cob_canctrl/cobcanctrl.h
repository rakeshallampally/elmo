
#ifndef COBCANCTRL_INCLUDEDEF_H
#define COBCANCTRL_INCLUDEDEF_H

//-----------------------------------------------

// general includes

// Headers provided by other cob-packages
#include <cob_canopen_motor/CanDriveItf.h>
#include <cob_canopen_motor/CanDriveHarmonica.h>
#include <cob_generic_can/CanItf.h>

// Headers provided by cob-packages which should be avoided/removed


// remove (not supported)
//#include "stdafx.h"


//-----------------------------------------------

/**
 * Represents all CAN components on an arbitrary canbus.
 */
class cobcanctrl // : public CanCtrlPltfItf
{
public:

	//--------------------------------- Basic procedures

	/**
	 * Default constructor.
	 */
	cobcanctrl();

	/**
	 * Default destructor.
	 */
	~cobcanctrl();




	//

};


//-----------------------------------------------
#endif
