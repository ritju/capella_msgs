# 汽车相对map坐标系的位姿
geometry_msgs/PoseStamped pose  #pose.pose.position.z的值: 100.0表示前摄像头看见车， 200.0表示后摄像头看见车

# 汽车的长,宽
geometry_msgs/Vector3 size

# 汽车相对base_link的速度
geometry_msgs/TwistStamped speed
