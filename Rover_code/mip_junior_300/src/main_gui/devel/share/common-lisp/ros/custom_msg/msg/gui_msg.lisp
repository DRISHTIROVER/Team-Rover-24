; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude gui_msg.msg.html

(cl:defclass <gui_msg> (roslisp-msg-protocol:ros-message)
  ((flag_ob_avoid_or_g2g
    :reader flag_ob_avoid_or_g2g
    :initarg :flag_ob_avoid_or_g2g
    :type cl:integer
    :initform 0)
   (goal_no
    :reader goal_no
    :initarg :goal_no
    :type cl:integer
    :initform 0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0)
   (location_x
    :reader location_x
    :initarg :location_x
    :type cl:float
    :initform 0.0)
   (location_y
    :reader location_y
    :initarg :location_y
    :type cl:float
    :initform 0.0))
)

(cl:defclass gui_msg (<gui_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gui_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gui_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<gui_msg> is deprecated: use custom_msg-msg:gui_msg instead.")))

(cl:ensure-generic-function 'flag_ob_avoid_or_g2g-val :lambda-list '(m))
(cl:defmethod flag_ob_avoid_or_g2g-val ((m <gui_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:flag_ob_avoid_or_g2g-val is deprecated.  Use custom_msg-msg:flag_ob_avoid_or_g2g instead.")
  (flag_ob_avoid_or_g2g m))

(cl:ensure-generic-function 'goal_no-val :lambda-list '(m))
(cl:defmethod goal_no-val ((m <gui_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:goal_no-val is deprecated.  Use custom_msg-msg:goal_no instead.")
  (goal_no m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <gui_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:distance-val is deprecated.  Use custom_msg-msg:distance instead.")
  (distance m))

(cl:ensure-generic-function 'location_x-val :lambda-list '(m))
(cl:defmethod location_x-val ((m <gui_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:location_x-val is deprecated.  Use custom_msg-msg:location_x instead.")
  (location_x m))

(cl:ensure-generic-function 'location_y-val :lambda-list '(m))
(cl:defmethod location_y-val ((m <gui_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:location_y-val is deprecated.  Use custom_msg-msg:location_y instead.")
  (location_y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gui_msg>) ostream)
  "Serializes a message object of type '<gui_msg>"
  (cl:let* ((signed (cl:slot-value msg 'flag_ob_avoid_or_g2g)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'goal_no)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'location_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'location_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gui_msg>) istream)
  "Deserializes a message object of type '<gui_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag_ob_avoid_or_g2g) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'goal_no) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'location_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'location_y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gui_msg>)))
  "Returns string type for a message object of type '<gui_msg>"
  "custom_msg/gui_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gui_msg)))
  "Returns string type for a message object of type 'gui_msg"
  "custom_msg/gui_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gui_msg>)))
  "Returns md5sum for a message object of type '<gui_msg>"
  "fcfe2d5e2cb7ff83917cfec5609b532b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gui_msg)))
  "Returns md5sum for a message object of type 'gui_msg"
  "fcfe2d5e2cb7ff83917cfec5609b532b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gui_msg>)))
  "Returns full string definition for message of type '<gui_msg>"
  (cl:format cl:nil "int32 flag_ob_avoid_or_g2g ~%int32 goal_no~%float64 distance~%float64 location_x~%float64 location_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gui_msg)))
  "Returns full string definition for message of type 'gui_msg"
  (cl:format cl:nil "int32 flag_ob_avoid_or_g2g ~%int32 goal_no~%float64 distance~%float64 location_x~%float64 location_y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gui_msg>))
  (cl:+ 0
     4
     4
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gui_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'gui_msg
    (cl:cons ':flag_ob_avoid_or_g2g (flag_ob_avoid_or_g2g msg))
    (cl:cons ':goal_no (goal_no msg))
    (cl:cons ':distance (distance msg))
    (cl:cons ':location_x (location_x msg))
    (cl:cons ':location_y (location_y msg))
))
