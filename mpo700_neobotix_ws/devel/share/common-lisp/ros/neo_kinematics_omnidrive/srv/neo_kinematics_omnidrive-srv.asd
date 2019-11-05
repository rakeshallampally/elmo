
(cl:in-package :asdf)

(defsystem "neo_kinematics_omnidrive-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Homing" :depends-on ("_package_Homing"))
    (:file "_package_Homing" :depends-on ("_package"))
  ))