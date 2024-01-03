extends Sprite

var battery_report = ActuationStatus.new()
var battery_scale = -1  # 调整刹车值

func _ready():
	battery_report.subscribe("/pix_robobus/vcu_report1", false)

func _process(_delta):
	if !battery_report.has_new():
		return
	var battery_value = battery_report.get_battery()

	# 将刹车值映射到 ProgressBar 的范围 [0, 100],限制刹车值在 [0, battery_scale] 范围内
	var mapped_brake = clamp(battery_value, 0.0, battery_scale)
	
	# 更新 ProgressBar 的值
	$ProgressBar.value = mapped_brake * battery_scale
	battery_report.set_old()

