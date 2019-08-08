
#ifndef CANSOCKETDRIVER_INCLUDEDEF_H
#define CANSOCKETDRIVER_INCLUDEDEF_H
//-----------------------------------------------
#include <cob_generic_can/CanItf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>
//-----------------------------------------------

class cansocketdriver : public CanItf
{
public:


	ros::NodeHandle n;

	int s;
	int nbytes;
	struct sockaddr_can addr;
	struct can_frame frame;
	struct ifreq ifr;
	const char *ifname = "vcan0";
	// --------------- Interface
	cansocketdriver();
	~cansocketdriver();
	int initsocket();

	void transmitMsg(CanMsg CMsg);
	void receiveMsg(CanMsg* pCMsg);




};
//-----------------------------------------------
#endif
