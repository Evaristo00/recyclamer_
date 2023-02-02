
(cl:in-package :asdf)

(defsystem "custom_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "movement" :depends-on ("_package_movement"))
    (:file "_package_movement" :depends-on ("_package"))
  ))