#!/usr/bin/env python3
 
# Author: Automatic Addison https://automaticaddison.com
# Description: Uses the ROS action lib to move a robotic arm to a goal location
 
# Import the necessary libraries
from __future__ import print_function
import sys # Printing
import rospy # Python client library
import actionlib # ROS action library
from control_msgs.msg import FollowJointTrajectoryAction, FollowJointTrajectoryGoal # Controller messages
from std_msgs.msg import Float64 # 64-bit floating point numbers
from trajectory_msgs.msg import JointTrajectoryPoint # Robot trajectories
from blessed import Terminal 
term = Terminal()

msg = """
*************************************************
i <> o
j <> l
, <> u
. <> m
k <> ;

r to reset and only works after launch
-------------------------------------------------
t : to exit
*************************************************
"""

moveBindings = {
   'i': (0.9, 0, 0, 0, 0),
   'o': (-0.9, 0, 0, 0, 0),
   'j': (0, 0.9, 0, 0, 0),
   'l': (0, -0.9, 0, 0, 0),
   'u': (0, 0, -0.9, 0, 0),
   ',': (0, 0, 0.9, 0, 0),
   '.': (0, 0, 0, 0, 0.9),
   'm': (0, 0, 0, 0, -0.9),
   'k': (0, 0, 0, 0.9, 0),
   ';': (0, 0, 0, -0.9, 0),
   'r': (0, 0, 0, 0, 0),
   't': (2, 0, 0, 0, 0),
}

def move_robot_arm(joint_values):
  """
  Function to move the robot arm to desired joint angles.
  :param: joint_values A list of desired angles for the joints of a robot arm 
  """
  # Create the SimpleActionClient, passing the type of the action to the constructor
  arm_client = actionlib.SimpleActionClient('arm_controller/follow_joint_trajectory', FollowJointTrajectoryAction)
 
  # Wait for the server to start up and start listening for goals.
  arm_client.wait_for_server()
     
  # Create a new goal to send to the Action Server
  arm_goal = FollowJointTrajectoryGoal()
 
  # Store the names of each joint of the robot arm
  arm_goal.trajectory.joint_names = ['arm_base_joint', 'shoulder_joint','bottom_wrist_joint' ,'elbow_joint', 'top_wrist_joint']
   
  # Create a trajectory point   
  point = JointTrajectoryPoint()
 
  # Store the desired joint values
  point.positions = joint_values
 
  # Set the time it should in seconds take to move the arm to the desired joint angles
  point.time_from_start = rospy.Duration(3)
 
  # Add the desired joint values to the goal
  arm_goal.trajectory.points.append(point)
 
  # Define timeout values
  exec_timeout = rospy.Duration(10)
  prmpt_timeout = rospy.Duration(5)
 
  # Send a goal to the ActionServer and wait for the server to finish performing the action
  arm_client.send_goal_and_wait(arm_goal, exec_timeout, prmpt_timeout)
 
 
if __name__ == '__main__':
  """
  Main method.
  """
  try:
    # Initialize a rospy node so that the SimpleActionClient can
    # publish and subscribe over ROS.
    rospy.init_node('send_goal_to_arm_py')
 
    # Move the joints of the robot arm to the desired angles in radians
    
    #move_robot_arm([-0.1, 0.5, 0.02, 0, 0])
    x = 0.0
    y = 0.0
    z = 0.0
    c = 0.0
    b = 0.0
    print(msg)
    i =1
    while i!=2 :
      with term.cbreak():
        key = term.inkey()  #takes input from terminal
      if key in moveBindings.keys():
        i = moveBindings[key][0]
        z = z + moveBindings[key][0]
        x = x + moveBindings[key][1]
        c = c + moveBindings[key][2]
        y = y + moveBindings[key][3]
        b = b + moveBindings[key][4]
        move_robot_arm([z, x, c, y, b])
  
     
  except rospy.ROSInterruptException:
    print("Program interrupted before completion.", file= sys.stderr)
