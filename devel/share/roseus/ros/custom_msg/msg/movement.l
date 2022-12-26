;; Auto-generated. Do not edit!


(when (boundp 'custom_msg::movement)
  (if (not (find-package "CUSTOM_MSG"))
    (make-package "CUSTOM_MSG"))
  (shadow 'movement (find-package "CUSTOM_MSG")))
(unless (find-package "CUSTOM_MSG::MOVEMENT")
  (make-package "CUSTOM_MSG::MOVEMENT"))

(in-package "ROS")
;;//! \htmlinclude movement.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass custom_msg::movement
  :super ros::object
  :slots (_angle _distance ))

(defmethod custom_msg::movement
  (:init
   (&key
    ((:angle __angle) (instance std_msgs::Float64 :init))
    ((:distance __distance) (instance std_msgs::Float64 :init))
    )
   (send-super :init)
   (setq _angle __angle)
   (setq _distance __distance)
   self)
  (:angle
   (&rest __angle)
   (if (keywordp (car __angle))
       (send* _angle __angle)
     (progn
       (if __angle (setq _angle (car __angle)))
       _angle)))
  (:distance
   (&rest __distance)
   (if (keywordp (car __distance))
       (send* _distance __distance)
     (progn
       (if __distance (setq _distance (car __distance)))
       _distance)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Float64 _angle
    (send _angle :serialization-length)
    ;; std_msgs/Float64 _distance
    (send _distance :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Float64 _angle
       (send _angle :serialize s)
     ;; std_msgs/Float64 _distance
       (send _distance :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Float64 _angle
     (send _angle :deserialize buf ptr-) (incf ptr- (send _angle :serialization-length))
   ;; std_msgs/Float64 _distance
     (send _distance :deserialize buf ptr-) (incf ptr- (send _distance :serialization-length))
   ;;
   self)
  )

(setf (get custom_msg::movement :md5sum-) "8d9d131ce4cf4580f59de99ac7adc6df")
(setf (get custom_msg::movement :datatype-) "custom_msg/movement")
(setf (get custom_msg::movement :definition-)
      "#Header header
std_msgs/Float64 angle
std_msgs/Float64 distance



================================================================================
MSG: std_msgs/Float64
float64 data
")



(provide :custom_msg/movement "8d9d131ce4cf4580f59de99ac7adc6df")


