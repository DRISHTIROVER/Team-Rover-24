import numpy as np
import rospy
from sensor_msgs.msg import JointState
T1 =0
T2 =0
T1=(T1*np.pi)/180
T2=(T2*np.pi)/180
PT = [[T1,np.pi/2,0.0295,0.027],[T2,0,1.000,0.00]]
if __name__ == '__main__':
    T1 =0
    T2 =0
    T1=(T1*np.pi)/180
    T2=(T2*np.pi)/180
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/",JointState,queue_size = 500)
    joint = JointState()
    while not rospy.is_shutdown():
        r = rospy.Rate(0.5)
        joint.header.stamp = rospy.Time.now()
        joint.name = ["prismatic1","revolute1","revolute2","revolute3","EE_right","EE_left"]
        joint.velocity = []
        joint.effort = []
        r.sleep()
        HTM0_1 = [[np.cos(PT[0][0]),-np.sin(PT[0][0])*np.cos(PT[0][1]),np.sin(PT[0][0])*np.sin(PT[0][1]),PT[0][2]*np.cos(PT[0][0])],
        [np.sin(PT[0][0]),np.cos(PT[0][0])*np.cos(PT[0][1]),-np.cos(PT[0][0])*np.sin(PT[0][1]),PT[0][2]*np.sin(PT[0][0])],
        [0,np.sin(PT[0][1]),np.cos(PT[0][1]),PT[0][3]],
        [0,0,0,1]]
        i =1
        HTM1_2= [[np.cos(PT[i][0]),-np.sin(PT[i][0])*np.cos(PT[i][1]),np.sin(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.cos(PT[i][0])],
        [np.sin(PT[i][0]),np.cos(PT[i][0])*np.cos(PT[i][1]),-np.cos(PT[i][0])*np.sin(PT[i][1]),PT[i][2]*np.sin(PT[i][0])],
        [0,np.sin(PT[i][1]),np.cos(PT[i][1]),PT[i][3]],
        [0,0,0,1]]
        HTM0_2 = np.dot(HTM0_1,HTM1_2)
        joint.position = [0,HTM0_2[4][1],HTM0_2[4][2],HTM0_2[4][3],0,0]
        pub.publish(joint)
    
