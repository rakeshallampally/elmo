


#include "ros/ros.h"
//-----------------------------------------------
#include <cob_generic_can/cansocketdriver.h>
cansocketdriver::cansocketdriver()
{




	initsocket();
}

cansocketdriver::~cansocketdriver()
{





}
//-----------------------------------------------

//-----------------------------------------------
int cansocketdriver::initsocket()
{

	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror(" There is an error while opening socket");
		return -1;
	}

	strcpy(ifr.ifr_name, ifname);
	ioctl(s, SIOCGIFINDEX, &ifr);

	addr.can_family  = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	// printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

	if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Error in socket bind");
		return -2;
	}
	return 0;
}

//-------------------------------------------
void cansocketdriver::transmitMsg(CanMsg CMsg){

	frame.can_id=CMsg.m_iID;
	frame.can_dlc=CMsg.m_iLen;
	for(int i=0; i<8; i++)
		frame.data[i] = CMsg.getAt(i);

	nbytes = write(s, &frame, sizeof(struct can_frame));





	// frame.can_id  = 0x123;;
	// frame.can_dlc = iDataLen;
	// frame.data[0] = cCmdChar1;
	// frame.data[1] = cCmdChar2;
	// frame.data[2] = iIndex;
	// frame.data[3] = (iIndex >> 8) & 0x3F;
	// frame.data[4] =iData;
	// frame.data[5] =1>>8;
	// frame.data[6] =1>>16;
	// frame.data[7] =1>>24;
	// nbytes = write(s, &frame, sizeof(struct can_frame));

}


//-------------------------------------------
void cansocketdriver::receiveMsg(CanMsg* pCMsg)
{
	std::cout << "motor sssssis on "  << std::endl;
	std::cout << sizeof(struct can_frame)  << std::endl;

	nbytes = read(s, &frame, sizeof(struct can_frame));

	pCMsg->m_iID =frame.can_id;
	std::cout << "motor sssssis ddsfedon "  << std::endl;
	pCMsg->set(frame.data[0], frame.data[1], frame.data[2], frame.data[3],
			frame.data[4], frame.data[5], frame.data[6], frame.data[7]);



	// nbytes = read(s, &frame, sizeof(struct can_frame));
	// ifr.ifr_ifindex = addr.can_ifindex;
	// ioctl(s, SIOCGIFNAME, &ifr);
	// ROS_INFO("Received a CAN frame from interface %s", ifr.ifr_name);
	// ROS_INFO("can_id: %X data length: %d data: ", frame.can_id,frame.can_dlc);
	// for (int i = 0; i < frame.can_dlc; i++)
	// 			ROS_INFO("%02X ", frame.data[i]);
}
