
#ifndef cansocketreceiver_INCLUDEDEF_H
#define cansocketreceiver_INCLUDEDEF_H
//-----------------------------------------------
#include <cob_generic_can/CanItff.h>
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

class cansocketreceiver : public CanItff
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
	cansocketreceiver();
	~cansocketreceiver();
	int initsocket();


	void receiveMsg(CanMsg* pCMsg);




};
//-----------------------------------------------
#endif
