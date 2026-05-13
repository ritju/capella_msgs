uint8 LINE=0
uint8 ELLIPSE_ARC=1

uint8 type

# 是否为延伸段（true=预测/延伸部分，非实际点云检测结果）
bool is_virtual

LineSegment line_segment
EllipseArcSegment ellipse_arc_segment
