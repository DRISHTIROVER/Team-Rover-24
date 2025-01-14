; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude ultrasonic_msg.msg.html

(cl:defclass <ultrasonic_msg> (roslisp-msg-protocol:ros-message)
  ((r1
    :reader r1
    :initarg :r1
    :type cl:float
    :initform 0.0)
   (r2
    :reader r2
    :initarg :r2
    :type cl:float
    :initform 0.0)
   (r3
    :reader r3
    :initarg :r3
    :type cl:float
    :initform 0.0)
   (r4
    :reader r4
    :initarg :r4
    :type cl:float
    :initform 0.0)
   (r5
    :reader r5
    :initarg :r5
    :type cl:float
    :initform 0.0))
)

(cl:defclass ultrasonic_msg (<ultrasonic_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ultrasonic_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ultrasonic_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<ultrasonic_msg> is deprecated: use custom_msg-msg:ultrasonic_msg instead.")))

(cl:ensure-generic-function 'r1-val :lambda-list '(m))
(cl:defmethod r1-val ((m <ultrasonic_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:r1-val is deprecated.  Use custom_msg-msg:r1 instead.")
  (r1 m))

(cl:ensure-generic-function 'r2-val :lambda-list '(m))
(cl:defmethod r2-val ((m <ultrasonic_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:r2-val is deprecated.  Use custom_msg-msg:r2 instead.")
  (r2 m))

(cl:ensure-generic-function 'r3-val :lambda-list '(m))
(cl:defmethod r3-val ((m <ultrasonic_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:r3-val is deprecated.  Use custom_msg-msg:r3 instead.")
  (r3 m))

(cl:ensure-generic-function 'r4-val :lambda-list '(m))
(cl:defmethod r4-val ((m <ultrasonic_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:r4-val is deprecated.  Use custom_msg-msg:r4 instead.")
  (r4 m))

(cl:ensure-generic-function 'r5-val :lambda-list '(m))
(cl:defmethod r5-val ((m <ultrasonic_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:r5-val is deprecated.  Use custom_msg-msg:r5 instead.")
  (r5 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ultrasonic_msg>) ostream)
  "Serializes a message object of type '<ultrasonic_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r4))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'r5))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ultrasonic_msg>) istream)
  "Deserializes a message object of type '<ultrasonic_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r3) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r4) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'r5) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ultrasonic_msg>)))
  "Returns string type for a message object of type '<ultrasonic_msg>"
  "custom_msg/ultrasonic_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ultrasonic_msg)))
  "Returns string type for a message object of type 'ultrasonic_msg"
  "custom_msg/ultrasonic_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ultrasonic_msg>)))
  "Returns md5sum for a message object of type '<ultrasonic_msg>"
  "e6539a993ae760db074e494e04960752")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ultrasonic_msg)))
  "Returns md5sum for a message object of type 'ultrasonic_msg"
  "e6539a993ae760db074e494e04960752")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ultrasonic_msg>)))
  "Returns full string definition for message of type '<ultrasonic_msg>"
  (cl:format cl:nil "float32 r1~%float32 r2~%float32 r3~%float32 r4~%float32 r5~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ultrasonic_msg)))
  "Returns full string definition for message of type 'ultrasonic_msg"
  (cl:format cl:nil "float32 r1~%float32 r2~%float32 r3~%float32 r4~%float32 r5~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ultrasonic_msg>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ultrasonic_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'ultrasonic_msg
    (cl:cons ':r1 (r1 msg))
    (cl:cons ':r2 (r2 msg))
    (cl:cons ':r3 (r3 msg))
    (cl:cons ':r4 (r4 msg))
    (cl:cons ':r5 (r5 msg))
))
