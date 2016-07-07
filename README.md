comm_tcp: Package in ROS for TCP/IP communication
=================================================

A ROS Catkin package with client and server nodes to communicate with other frameworks on different operating systems using TCP/IP.

Before running the package, make sure the ROS master is up and running:
```
$ roscore
```

Once the master is up, run the following commands:

**For Server Node:**
(Replace 'port_number' by the specific port)
```
$ rosrun comm_tcp server_node <port_number>
```
To communicate with Piaget, simply run the script [l-runServer.sh](scripts/l-runServer.sh) present in the scripts directory.
```
$ ./scripts/l-runServer.sh
```

**For Client Node:**
(Replace 'server_address' and 'port_number' by the correct values)
```
$ rosrun comm_tcp client_node <server_address> <port_number>
```
To communicate with Piaget, simply run the script [l-runClient.sh](scripts/l-runClient.sh) present in the scripts directory.
```
$ ./scripts/l-runClient.sh <server_address>
```

TODO:
=====
- Refactor the sockets code (in C) to a more object oriented C++ version.
- Refactor code according to C++ style guide convention.
- Follow ROS package guidelines and hopefully publish package.
