#!/usr/bin/env python3
import rospy,tf,time
from tf.transformations import euler_from_quaternion
from sensor_msgs.msg import JointState
import numpy as np
def H(a,b):
	m = np.dot(a,b)
	return m
def fk(t1,t2,t3,t4):
	#r0_1=[[np.cos(t1),-np.sin(t1),0],[np.sin(t1),np.cos(t1),0],[0,0,1]]
	#r1_2=[[np.cos(t2),-np.sin(t2),0],[0,0,-1],[np.sin(t2),np.cos(t2),0]]
	#r2_3=[[np.sin(t3),-np.cos(t3),0],[np.cos(t3),np.sin(t3),0],[0,0,1]]
	#r3_4=[[np.sin(t4),-np.cos(t4),0],[np.cos(t4),np.cos(t4),0],[0,0,1]]
	#d0_1=[0,0,0.114]
	#d1_2=[-0.035,0,0.17]
	#d2_3=[0,0.34,0]
	#d3_4=[0.24,0,0]
	#h0_1=np.concatenate((r0_1,d0_1),1)
	#h0_1=np.concatenate((h0_1,[0,0,0,1]),0)
	#h1_2=np.concatenate((r1_2,d1_2),1)
	#h1_2=np.concatenate((h1_2,[0,0,0,1]),0)
	#h2_3=np.concatenate((r2_3,d2_3),1)
	#h2_3=np.concatenate((h2_3,[0,0,0,1]),0)
	#h3_4=np.concatenate((r3_4,d3_4),1)
	#h3_4=np.concatenate((h3_4,[0,0,0,1]),0)
	h0_1=[[np.cos(t1),-np.sin(t1),0,0],[np.sin(t1),np.cos(t1),0,0],[0,0,1,0.114],[0,0,0,1]]
	h1_2=[[np.cos(t2),-np.sin(t2),0,-0.035],[0,0,-1,0],[np.sin(t2),np.cos(t2),0,0.17],[0,0,0,1]]
	h2_3=[[np.sin(t3),-np.cos(t3),0,0.044],[np.cos(t3),np.sin(t3),0,0],[0,0,1,0.33755],[0,0,0,1]]
	h3_4=[[1,0,0,0.031],[0,1,0,0],[0,0,1,0.238],[0,0,0,1]]
	h0_2 = H(h0_1,h1_2)
	h0_3 = H(h0_2,h2_3)
	h0_4 = H(h0_3,h3_4)
	x = h0_4[0][3]
	y = h0_4[1][3]
	z = h0_4[2][3]
	return [x,y,z]
	
def jointvalue(data):
	th1 = data.position[0]
	th2 = data.position[1] + 0.00031
	th3 = data.position[2] + 0.0002
	th4 = data.position[3]
	ab = fk(th1,th2,th3,th4)
	(trans,rot) = listener.lookupTransform("/base_link","/gripper_rev", rospy.Time(0))
	euler = euler_from_quaternion(rot)
	ans = [[ab[0]-trans[0]],[ab[1]-trans[1]],[ab[2]-trans[2]]]
	print (ab)

	 
	

rospy.init_node('fk', anonymous=True)
listener = tf.TransformListener() 
r = rospy.Rate(1)
while not rospy.is_shutdown():
	sub = rospy.Subscriber('joint_states', JointState, jointvalue)
	r.sleep()
