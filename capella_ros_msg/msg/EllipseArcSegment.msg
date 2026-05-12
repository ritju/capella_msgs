# 参考位姿（定义椭圆弧所在平面及中心位置）
geometry_msgs/Pose frame

# 弧长起止位置（局部坐标系）
float64 s_start
float64 s_end

# 椭圆半长轴（米）
float64 a
# 椭圆半短轴（米）
float64 b

# 起止角度（弧度，相对于椭圆局部坐标系 X 轴）
float64 theta_start
float64 theta_end

# 显式 3D 端点（世界坐标系）
geometry_msgs/Point start_point
geometry_msgs/Point end_point
