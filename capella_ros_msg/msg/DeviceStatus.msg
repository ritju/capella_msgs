uint16 left_motor_stu  #左侧电机状态 0x0000h:无错误;0x0001h:过压;0x0002h:欠压;0x0004h:过流;0x0008h:过载;0x0010h:电流超差;0x0020h:编码器超差;0x0040h:速度超差;
                       #0x0080h:参考电压出错;0x0100h:EEPROM读写错误;0x0200h:霍尔出错;0x0400h:电机温度过高
uint16 right_motor_stu #右侧电机状态
uint8  emer_stop_stu   #急停按钮开关状态:0x00:未按下急停开关;0x01:按下急停开关
uint8  inverter_stu    #逆变器的开启状态:0x00:逆变器未上电;0x01:逆变器已上电
uint8 vacuum_cleaner_stu #扫地模式开关状态:0x00:扫地模式停止工作;0x01:扫地模式开始工作
uint8 roll_cleaner_stu #洗地模式滚刷开关状态:0x00:洗地滚刷停止工作;0x01:洗地滚刷开始工作
uint8 suct_water_cleaner_stu #吸污水泵开关状态：0x00:吸污水停止工作;0x01:吸污水开始工作
bool drainage_water_stu #排污水工作状态：false是未排污水，true是正在排污水
uint8 add_water_stu #加水工作状态：0x00：未加水，0x01:自动加水，0x02:手动加水
uint8 pilot_lamp_stu #指示灯运行状态，0x00：关闭指示灯，0x01:红灯亮，0x02:绿灯亮，0x03:黄灯亮
uint8 wash_cleaner_stu #洗地模式开关状态:0x00:洗地模式停止工作;0x01:洗地模式开始工作
bool charging_stu #充电状态，false是未充电，true是正在充电
int16 charging_current #电池的充放电电流，带符号型16进制数，充电为正，放电为负，单位：10mA
float32 clean_water_tank_level #净水箱水位，取值范围为[0.0, 1.0]。0表示水箱为空，1表示水箱已满。
float32 wastewater_tank_level #污水箱水位，取值范围为[0.0, 1.0]。0表示水箱为空，1表示水箱已满。
bool garbage_full_stu #垃圾箱装满状态，false是未装满，true是装满
float32 detergent_level #洗涤剂液位，取值范围为[0.0, 1.0]。0表示水箱为空，1表示水箱已满。
bool clear_water_stu #清水箱工作状态： false是未放清水，true是正在放清水
uint8 turn_led_stu #转向灯状态：0x00：转向灯全灭 0x01：左转灯亮 0x02:右转灯亮 0x03：双闪灯亮
bool side_motor_run_stu #边刷电机工作状态： false是未运行，true是正在运行
bool fill_light_run_stu #补光灯运行状态： false是未运行，true是正在运行
bool device_motor_enable_stu #驱动轮电机使能状态：false是失能状态，true是使能状态

#驱动轮电机命令状态：0x00:无命令，0x01:配置使能，0x02:配置失能，0x03：清楚故障，0x04:设置速度，0x05:驻车配置
uint8 device_motor_set_cmd_flag 
