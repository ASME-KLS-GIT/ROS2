#ROS 
# NODES : 
---
---
A node is a participant in the ROS 2 graph, which uses a [client library](https://docs.ros.org/en/jazzy/Concepts/Basic/About-Client-Libraries.html) to communicate with other nodes. Nodes can communicate with other nodes within the same process, in a different process, or on a different machine. Nodes are typically the unit of computation in a ROS graph; each node should do one logical thing.


Different functions are kept isolated from each other by using dedicated nodes for each of them .


Each node is capable of :(you'll understand this better as you keep using ROS)
	Publish messages onto a topic.
	
	Subscribe to a topic and react to messages.
	
	Offer a service (handle requests from other nodes).
	
	Call a service on another node.
	
	Run actions (long tasks with progress feedback and cancellation).
	
	Fire timers at any frequency.
	
	Read and set parameters at runtime.
	
	Log messages (debug, info, warn, error).
	
	Access the ROS2 clock (real time or simulated time).
	
	Discover other nodes, topics, and services on the network automatically.
	
	Run on a different machine entirely and still communicate.
	

---
## **IMPORTANT**
### What a node cannot do :
---
Directly access another node's internal variables — everything must go through topics, services, or actions.


Persist state after it shuts down — no built-in memory between runs.

Guarantee real-time execution by itself — ROS2 is not a real-time systemof the box.

(there's ROS2 with [**RTOS**](https://en.wikipedia.org/wiki/Real-time_operating_system) (Real Time Operating System) for that, but that's advanced territory).


Control hardware directly without a driver layer — a node talks to a hardware interface, it doesn't bypass the OS.

---

ROS2 maintains modularity by enforcing these rules upon nodes . One node cannot reach into the scope of another node and that is not a convention but an enforced law which ensures modularity.


If there's something being transferred between two nodes , then it **has** to be through a **topic** , **subscription**, or any communication channel provided by ROS2's 
infrastructure.

---
---
## TOPICS:

Topics are one of the three primary styles of interfaces provided by ROS 2. Topics should be used for continuous data streams, like sensor data, robot state, etc.


A topic is something that generally acts as a bridge between two nodes , it carries a message given by one node to another node , that is how two nodes are connected , a node which is constantly **publishing** data puts it into a topic , and a node which is going to receive the data has **subscribed** to the topic in which the data is being sent. 


This is called a publisher subscriber model in ROS2 and is one of the main characteristics of a ROS2 ecosystem.

---
## A topic has three main characteristics :

### **PRIMARILY FUNCTIONS ON PUBLISHER/SUBSCRIBER MODEL** :

A publish/subscribe system is one in which there are **producers of data (publishers)**and **consumers of data (subscribers).** The publishers and subscribers know how to contact each other through the concept of a “topic”, which is a common name so that the entities can find each other.

### **ANONYMOUS**

 ROS 2 is “anonymous”. This means that when a subscriber gets a piece of data, it doesn’t generally know or care which publisher originally sent it (though it can find out if it wants). The benefit to this architecture is that publishers and subscribers can be swapped out at will without affecting the rest of the system.

### **STRONGLY TYPED**

ROS2 is known as an ecosystem where any interface defined is "strongly typed"

This means we have to be clear of the semantics and assume that there's no automated system maintaining all the semantics.
eg. 
if the contents of a ROS message are :
```
uint32 field1
string field2


```
Then `field1` has to always be a 32-bit integer and `field2` has to always be a string. There is no automatic system that does this defining for you.


---
# ANALOGY : 

A basic(minimally functional) ROS2 ecosystem can be analogously thought of as a Dairy which delivers milk to its customers through various milkmen (or delivery boys for you modern folks).

A Topic is a milkman , a customer (receiving node) -subscribes to the dairy's(publisher node) service and the Dairy delivers at a fixed rate (frequency) through a milkman delivers , the milkman delivers and moves on.

The customer doesn't know or care which milkman delivers the milk to his doorstep(the customer can if they wish to). The customer's only concern is that the milk should get delivered at the agreed deliver timings and at the agreed number of packets per day(or whatever metric is used in your locality).

---
---
# SERVICES:

In ROS 2, a service refers to a remote procedure call. In other words, a node can make a remote procedure call to another node which will do a computation and return a result.

These services are meant to be quick and are hence not generally preferred for long running tasks.

Services in ROS2 can be put into two entities , namely : 
	Service Client 
	Service Server 

A service client is an entity that will request a remote service server to perform a computation on its behalf.

A service server is the entity that will accept a remote procedure request, and perform some computation on it.


