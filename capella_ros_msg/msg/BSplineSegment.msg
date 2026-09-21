# 沿 MultiCurve 的累计路径起止位置（从曲线原点到本段起止点的距离）
float32 s_start
float32 s_end

# B样条控制点
geometry_msgs/Point[] control_points

# B样条阶数（degree + 1）
uint32 order

# 节点向量
float32[] knot_vector

# 显式 3D 端点（世界坐标系）
geometry_msgs/Point start_point
geometry_msgs/Point end_point
