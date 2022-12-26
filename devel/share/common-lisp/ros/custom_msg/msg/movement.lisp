; Auto-generated. Do not edit!


(cl:in-package custom_msg-msg)


;//! \htmlinclude movement.msg.html

(cl:defclass <movement> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (distance
    :reader distance
    :initarg :distance
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64)))
)

(cl:defclass movement (<movement>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <movement>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'movement)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msg-msg:<movement> is deprecated: use custom_msg-msg:movement instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <movement>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:angle-val is deprecated.  Use custom_msg-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <movement>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msg-msg:distance-val is deprecated.  Use custom_msg-msg:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <movement>) ostream)
  "Serializes a message object of type '<movement>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'angle) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'distance) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <movement>) istream)
  "Deserializes a message object of type '<movement>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'angle) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'distance) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<movement>)))
  "Returns string type for a message object of type '<movement>"
  "custom_msg/movement")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'movement)))
  "Returns string type for a message object of type 'movement"
  "custom_msg/movement")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<movement>)))
  "Returns md5sum for a message object of type '<movement>"
  "8d9d131ce4cf4580f59de99ac7adc6df")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'movement)))
  "Returns md5sum for a message object of type 'movement"
  "8d9d131ce4cf4580f59de99ac7adc6df")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<movement>)))
  "Returns full string definition for message of type '<movement>"
  (cl:format cl:nil "#Header header~%std_msgs/Float64 angle~%std_msgs/Float64 distance~%~%~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'movement)))
  "Returns full string definition for message of type 'movement"
  (cl:format cl:nil "#Header header~%std_msgs/Float64 angle~%std_msgs/Float64 distance~%~%~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <movement>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'angle))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'distance))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <movement>))
  "Converts a ROS message object to a list"
  (cl:list 'movement
    (cl:cons ':angle (angle msg))
    (cl:cons ':distance (distance msg))
))
