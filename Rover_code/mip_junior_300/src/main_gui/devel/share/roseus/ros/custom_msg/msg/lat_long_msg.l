;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::lat_long_msg)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'lat_long_msg (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::LAT_LONG_MSG")
  (make-package "CUSTOM_MSG::LAT_LONG_MSG"))

(in-package "ROS")
;;//! \htmlinclude lat_long_msg.msg.html


(defclass custom_msg::lat_long_msg
  :super ros::object
  :slots (_lat _long ))

(defmethod custom_msg::lat_long_msg
  (:init
   (&key
    ((:lat __lat) 0.0)
    ((:long __long) 0.0)
    )
   (send-super :init)
   (setq _lat (float __lat))
   (setq _long (float __long))
   self)
  (:lat
   (&optional __lat)
   (if __lat (setq _lat __lat)) _lat)
  (:long
   (&optional __long)
   (if __long (setq _long __long)) _long)
  (:serialization-length
   ()
   (+
    ;; float32 _lat
    4
    ;; float32 _long
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _lat
       (sys::poke _lat (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _long
       (sys::poke _long (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _lat
     (setq _lat (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _long
     (setq _long (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msg::lat_long_msg :md5sum-) "72e4d8aabf891137eea8ff409e1fa1a8")
(setf (get custom_msg::lat_long_msg :datatype-) "custom_msg/lat_long_msg")
(setf (get custom_msg::lat_long_msg :definition-)
      "float32 lat
float32 long

")



(provide :custom_msg/lat_long_msg "72e4d8aabf891137eea8ff409e1fa1a8")


