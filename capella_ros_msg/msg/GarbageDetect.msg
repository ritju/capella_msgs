# 垃圾相对机器人的位姿
geometry_msgs/PoseStamped pose

# 湿垃圾
uint8 WET_GARBAGE=1

# 干垃圾
uint8 DRY_GARBAGE=2

# 垃圾类别，用于开关清洁工具
int8 class_id

# 垃圾的边界框角点
geometry_msgs/Point[] bbox_corner_points

# 树叶
uint8 LEAFS=2

# 污水
uint8 SEWAGE=3

# 纸巾
uint8 TISSUSE=4

# 垃圾序号，用于上报统计
int8 class_code