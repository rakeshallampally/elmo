;; Auto-generated. Do not edit!


(when (boundp 'neo_kinematics_omnidrive::Homing)
  (if (not (find-package "NEO_KINEMATICS_OMNIDRIVE"))
    (make-package "NEO_KINEMATICS_OMNIDRIVE"))
  (shadow 'Homing (find-package "NEO_KINEMATICS_OMNIDRIVE")))
(unless (find-package "NEO_KINEMATICS_OMNIDRIVE::HOMING")
  (make-package "NEO_KINEMATICS_OMNIDRIVE::HOMING"))
(unless (find-package "NEO_KINEMATICS_OMNIDRIVE::HOMINGREQUEST")
  (make-package "NEO_KINEMATICS_OMNIDRIVE::HOMINGREQUEST"))
(unless (find-package "NEO_KINEMATICS_OMNIDRIVE::HOMINGRESPONSE")
  (make-package "NEO_KINEMATICS_OMNIDRIVE::HOMINGRESPONSE"))

(in-package "ROS")



(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass neo_kinematics_omnidrive::HomingRequest
  :super ros::object
  :slots ())

(defmethod neo_kinematics_omnidrive::HomingRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass neo_kinematics_omnidrive::HomingResponse
  :super ros::object
  :slots (_success ))

(defmethod neo_kinematics_omnidrive::HomingResponse
  (:init
   (&key
    ((:success __success) (instance std_msgs::Bool :init))
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&rest __success)
   (if (keywordp (car __success))
       (send* _success __success)
     (progn
       (if __success (setq _success (car __success)))
       _success)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Bool _success
    (send _success :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Bool _success
       (send _success :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Bool _success
     (send _success :deserialize buf ptr-) (incf ptr- (send _success :serialization-length))
   ;;
   self)
  )

(defclass neo_kinematics_omnidrive::Homing
  :super ros::object
  :slots ())

(setf (get neo_kinematics_omnidrive::Homing :md5sum-) "5f31cb2e813cfb0e488c574c3b5d9dbe")
(setf (get neo_kinematics_omnidrive::Homing :datatype-) "neo_kinematics_omnidrive/Homing")
(setf (get neo_kinematics_omnidrive::Homing :request) neo_kinematics_omnidrive::HomingRequest)
(setf (get neo_kinematics_omnidrive::Homing :response) neo_kinematics_omnidrive::HomingResponse)

(defmethod neo_kinematics_omnidrive::HomingRequest
  (:response () (instance neo_kinematics_omnidrive::HomingResponse :init)))

(setf (get neo_kinematics_omnidrive::HomingRequest :md5sum-) "5f31cb2e813cfb0e488c574c3b5d9dbe")
(setf (get neo_kinematics_omnidrive::HomingRequest :datatype-) "neo_kinematics_omnidrive/HomingRequest")
(setf (get neo_kinematics_omnidrive::HomingRequest :definition-)
      "---
std_msgs/Bool success



================================================================================
MSG: std_msgs/Bool
")

(setf (get neo_kinematics_omnidrive::HomingResponse :md5sum-) "5f31cb2e813cfb0e488c574c3b5d9dbe")
(setf (get neo_kinematics_omnidrive::HomingResponse :datatype-) "neo_kinematics_omnidrive/HomingResponse")
(setf (get neo_kinematics_omnidrive::HomingResponse :definition-)
      "---
std_msgs/Bool success



================================================================================
MSG: std_msgs/Bool
")



(provide :neo_kinematics_omnidrive/Homing "5f31cb2e813cfb0e488c574c3b5d9dbe")


