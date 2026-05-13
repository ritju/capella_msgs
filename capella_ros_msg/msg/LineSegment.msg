# 沿 MultiCurve 的累计路径起止位置（从曲线原点到本段起止点的距离）
float64 s_start
float64 s_end

# 线段长度（米）
float64 line_length

# 显式 3D 端点（世界坐标系）
geometry_msgs/Point start_point
geometry_msgs/Point end_point
