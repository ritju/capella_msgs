# 前轮转向 + 后桥驱动控制指令
# 坐标系：x 前、y 左、z 上

float32 linear_x             # 后桥中心线速度，m/s，前进为正
float32 front_steer_angle    # 前轮转角（经过减速器的最终输出），rad，左转为正