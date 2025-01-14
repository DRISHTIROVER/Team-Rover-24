; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude g2g_x_z.msg.html

(cl:defclass <g2g_x_z> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:float
    :initform 0.0))
)

(cl:defclass g2g_x_z (<g2g_x_z>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <g2g_x_z>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'g2g_x_z)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<g2g_x_z> is deprecated: use custom_msg-msg:g2g_x_z instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <g2g_x_z>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:x-val is deprecated.  Use custom_msg-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <g2g_x_z>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:z-val is deprecated.  Use custom_msg-msg:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <g2g_x_z>) ostream)
  "Serializes a message object of type '<g2g_x_z>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <g2g_x_z>) istream)
  "Deserializes a message object of type '<g2g_x_z>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'z) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<g2g_x_z>)))
  "Returns string type for a message object of type '<g2g_x_z>"
  "custom_msg/g2g_x_z")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'g2g_x_z)))
  "Returns string type for a message object of type 'g2g_x_z"
  "custom_msg/g2g_x_z")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<g2g_x_z>)))
  "Returns md5sum for a message object of type '<g2g_x_z>"
  "3d990ebeae1ee5ba6990ba82cc74e4c5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'g2g_x_z)))
  "Returns md5sum for a message object of type 'g2g_x_z"
  "3d990ebeae1ee5ba6990ba82cc74e4c5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<g2g_x_z>)))
  "Returns full string definition for message of type '<g2g_x_z>"
  (cl:format cl:nil "float32 x~%float32 z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'g2g_x_z)))
  "Returns full string definition for message of type 'g2g_x_z"
  (cl:format cl:nil "float32 x~%float32 z~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <g2g_x_z>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <g2g_x_z>))
  "Converts a ROS message object to a list"
  (cl:list 'g2g_x_z
    (cl:cons ':x (x msg))
    (cl:cons ':z (z msg))
))
