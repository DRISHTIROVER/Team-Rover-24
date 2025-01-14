;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::gui_msg)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'gui_msg (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::GUI_MSG")
  (make-package "CUSTOM_MSG::GUI_MSG"))

(in-package "ROS")
;;//! \htmlinclude gui_msg.msg.html


(defclass custom_msg::gui_msg
  :super ros::object
  :slots (_flag_ob_avoid_or_g2g _goal_no _distance _location_x _location_y ))

(defmethod custom_msg::gui_msg
  (:init
   (&key
    ((:flag_ob_avoid_or_g2g __flag_ob_avoid_or_g2g) 0)
    ((:goal_no __goal_no) 0)
    ((:distance __distance) 0.0)
    ((:location_x __location_x) 0.0)
    ((:location_y __location_y) 0.0)
    )
   (send-super :init)
   (setq _flag_ob_avoid_or_g2g (round __flag_ob_avoid_or_g2g))
   (setq _goal_no (round __goal_no))
   (setq _distance (float __distance))
   (setq _location_x (float __location_x))
   (setq _location_y (float __location_y))
   self)
  (:flag_ob_avoid_or_g2g
   (&optional __flag_ob_avoid_or_g2g)
   (if __flag_ob_avoid_or_g2g (setq _flag_ob_avoid_or_g2g __flag_ob_avoid_or_g2g)) _flag_ob_avoid_or_g2g)
  (:goal_no
   (&optional __goal_no)
   (if __goal_no (setq _goal_no __goal_no)) _goal_no)
  (:distance
   (&optional __distance)
   (if __distance (setq _distance __distance)) _distance)
  (:location_x
   (&optional __location_x)
   (if __location_x (setq _location_x __location_x)) _location_x)
  (:location_y
   (&optional __location_y)
   (if __location_y (setq _location_y __location_y)) _location_y)
  (:serialization-length
   ()
   (+
    ;; int32 _flag_ob_avoid_or_g2g
    4
    ;; int32 _goal_no
    4
    ;; float64 _distance
    8
    ;; float64 _location_x
    8
    ;; float64 _location_y
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _flag_ob_avoid_or_g2g
       (write-long _flag_ob_avoid_or_g2g s)
     ;; int32 _goal_no
       (write-long _goal_no s)
     ;; float64 _distance
       (sys::poke _distance (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _location_x
       (sys::poke _location_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _location_y
       (sys::poke _location_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _flag_ob_avoid_or_g2g
     (setq _flag_ob_avoid_or_g2g (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _goal_no
     (setq _goal_no (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _distance
     (setq _distance (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _location_x
     (setq _location_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _location_y
     (setq _location_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get custom_msg::gui_msg :md5sum-) "fcfe2d5e2cb7ff83917cfec5609b532b")
(setf (get custom_msg::gui_msg :datatype-) "custom_msg/gui_msg")
(setf (get custom_msg::gui_msg :definition-)
      "int32 flag_ob_avoid_or_g2g 
int32 goal_no
float64 distance
float64 location_x
float64 location_y

")



(provide :custom_msg/gui_msg "fcfe2d5e2cb7ff83917cfec5609b532b")


