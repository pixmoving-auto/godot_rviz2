extends Sprite

# 在这里声明成员变量。例如：
var is_traffic_light_green = true  # 假设绿灯状态初始为真

# 当节点第一次进入场景树时调用。
func _ready():
	# 初始化绿灯状态
	update_traffic_light_visibility()

# 根据绿灯状态更新图标可见性
func update_traffic_light_visibility() -> void:
	if is_traffic_light_green:
		visible = true  # 如果绿灯亮，则显示图标
	else:
		visible = false  # 如果绿灯不亮，则隐藏图标

# 模拟获取车辆绿灯信号的函数
func get_traffic_light_state() -> bool:
	# 在实际应用中，这里应该是从车辆系统中获取绿灯状态的逻辑
	# 这里简单地返回一个假值来模拟
	return false

# Called every frame. 'delta' 是自上一帧以来经过的时间。
func _process(delta: float) -> void:
	# 每帧都检查绿灯状态并更新图标可见性
	is_traffic_light_green = get_traffic_light_state()
	update_traffic_light_visibility()
