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

#include "ros/ros.h"
#include <unistd.h>

	ros::Timer timer;
	int s;
	int nbytes;
	struct sockaddr_can addr;
	struct can_frame frame;
	struct ifreq ifr;
	const char *ifname = "vcan0";




// class receiver
// {
// public:
// 	ros::NodeHandle n;
// 	ros::Timer timer;
// 	int s;
// 	int nbytes;
// 	struct sockaddr_can addr;
// 	struct can_frame frame;
// 	struct ifreq ifr;
// 	const char *ifname = "vcan0";
//
//
//
// 	receiver()
// 	{
//
//    dow();
//
// 		}
//
		int dow()
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


	int rece()
	{
		ROS_INFO("r22s");
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
		ROS_INFO("r35s");



		nbytes = read(s, &frame, sizeof(struct can_frame));
		ROS_INFO("r37s");
		// ifr.ifr_ifindex = addr.can_ifindex;
		// ioctl(s, SIOCGIFNAME, &ifr);
		// ROS_INFO("Received a CAN frame from interface %s", ifr.ifr_name);
		ROS_INFO("can_id: %X data length: %d data: ", frame.can_id,frame.can_dlc);
		for (int i = 0; i < frame.can_dlc; i++)
					ROS_INFO("%02X ", frame.data[i]);

		return 0;



	}


	void sen()
	{
		ROS_INFO("r11");
		std::cout<<"r1";
		frame.can_id  = 0x123;
	frame.can_dlc = 2;
	frame.data[0] = 0x11;
	frame.data[1] = 0x22;
	std::cout<<std::hex<<frame.can_dlc;

	nbytes = write(s, &frame, sizeof(struct can_frame));

	}







int main(int argc, char **argv)
{
	ros::init(argc, argv, "can_message_receiver");
	ros::NodeHandle n;

	//constructor
	dow();
	sen();

	while(1)
	{
		ROS_INFO("r21");

		rece();
	}



  // Spin to avoid exiting
  ros::spinOnce();

  return 0;
}


//
// class receiver
// {
// public:
// 	ros::NodeHandle n;
// 	ros::Timer timer;
// 	int s;
// 	int nbytes;
// 	struct sockaddr_can addr;
// 	struct can_frame frame;
// 	struct ifreq ifr;
// 	const char *ifname = "vcan0";
//
//
//
// 	receiver()
// 	{
//
// 		timer =n.createTimer(ros::Duration(0.02), &receiver::callback, this);
// 	}
//
// 	void callback(const ros::TimerEvent& e)
// 	{
// 		nbytes = read(s, &frame, sizeof(struct can_frame));
// 		// ifr.ifr_ifindex = addr.can_ifindex;
// 		// ioctl(s, SIOCGIFNAME, &ifr);
// 		// ROS_INFO("Received a CAN frame from interface %s", ifr.ifr_name);
// 		ROS_INFO("can_id: %X data length: %d data: ", frame.can_id,frame.can_dlc);
// 		for (int i = 0; i < frame.can_dlc; i++)
// 					ROS_INFO("%02X ", frame.data[i]);
//
//
//
// 	}
// 	int dow()
// 	{
// 		if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
// 			perror(" There is an error while opening socket");
// 			return -1;
// 		}
//
// 		strcpy(ifr.ifr_name, ifname);
// 		ioctl(s, SIOCGIFINDEX, &ifr);
//
// 		addr.can_family  = AF_CAN;
// 		addr.can_ifindex = ifr.ifr_ifindex;
//
// 		// printf("%s at index %d\n", ifname, ifr.ifr_ifindex);
//
// 		if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
// 			perror("Error in socket bind");
// 			return -2;
// 		}
// 		return 0;
//
//
// 	}
//
//
// };
//
//
//
//
//
// int main(int argc, char **argv)
// {
// 	ros::init(argc, argv, "can_message_receiver");
// 	//constructor
// 	receiver rec;
// 	rec.dow();
//
//
//   // Spin to avoid exiting
//   ros::spin();
//
//   return 0;
// }
//
//
//
//













// void callback(const ros::TimerEvent& event)
// {
//
// 	nbytes = read(s, &frame, sizeof(struct can_frame));
// 	ifr.ifr_ifindex = addr.can_ifindex;
// 	ioctl(s, SIOCGIFNAME, &ifr);
// 	ROS_INFO("Received a CAN frame from interface %s", ifr.ifr_name);
// 	ROS_INFO("can_id: %X data length: %d data: ", frame.can_id,frame.can_dlc);
// 	for (int i = 0; i < frame.can_dlc; i++)
// 				ROS_INFO("%02X ", frame.data[i]);
// }
//
//
// int main(int argc, char **argv)
// {
//
//
//   ros::init(argc, argv, "can_message_receiver");
//   ros::NodeHandle n;
//
//
//
// 	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
// 		perror(" There is an error while opening socket");
// 		return -1;
// 	}
//
// 	strcpy(ifr.ifr_name, ifname);
// 	ioctl(s, SIOCGIFINDEX, &ifr);
//
// 	addr.can_family  = AF_CAN;
// 	addr.can_ifindex = ifr.ifr_ifindex;
//
// 	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);
//
// 	if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
// 		perror("Error in socket bind");
// 		return -2;
// 	}
// 	ros::Timer timer = n.createTimer(ros::Duration(0.1), callback);
//
//
//   // Spin to avoid exiting
//   ros::spin();
//
//   return 0;
// }
//













// int main(int argc, char **argv)
// {
// 	int s;
// 	int nbytes;
// 	struct sockaddr_can addr;
// 	struct can_frame frame;
// 	struct ifreq ifr;
//
//   ros::init(argc, argv, "can_message_receiver");
//   ros::NodeHandle n;
//
// 	const char *ifname = "vcan0";
//
// 	if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
// 		perror(" There is an error while opening socket");
// 		return -1;
// 	}
//
// 	strcpy(ifr.ifr_name, ifname);
// 	ioctl(s, SIOCGIFINDEX, &ifr);
//
// 	addr.can_family  = AF_CAN;
// 	addr.can_ifindex = ifr.ifr_ifindex;
//
// 	printf("%s at index %d\n", ifname, ifr.ifr_ifindex);
//
// 	if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
// 		perror("Error in socket bind");
// 		return -2;
// 	}
//
//
//
//
// 	nbytes = read(s, &frame, sizeof(struct can_frame));
// 	ifr.ifr_ifindex = addr.can_ifindex;
// 	ioctl(s, SIOCGIFNAME, &ifr);
// 	printf("Received a CAN frame from interface %s", ifr.ifr_name);
// 	printf("can_id: %X data length: %d data: ", frame.can_id,frame.can_dlc);
// 	for (int i = 0; i < frame.can_dlc; i++)
//         printf("%02X ", frame.data[i]);
//
//
//   // Spin to avoid exiting
//   ros::spinOnce();
//
//   return 0;
// }
