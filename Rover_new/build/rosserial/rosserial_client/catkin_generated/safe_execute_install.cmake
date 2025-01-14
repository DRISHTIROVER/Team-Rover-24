execute_process(COMMAND "/home/rover_1/rover_new/build/rosserial/rosserial_client/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/rover_1/rover_new/build/rosserial/rosserial_client/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
