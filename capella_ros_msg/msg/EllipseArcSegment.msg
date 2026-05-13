# 参考位姿（Z轴为椭圆平面法向量，X轴对齐长轴方向，Y轴对齐短轴方向）
geometry_msgs/Pose frame

# 沿 MultiCurve 的累计路径起止位置（从曲线原点到本段起止点的距离）
float64 s_start
float64 s_end

# 椭圆半长轴（米）
float64 a
# 椭圆半短轴（米）
float64 b

# 起止角度（弧度，相对于椭圆局部坐标系 X 轴）
float64 theta_start
float64 theta_end

# 凹凸性（true=凸，false=凹，相对于局部地面坐标系的 Z 轴法向）
bool is_convex

# 圆弧方向（true=逆时针，false=顺时针，相对于局部地面坐标系的 Z 轴）
bool is_ccw

# 显式 3D 端点（世界坐标系）
geometry_msgs/Point start_point
geometry_msgs/Point end_point
