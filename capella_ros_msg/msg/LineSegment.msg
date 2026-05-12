# 参考位姿（定义线段所在平面及起点位置）
geometry_msgs/Pose frame

# 弧长起止位置（局部坐标系）
float64 s_start
float64 s_end

# 线段长度（米）
float64 line_length

# 显式 3D 端点（世界坐标系）
geometry_msgs/Point start_point
geometry_msgs/Point end_point
