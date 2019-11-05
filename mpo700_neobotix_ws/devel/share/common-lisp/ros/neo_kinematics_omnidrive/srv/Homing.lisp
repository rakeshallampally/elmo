; Auto-generated. Do not edit!


(cl:in-package neo_kinematics_omnidrive-srv)


;//! \htmlinclude Homing-request.msg.html

(cl:defclass <Homing-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Homing-request (<Homing-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Homing-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Homing-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_kinematics_omnidrive-srv:<Homing-request> is deprecated: use neo_kinematics_omnidrive-srv:Homing-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Homing-request>) ostream)
  "Serializes a message object of type '<Homing-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Homing-request>) istream)
  "Deserializes a message object of type '<Homing-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Homing-request>)))
  "Returns string type for a service object of type '<Homing-request>"
  "neo_kinematics_omnidrive/HomingRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Homing-request)))
  "Returns string type for a service object of type 'Homing-request"
  "neo_kinematics_omnidrive/HomingRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Homing-request>)))
  "Returns md5sum for a message object of type '<Homing-request>"
  "5f31cb2e813cfb0e488c574c3b5d9dbe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Homing-request)))
  "Returns md5sum for a message object of type 'Homing-request"
  "5f31cb2e813cfb0e488c574c3b5d9dbe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Homing-request>)))
  "Returns full string definition for message of type '<Homing-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Homing-request)))
  "Returns full string definition for message of type 'Homing-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Homing-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Homing-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Homing-request
))
;//! \htmlinclude Homing-response.msg.html

(cl:defclass <Homing-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type std_msgs-msg:Bool
    :initform (cl:make-instance 'std_msgs-msg:Bool)))
)

(cl:defclass Homing-response (<Homing-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Homing-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Homing-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name neo_kinematics_omnidrive-srv:<Homing-response> is deprecated: use neo_kinematics_omnidrive-srv:Homing-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <Homing-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader neo_kinematics_omnidrive-srv:success-val is deprecated.  Use neo_kinematics_omnidrive-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Homing-response>) ostream)
  "Serializes a message object of type '<Homing-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'success) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Homing-response>) istream)
  "Deserializes a message object of type '<Homing-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'success) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Homing-response>)))
  "Returns string type for a service object of type '<Homing-response>"
  "neo_kinematics_omnidrive/HomingResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Homing-response)))
  "Returns string type for a service object of type 'Homing-response"
  "neo_kinematics_omnidrive/HomingResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Homing-response>)))
  "Returns md5sum for a message object of type '<Homing-response>"
  "5f31cb2e813cfb0e488c574c3b5d9dbe")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Homing-response)))
  "Returns md5sum for a message object of type 'Homing-response"
  "5f31cb2e813cfb0e488c574c3b5d9dbe")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Homing-response>)))
  "Returns full string definition for message of type '<Homing-response>"
  (cl:format cl:nil "std_msgs/Bool success~%~%~%~%================================================================================~%MSG: std_msgs/Bool~%bool data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Homing-response)))
  "Returns full string definition for message of type 'Homing-response"
  (cl:format cl:nil "std_msgs/Bool success~%~%~%~%================================================================================~%MSG: std_msgs/Bool~%bool data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Homing-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'success))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Homing-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Homing-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Homing)))
  'Homing-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Homing)))
  'Homing-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Homing)))
  "Returns string type for a service object of type '<Homing>"
  "neo_kinematics_omnidrive/Homing")