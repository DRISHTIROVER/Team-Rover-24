# ps4 control(tele_op)
import pygame
import time
from geometry_msgs.msg import Twist
import rospy
import pprint
X,Y=0.0,0.0
class PS4Controller(object):
    """Class representing the PS4 controller. Pretty straightforward functionality."""
    global X
    global Y
    controller = None
    axis_data = None
    button_data = None
    hat_data = None
    rospy.init_node('custom_talker', anonymous=True)
    pub = rospy.Publisher('/manipulator', Twist,queue_size = 10)

    def init(self):
        """Initialize the joystick components"""

        pygame.init()
        pygame.joystick.init()
        self.controller = pygame.joystick.Joystick(0)
        self.controller.init()

    def listen(self):
        """Listen for events to happen"""
        if not self.axis_data:
            self.axis_data = {}

        if not self.button_data:
            self.button_data = {}
            for i in range(self.controller.get_numbuttons()):
                self.button_data[i] = 0
        if not self.hat_data:
            self.hat_data = {}
            for i in range(self.controller.get_numhats()):
                self.hat_data[i] = (0, 0)

        while not rospy.is_shutdown():
            time.sleep(0.01)
            for event in pygame.event.get():
                if event.type == pygame.JOYAXISMOTION:
                    self.axis_data[event.axis] = round(event.value, 2)

                    msg = Twist()

                pprint.pprint(self.axis_data)
            
                # print("3="+str(step3),"2="+str(step2),step1)
                # print("drishti_joint="+str(drishti_joint)+"Svnit_joint="+str(Svnit_joint)+"gripper_joint="+str(gripper_joint))


ps4 = PS4Controller()
ps4.init()
ps4.listen()
