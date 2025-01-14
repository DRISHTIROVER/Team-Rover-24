; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude lat_long_msg.msg.html

(cl:defclass <lat_long_msg> (roslisp-msg-protocol:ros-message)
  ((lat
    :reader lat
    :initarg :lat
    :type cl:float
    :initform 0.0)
   (long
    :reader long
    :initarg :long
    :type cl:float
    :initform 0.0))
)

(cl:defclass lat_long_msg (<lat_long_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <lat_long_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'lat_long_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<lat_long_msg> is deprecated: use custom_msg-msg:lat_long_msg instead.")))

(cl:ensure-generic-function 'lat-val :lambda-list '(m))
(cl:defmethod lat-val ((m <lat_long_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:lat-val is deprecated.  Use custom_msg-msg:lat instead.")
  (lat m))

(cl:ensure-generic-function 'long-val :lambda-list '(m))
(cl:defmethod long-val ((m <lat_long_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:long-val is deprecated.  Use custom_msg-msg:long instead.")
  (long m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <lat_long_msg>) ostream)
  "Serializes a message object of type '<lat_long_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'long))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <lat_long_msg>) istream)
  "Deserializes a message object of type '<lat_long_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lat) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'long) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<lat_long_msg>)))
  "Returns string type for a message object of type '<lat_long_msg>"
  "custom_msg/lat_long_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'lat_long_msg)))
  "Returns string type for a message object of type 'lat_long_msg"
  "custom_msg/lat_long_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<lat_long_msg>)))
  "Returns md5sum for a message object of type '<lat_long_msg>"
  "72e4d8aabf891137eea8ff409e1fa1a8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'lat_long_msg)))
  "Returns md5sum for a message object of type 'lat_long_msg"
  "72e4d8aabf891137eea8ff409e1fa1a8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<lat_long_msg>)))
  "Returns full string definition for message of type '<lat_long_msg>"
  (cl:format cl:nil "float32 lat~%float32 long~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'lat_long_msg)))
  "Returns full string definition for message of type 'lat_long_msg"
  (cl:format cl:nil "float32 lat~%float32 long~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <lat_long_msg>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <lat_long_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'lat_long_msg
    (cl:cons ':lat (lat msg))
    (cl:cons ':long (long msg))
))
