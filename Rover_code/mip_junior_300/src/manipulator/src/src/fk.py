#!/usr/bin/env python3
import rospy,tf,time
from tf.transformations import euler_from_quaternion
from sensor_msgs.msg import JointState
import numpy as np
def H(a=[],b=[]):
	m = np.dot(a,b)
	return m
def h(a,pt=[]):
	b = [[np.cos(pt[a][0]),-np.sin(pt[a][0])*np.cos(pt[a][1]),np.sin(pt[a][0])*np.sin(pt[a][1]),pt[a][2]*np.cos(pt[a][0])],[np.sin(pt[a][0]),np.cos(pt[a][0])*np.cos(pt[a][1]),-np.cos(pt[a][0])*np.sin(pt[a][1]),pt[a][2]*np.sin(pt[a][0])],[0,np.sin(pt[a][1]),np.cos(pt[a][1]),pt[a][3]],[0,0,0,1]]
	return b
def fk(th1,th2,th3):
	pt = [[th1,0,0,0.114],[0,-1.571,-0.035,0.174],[(1.57+th2),0,0.34,0.80105],[th3,0,0.24,0.000122]]
	h0_1 = h(0,pt)
	h1_2 = h(1,pt)
	h2_3 = h(2,pt)
	h3_4 = h(3,pt)
	h0_2 = H(h0_1,h1_2)
	h0_3 = H(h0_2,h2_3)
	h0_4 = H(h0_3,h3_4)
	x = h0_2[0][3]
	y = h0_2[1][3]
	z = h0_2[2][3]
	return [x,y,z] 
def jointvalue(data):
	th1 = data.position[0]
	th2 = data.position[1] + 0.00031
	th3 = data.position[2] + 0.0002
	#th4 = data.position[3]
	ab = fk(th1,th2,th3)
	(trans,rot) = listener.lookupTransform("/base_link","/gripper_rev", rospy.Time(0))
	euler = euler_from_quaternion(rot)
	ans = [[(((ab[0]-trans[0])*100)/trans[0])],[(((ab[1]-trans[1])*100)/trans[1])],[(((ab[2]-trans[2])*100)/trans[2])]]
	print (ab)

rospy.init_node('fk', anonymous=True)
listener = tf.TransformListener() 
r = rospy.Rate(1)
while not rospy.is_shutdown():
	sub = rospy.Subscriber('joint_states', JointState, jointvalue)
	r.sleep()
