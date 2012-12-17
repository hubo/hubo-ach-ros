; Auto-generated. Do not edit!


(cl:in-package hubo_ros_msgs-msg)


;//! \htmlinclude HuboTrajectory.msg.html

(cl:defclass <HuboTrajectory> (roslisp-msg-protocol:ros-message)
  ((joints
    :reader joints
    :initarg :joints
    :type (cl:vector hubo_ros_msgs-msg:HuboJointCommand)
   :initform (cl:make-array 0 :element-type 'hubo_ros_msgs-msg:HuboJointCommand :initial-element (cl:make-instance 'hubo_ros_msgs-msg:HuboJointCommand)))
   (num_joints
    :reader num_joints
    :initarg :num_joints
    :type cl:integer
    :initform 0))
)

(cl:defclass HuboTrajectory (<HuboTrajectory>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HuboTrajectory>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HuboTrajectory)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hubo_ros_msgs-msg:<HuboTrajectory> is deprecated: use hubo_ros_msgs-msg:HuboTrajectory instead.")))

(cl:ensure-generic-function 'joints-val :lambda-list '(m))
(cl:defmethod joints-val ((m <HuboTrajectory>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros_msgs-msg:joints-val is deprecated.  Use hubo_ros_msgs-msg:joints instead.")
  (joints m))

(cl:ensure-generic-function 'num_joints-val :lambda-list '(m))
(cl:defmethod num_joints-val ((m <HuboTrajectory>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hubo_ros_msgs-msg:num_joints-val is deprecated.  Use hubo_ros_msgs-msg:num_joints instead.")
  (num_joints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HuboTrajectory>) ostream)
  "Serializes a message object of type '<HuboTrajectory>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'joints))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'joints))
  (cl:let* ((signed (cl:slot-value msg 'num_joints)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HuboTrajectory>) istream)
  "Deserializes a message object of type '<HuboTrajectory>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'joints) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'joints)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'hubo_ros_msgs-msg:HuboJointCommand))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num_joints) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HuboTrajectory>)))
  "Returns string type for a message object of type '<HuboTrajectory>"
  "hubo_ros_msgs/HuboTrajectory")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HuboTrajectory)))
  "Returns string type for a message object of type 'HuboTrajectory"
  "hubo_ros_msgs/HuboTrajectory")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HuboTrajectory>)))
  "Returns md5sum for a message object of type '<HuboTrajectory>"
  "e1b182ddb50fa4986084202886606609")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HuboTrajectory)))
  "Returns md5sum for a message object of type 'HuboTrajectory"
  "e1b182ddb50fa4986084202886606609")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HuboTrajectory>)))
  "Returns full string definition for message of type '<HuboTrajectory>"
  (cl:format cl:nil "HuboJointCommand[] joints~%int32 num_joints~%~%================================================================================~%MSG: hubo_ros_msgs/HuboJointCommand~%string name~%float64 position~%float64 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HuboTrajectory)))
  "Returns full string definition for message of type 'HuboTrajectory"
  (cl:format cl:nil "HuboJointCommand[] joints~%int32 num_joints~%~%================================================================================~%MSG: hubo_ros_msgs/HuboJointCommand~%string name~%float64 position~%float64 velocity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HuboTrajectory>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'joints) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HuboTrajectory>))
  "Converts a ROS message object to a list"
  (cl:list 'HuboTrajectory
    (cl:cons ':joints (joints msg))
    (cl:cons ':num_joints (num_joints msg))
))
