extends Sprite

# 在这里声明成员变量。例如：
var is_traffic_light_yellow = false  # 假设黄灯状态初始为假

# 当节点第一次进入场景树时调用。
func _ready():
	# 初始化黄灯状态
	update_traffic_light_visibility()

# 根据黄灯状态更新图标可见性
func update_traffic_light_visibility() -> void:
	if is_traffic_light_yellow:
		visible = true  # 如果黄灯亮，则显示图标
	else:
		visible = false  # 如果黄灯不亮，则隐藏图标

# 模拟获取车辆黄灯信号的函数
func get_traffic_light_state() -> bool:
	# 在实际应用中，这里应该是从车辆系统中获取黄灯状态的逻辑
	# 这里简单地返回一个假值来模拟
	return false

# Called every frame. 'delta' 是自上一帧以来经过的时间。
func _process(delta: float) -> void:
	# 每帧都检查黄灯状态并更新图标可见性
	is_traffic_light_yellow = get_traffic_light_state()
	update_traffic_light_visibility()
