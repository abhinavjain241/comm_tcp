 /*************************************************************************
 * Author: Abhinav Jain
 * Contact: abhinavjain241@gmail.com, abhinav.jain@heig-vd.ch
 * Date: 28/06/2016
 *
 * This file contains source code to the client node of the ROS package
 * comm_tcp developed at LaRA (Laboratory of Robotics and Automation)
 * as part of my project during an internship from May 2016 - July 2016.
 *
 * (C) All rights reserved. LaRA, HEIG-VD, 2016 (http://lara.populus.ch/)
 ***************************************************************************/
#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "std_msgs/String.h"

#define MESSAGE_FREQ 1

void error(const char *msg) {
    perror(msg);
    exit(0);
}

class Listener {
private:
    char topic_message[256] = { 0 };
public:
    void callback(const std_msgs::String::ConstPtr& msg);
    char* getMessageValue();
};

void Listener::callback(const std_msgs::String::ConstPtr& msg) {
    memset(topic_message, 0, 256);
    strcpy(topic_message, msg->data.c_str());
    ROS_INFO("I heard:[%s]", msg->data.c_str());
}

char* Listener::getMessageValue() {
    return topic_message;
}

int main(int argc, char *argv[]) {
	ros::init(argc, argv, "client_node");
	ros::NodeHandle nh;
    ros::Rate loop_rate(MESSAGE_FREQ); // set the rate as defined in the macro MESSAGE_FREQ
	Listener listener;
        ros::Subscriber client_sub = nh.subscribe("/client_messages", 1, &Listener::callback, &listener);
    int sockfd, portno, n, choice = 1;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    bool echoMode = false;
    if (argc < 3) {
       fprintf(stderr,"Usage: $ rosrun comm_tcp client_node <hostname> <port> --arguments\nArguments:\n -e : Echo mode\n");
       exit(0);
    }
    if (argc > 3)
		if (strcmp(argv[3], "-e") == 0)
			echoMode = true;
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    std::cout << "How do you want the client to behave?:\n1. Be able to send messages manually\n2. Subscribe to /client_messages and send whatever's available there\nYour choice:";
    std::cin >> choice;
	while(ros::ok()) {
        bzero(buffer,256);
        if (choice == 1) {
            printf("Please enter the message: ");
            fgets(buffer,255,stdin);
        } else if (choice == 2) {
            strcpy(buffer, listener.getMessageValue());
            loop_rate.sleep();
        }
	    n = write(sockfd,buffer,strlen(buffer));
	    if (n < 0) 
	         error("ERROR writing to socket");
	    if (echoMode) {
			bzero(buffer, 256);
		    n = read(sockfd,buffer,255);
		    if (n < 0)
				error("ERROR reading reply");
		    printf("%s\n", buffer);
	    }
	    ros::spinOnce();
	}
	return 0;
}
