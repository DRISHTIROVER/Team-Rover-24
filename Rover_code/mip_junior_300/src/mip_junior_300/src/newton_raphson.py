from sympy import *
import rospy
from sensor_msgs.msg import JointState

if __name__ == '__main__':
    T1 = Symbol('T1')
    T2 = Symbol('T2')
    #T1=(T1* .pi)/180
    #T2=(T2* .pi)/180
    PT = [[T1,pi/2,0.0295,0.027],[T2,0,1.000,0.00]]
    rospy.init_node('try', anonymous=True)
    pub = rospy.Publisher("/joint_states",JointState,queue_size = 500)
    joint = JointState()
    while not rospy.is_shutdown():
        r = rospy.Rate(0.5)
        joint.header.stamp = rospy.Time.now()
        joint.name = ["prismatic1","revolute1","revolute2","revolute3","EE_right","EE_left"]
        joint.velocity = []
        joint.effort = []
        r.sleep()
        HTM0_1 = Matrix([[  cos(PT[0][0]),-  sin(PT[0][0])*  cos(PT[0][1]),  sin(PT[0][0])*  sin(PT[0][1]),PT[0][2]*  cos(PT[0][0])],
        [  sin(PT[0][0]),  cos(PT[0][0])*  cos(PT[0][1]),-  cos(PT[0][0])*  sin(PT[0][1]),PT[0][2]*  sin(PT[0][0])],
        [0,  sin(PT[0][1]),  cos(PT[0][1]),PT[0][3]],
        [0,0,0,1]])
        i =1
        HTM1_2= Matrix([[  cos(PT[i][0]),-  sin(PT[i][0])*  cos(PT[i][1]),  sin(PT[i][0])*  sin(PT[i][1]),PT[i][2]*  cos(PT[i][0])],
        [  sin(PT[i][0]),  cos(PT[i][0])*  cos(PT[i][1]),-  cos(PT[i][0])*  sin(PT[i][1]),PT[i][2]*  sin(PT[i][0])],
        [0,  sin(PT[i][1]),  cos(PT[i][1]),PT[i][3]],
        [0,0,0,1]])
        HTM0_2  =   HTM0_1*HTM1_2
        #joint.position = [0,HTM0_2[4][1],HTM0_2[4][2],HTM0_2[4],0,0]
        print(HTM0_2[0,3])
        print(HTM0_2[1,3])
        print(HTM0_2[2,3])
        #print(HTM0_2[1][3])
        #rint(HTM0_2[2][3])
        #pub.publish(joint)
    