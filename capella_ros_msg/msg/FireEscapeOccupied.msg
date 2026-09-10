# 消防通道占用结果，qos:默认
builtin_interfaces/Time detect_time # 时间戳
string uuid                         # 消防通道 id
std_msgs/Bool is_occupied           # True: 占用，False: 空闲
sensor_msgs/Image image             # 消防通道图像