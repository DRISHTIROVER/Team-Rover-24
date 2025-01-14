;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::ultrasonic_msg)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'ultrasonic_msg (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::ULTRASONIC_MSG")
  (make-package "CUSTOM_MSG::ULTRASONIC_MSG"))

(in-package "ROS")
;;//! \htmlinclude ultrasonic_msg.msg.html


(defclass custom_msg::ultrasonic_msg
  :super ros::object
  :slots (_r1 _r2 _r3 _r4 _r5 ))

(defmethod custom_msg::ultrasonic_msg
  (:init
   (&key
    ((:r1 __r1) 0.0)
    ((:r2 __r2) 0.0)
    ((:r3 __r3) 0.0)
    ((:r4 __r4) 0.0)
    ((:r5 __r5) 0.0)
    )
   (send-super :init)
   (setq _r1 (float __r1))
   (setq _r2 (float __r2))
   (setq _r3 (float __r3))
   (setq _r4 (float __r4))
   (setq _r5 (float __r5))
   self)
  (:r1
   (&optional __r1)
   (if __r1 (setq _r1 __r1)) _r1)
  (:r2
   (&optional __r2)
   (if __r2 (setq _r2 __r2)) _r2)
  (:r3
   (&optional __r3)
   (if __r3 (setq _r3 __r3)) _r3)
  (:r4
   (&optional __r4)
   (if __r4 (setq _r4 __r4)) _r4)
  (:r5
   (&optional __r5)
   (if __r5 (setq _r5 __r5)) _r5)
  (:serialization-length
   ()
   (+
    ;; float32 _r1
    4
    ;; float32 _r2
    4
    ;; float32 _r3
    4
    ;; float32 _r4
    4
    ;; float32 _r5
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _r1
       (sys::poke _r1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _r2
       (sys::poke _r2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _r3
       (sys::poke _r3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _r4
       (sys::poke _r4 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _r5
       (sys::poke _r5 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _r1
     (setq _r1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _r2
     (setq _r2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _r3
     (setq _r3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _r4
     (setq _r4 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _r5
     (setq _r5 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get custom_msg::ultrasonic_msg :md5sum-) "e6539a993ae760db074e494e04960752")
(setf (get custom_msg::ultrasonic_msg :datatype-) "custom_msg/ultrasonic_msg")
(setf (get custom_msg::ultrasonic_msg :definition-)
      "float32 r1
float32 r2
float32 r3
float32 r4
float32 r5

")



(provide :custom_msg/ultrasonic_msg "e6539a993ae760db074e494e04960752")


