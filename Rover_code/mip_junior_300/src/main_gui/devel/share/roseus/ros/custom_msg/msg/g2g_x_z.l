;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::g2g_x_z)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'g2g_x_z (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::G2G_X_Z")
  (make-package "CUSTOM_MSG::G2G_X_Z"))

(in-package "ROS")
;;//! \htmlinclude g2g_x_z.msg.html


(defclass custom_msg::g2g_x_z
  :super ros::object
  :slots (_x _z ))

(defmethod custom_msg::g2g_x_z
  (:init
   (&key
    ((:x __x) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _z (float __z))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msg::g2g_x_z :md5sum-) "3d990ebeae1ee5ba6990ba82cc74e4c5")
(setf (get custom_msg::g2g_x_z :datatype-) "custom_msg/g2g_x_z")
(setf (get custom_msg::g2g_x_z :definition-)
      "float32 x
float32 z


")



(provide :custom_msg/g2g_x_z "3d990ebeae1ee5ba6990ba82cc74e4c5")


