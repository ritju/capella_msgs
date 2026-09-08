# 消防通道占用结果，qos:默认
builtin_interfaces/Time detect_time # 时间戳
geometry_msgs/Polygon fire_escape_polygon # 消防通道多边形
std_msgs/Bool is_occupied # True: 占用，False: 空闲
sensor_msgs/Image image # 检测到占用返回的图像，未占用返回空