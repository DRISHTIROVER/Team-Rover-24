;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::obavoid_flag_x_z)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'obavoid_flag_x_z (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::OBAVOID_FLAG_X_Z")
  (make-package "CUSTOM_MSG::OBAVOID_FLAG_X_Z"))

(in-package "ROS")
;;//! \htmlinclude obavoid_flag_x_z.msg.html


(defclass custom_msg::obavoid_flag_x_z
  :super ros::object
  :slots (_flag _x _z ))

(defmethod custom_msg::obavoid_flag_x_z
  (:init
   (&key
    ((:flag __flag) 0)
    ((:x __x) 0.0)
    ((:z __z) 0.0)
    )
   (send-super :init)
   (setq _flag (round __flag))
   (setq _x (float __x))
   (setq _z (float __z))
   self)
  (:flag
   (&optional __flag)
   (if __flag (setq _flag __flag)) _flag)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; int32 _flag
    4
    ;; float32 _x
    4
    ;; float32 _z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _flag
       (write-long _flag s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _flag
     (setq _flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msg::obavoid_flag_x_z :md5sum-) "e1d6d4965575c5ce2f191a4a891e87a9")
(setf (get custom_msg::obavoid_flag_x_z :datatype-) "custom_msg/obavoid_flag_x_z")
(setf (get custom_msg::obavoid_flag_x_z :definition-)
      "int32 flag
float32 x
float32 z

")



(provide :custom_msg/obavoid_flag_x_z "e1d6d4965575c5ce2f191a4a891e87a9")


