; Auto-generated. Do not edit!


(cl:in-package hubo_ros-msg)


;//! \htmlinclude HuboHand.msg.html

(cl:defclass <HuboHand> (roslisp-msg-protocol:ros-message)
  ((thumb
    :reader thumb
    :initarg :thumb
    :type hubo_ros-msg:HuboJointState
    :initform (cl:make-instance 'hubo_ros-msg:HuboJointState))
   (index
    :reader index
    :initarg :index
    :type hubo_ros-msg:HuboJointState
    :initform (cl:make-instance 'hubo_ros-msg:HuboJointState))
   (middle
    :reader middle
    :initarg :middle
    :type hubo_ros-msg:HuboJointState
    :initform (cl:make-instance 'hubo_ros-msg:HuboJointState))
   (ring
    :reader ring
    :initarg :ring
    :type hubo_ros-msg:HuboJointState
    :initform (cl:make-instance 'hubo_ros-msg:HuboJointState))
   (pinky
    :reader pinky
    :initarg :pinky
    :type hubo_ros-msg:HuboJointState
    :initform (cl:make-instance 'hubo_ros-msg:HuboJointState)))
)

(cl:defclass HuboHand (<HuboHand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HuboHand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HuboHand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hubo_ros-msg:<HuboHand> is deprecated: use hubo_ros-msg:HuboHand instead.")))

(cl:ensure-generic-function 'thumb-val :lambda-list '(m))
(cl:defmethod thumb-val ((m <HuboHand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros-msg:thumb-val is deprecated.  Use hubo_ros-msg:thumb instead.")
  (thumb m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <HuboHand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros-msg:index-val is deprecated.  Use hubo_ros-msg:index instead.")
  (index m))

(cl:ensure-generic-function 'middle-val :lambda-list '(m))
(cl:defmethod middle-val ((m <HuboHand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros-msg:middle-val is deprecated.  Use hubo_ros-msg:middle instead.")
  (middle m))

(cl:ensure-generic-function 'ring-val :lambda-list '(m))
(cl:defmethod ring-val ((m <HuboHand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros-msg:ring-val is deprecated.  Use hubo_ros-msg:ring instead.")
  (ring m))

(cl:ensure-generic-function 'pinky-val :lambda-list '(m))
(cl:defmethod pinky-val ((m <HuboHand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros-msg:pinky-val is deprecated.  Use hubo_ros-msg:pinky instead.")
  (pinky m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HuboHand>) ostream)
  "Serializes a message object of type '<HuboHand>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'thumb) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'index) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'middle) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'ring) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pinky) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HuboHand>) istream)
  "Deserializes a message object of type '<HuboHand>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'thumb) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'index) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'middle) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'ring) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pinky) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HuboHand>)))
  "Returns string type for a message object of type '<HuboHand>"
  "hubo_ros/HuboHand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HuboHand)))
  "Returns string type for a message object of type 'HuboHand"
  "hubo_ros/HuboHand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HuboHand>)))
  "Returns md5sum for a message object of type '<HuboHand>"
  "dfd31cdc3f67d0c6f51804ccff860aaf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HuboHand)))
  "Returns md5sum for a message object of type 'HuboHand"
  "dfd31cdc3f67d0c6f51804ccff860aaf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HuboHand>)))
  "Returns full string definition for message of type '<HuboHand>"
  (cl:format cl:nil "HuboJointState thumb~%HuboJointState index~%HuboJointState middle~%HuboJointState ring~%HuboJointState pinky~%~%================================================================================~%MSG: hubo_ros/HuboJointState~%string name~%float64 commanded~%float64 position~%float64 velocity~%float64 current~%float64 temperature~%int32 active~%int32 zeroed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HuboHand)))
  "Returns full string definition for message of type 'HuboHand"
  (cl:format cl:nil "HuboJointState thumb~%HuboJointState index~%HuboJointState middle~%HuboJointState ring~%HuboJointState pinky~%~%================================================================================~%MSG: hubo_ros/HuboJointState~%string name~%float64 commanded~%float64 position~%float64 velocity~%float64 current~%float64 temperature~%int32 active~%int32 zeroed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HuboHand>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'thumb))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'index))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'middle))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'ring))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pinky))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HuboHand>))
  "Converts a ROS message object to a list"
  (cl:list 'HuboHand
    (cl:cons ':thumb (thumb msg))
    (cl:cons ':index (index msg))
    (cl:cons ':middle (middle msg))
    (cl:cons ':ring (ring msg))
    (cl:cons ':pinky (pinky msg))
))
