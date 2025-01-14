#!/usr/bin/env python3

import rospy,time
from devlib import setlimit
from sensor_msgs.msg import Joy,JointState
from std_msgs.msg import Header
from math import pi
j=JointState()
global a,b,c,d
[a,b,c,d] = [0,0,0,0]
factor = 0.003
past_time = 0

def data_transfer(msg,joint_pub):
	global a,b,c,d,factor,past_time
	j.header.stamp = rospy.Time.now()
	time_now = j.header.stamp.secs
	j.header.frame_id = "world"
	j.name = ["rev1","prism2","rev3","rev4"]	
	a+=(msg.buttons[0])*(msg.axes[5])*factor
	b+=(msg.buttons[1])*(msg.axes[5])*factor
	c+=(msg.buttons[2])*(msg.axes[5])*factor
	d+=(msg.buttons[3])*(msg.axes[5])*factor
	a = setlimit(a,pi,-pi)
	b = setlimit(b,0.8,0)
	c = setlimit(c,0,-pi)
	d = setlimit(d,pi,-pi)
	j.position=[a,b,c,d]
	if time_now - past_time ==1:
		temp_time = time_now%10000
		print (str(temp_time)+","+str(a)+","+str(b)+","+str(c)+","+str(d))		
	joint_pub.publish(j)
	past_time = time_now

while not rospy.is_shutdown():
	rospy.init_node('joint_state_publisher_gui',anonymous=True)
	joint_pub = rospy.Publisher('joint_states',JointState,queue_size=100)
	joy_sub = rospy.Subscriber('joy',Joy,data_transfer,joint_pub)
	time.sleep(1)

