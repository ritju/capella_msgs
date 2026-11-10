# 前轮转向 + 后桥驱动实际状态
# 坐标系：x 前、y 左、z 上

std_msgs/Header header
float32 linear_x             # 后桥中心线速度，m/s，前进为正
float32 front_steer_angle    # 前轮转角（经过减速器的最终输出），rad，左转为正
float32 front_wheel_speed    # 前轮转速（经过减速器的最终输出），rpm，绕z正向为正
