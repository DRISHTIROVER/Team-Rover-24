
(cl:in-package :asdf)

(defsystem "custom_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IMU" :depends-on ("_package_IMU"))
    (:file "_package_IMU" :depends-on ("_package"))
    (:file "g2g_x_z" :depends-on ("_package_g2g_x_z"))
    (:file "_package_g2g_x_z" :depends-on ("_package"))
    (:file "gui_msg" :depends-on ("_package_gui_msg"))
    (:file "_package_gui_msg" :depends-on ("_package"))
    (:file "lat_long_msg" :depends-on ("_package_lat_long_msg"))
    (:file "_package_lat_long_msg" :depends-on ("_package"))
    (:file "obavoid_flag_x_z" :depends-on ("_package_obavoid_flag_x_z"))
    (:file "_package_obavoid_flag_x_z" :depends-on ("_package"))
    (:file "ultrasonic_msg" :depends-on ("_package_ultrasonic_msg"))
    (:file "_package_ultrasonic_msg" :depends-on ("_package"))
    (:file "updated_xy" :depends-on ("_package_updated_xy"))
    (:file "_package_updated_xy" :depends-on ("_package"))
  ))