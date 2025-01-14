#!/usr/bin/env python3
import rospy,tf,time
from tf.transformations import euler_from_quaternion

rospy.init_node("listner")
listener = tf.TransformListener()   
while not rospy.is_shutdown():
    try:
        (trans,rot) = listener.lookupTransform('/world', '/end_point', rospy.Time(0))
    except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
        continue
    euler = euler_from_quaternion(rot)
    time_now = rospy.Time.now()
    time_now = int(str(time_now)[:10])
    time_now = time_now%10000
    print (str(time_now+0.1)+","+str(trans[0])+","+str(trans[1])+","+str(trans[2]))
    print (str(time_now+0.2)+","+str(euler[0])+","+str(euler[1])+","+str(euler[2]))
    print ("")
    time.sleep(1)