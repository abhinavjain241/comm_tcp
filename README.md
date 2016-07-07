comm_tcp: Package in ROS for communication over TCP/IP
=====================================================

A ROS Catkin package with client and server nodes to communicate with other frameworks on different operating systems using TCP/IP.

Before running the package, make sure the ROS master is up and running:
```
$ roscore
```

Once the master is up, run the following commands:

**For Server Node:**
(Replace 'port_number' by the specific port)
```
$ rosrun win_comm_chat server_node <port_number>
```

**For Client Node:**
(Replace 'server_address' and 'port_number' by the correct values)
```
$ rosrun win_comm_chat client_node <server_address> <port_number>
```

TODO:
=====
- Refactor the sockets code (in C) to a more object oriented C++ version.
- Refactor code according to C++ style guide convention.
- Follow ROS package guidelines and hopefully publish package.
