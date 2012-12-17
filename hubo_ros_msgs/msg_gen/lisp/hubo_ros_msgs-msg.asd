
(cl:in-package :asdf)

(defsystem "hubo_ros_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
<<<<<<< HEAD
    (:file "HuboIMU" :depends-on ("_package_HuboIMU"))
    (:file "_package_HuboIMU" :depends-on ("_package"))
    (:file "HuboFT" :depends-on ("_package_HuboFT"))
    (:file "_package_HuboFT" :depends-on ("_package"))
    (:file "HuboJointCommand" :depends-on ("_package_HuboJointCommand"))
    (:file "_package_HuboJointCommand" :depends-on ("_package"))
    (:file "HuboJointState" :depends-on ("_package_HuboJointState"))
    (:file "_package_HuboJointState" :depends-on ("_package"))
    (:file "HuboState" :depends-on ("_package_HuboState"))
    (:file "_package_HuboState" :depends-on ("_package"))
    (:file "HuboTrajectory" :depends-on ("_package_HuboTrajectory"))
    (:file "_package_HuboTrajectory" :depends-on ("_package"))
=======
    (:file "HuboJointCommand" :depends-on ("_package_HuboJointCommand"))
    (:file "_package_HuboJointCommand" :depends-on ("_package"))
    (:file "HuboFT" :depends-on ("_package_HuboFT"))
    (:file "_package_HuboFT" :depends-on ("_package"))
    (:file "HuboTrajectory" :depends-on ("_package_HuboTrajectory"))
    (:file "_package_HuboTrajectory" :depends-on ("_package"))
    (:file "HuboJointState" :depends-on ("_package_HuboJointState"))
    (:file "_package_HuboJointState" :depends-on ("_package"))
    (:file "HuboIMU" :depends-on ("_package_HuboIMU"))
    (:file "_package_HuboIMU" :depends-on ("_package"))
    (:file "HuboState" :depends-on ("_package_HuboState"))
    (:file "_package_HuboState" :depends-on ("_package"))
>>>>>>> 29eae297f826d1ce243bfc2d289c4cb3ac119701
  ))