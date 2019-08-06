
#ifndef CANSOCKETDRIVER_INCLUDEDEF_H
#define CANSOCKETDRIVER_INCLUDEDEF_H
//-----------------------------------------------
#include <cob_generic_can/CanItf.h>

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
	void initsocket();
	void destroy() {};
	bool transmitMsg(CanMsg CMsg);
	bool receiveMsg(CanMsg* pCMsg);

	

private:
	// --------------- Types

	bool m_bInitialized;
	bool m_bSimuEnabled;




	bool initCAN();

	void outputDetailedStatus();
};
//-----------------------------------------------
#endif
