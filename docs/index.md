# Documentation for the package win_comm_chat

This website serves as a documentation for my project **"Development of a transport layer/bridge for communication between Piaget and ROS"** at [HEIG-VD](http://heig-vd.ch/).

The project aims at connecting Piaget, the existing multi-agent framework for driving robots at the university to ROS, a very famous and prevalent robot middleware, to promote cross usage of packages and libraries between both environments.

This directory contains the source code for a [ROS Package](http://wiki.ros.org/Packages), which has two nodes [server_node](#server_node) and [client_node](#client_node) allowing for bi-directional communication over TCP/IP to any other program using the same protocol over sockets.

## server_node

**IMPORTANT:** Make sure the ROS master is up and running before you start this node, else it won't start! (To start ROS master, run the following command: ```$ roscore```)

The server_node is a simple TCP/IP server written in C++ (more like C type) and integrated to this ROS package. To start, run the following command:

```sh
$ rosrun win_comm_chat server_node <port_number>
```

Replace the <port_number\> above by the port number that you want to start the server on. To communicate with Piaget, we'll use the port 1024, and so the command looks like this:

```sh
$ rosrun win_comm_chat server_node 1024
```

Once you run the above, the server should start listening to incoming connections on the specified port. Something like this:

```sh 
Hello there! This node is listening on port 1024 for incoming connections
```


## client_node

**IMPORTANT:** Make sure the ROS master is up and running before you start this node, else it won't start! (To start ROS master, run the following command: ```$ roscore```)

The client_node is a TCP/IP client written in C++ (more like C type) and integrated to this ROS package. To start, run the following command:

```sh
$ rosrun win_comm_chat client_node <server_address> <port_number>
```

Replace the <server_address\> by the IP address or hostname of the server and the <port_number\> by the port that it's listening on. To communicate with Piaget, we'll use the port 1024 (and assume the server is running on the computer c38pc06), and so the command looks like this:

```sh
$ rosrun win_comm_chat client_node c38pc06 1024
```

Once you run the above, the server should start listening to incoming connections on the specified port. Something like this:

```sh 
Hello there! This node is listening on port 1024 for incoming connections
```

## Project layout

    mkdocs.yml    # The configuration file.
    docs/
        index.md  # The documentation homepage.
        ...       # Other markdown pages, images and other files.


## References

* [C/C++ Sockets](http://www.linuxhowtos.org/C_C++/socket.htm)
* [How can I do a Networking between ROS (Linux) and a C++ Program running on Windows?](http://answers.ros.org/question/52107/how-can-i-do-a-networking-between-ros-linux-and-a-c-program-running-on-windows/)
* []()
* []()
* []()


