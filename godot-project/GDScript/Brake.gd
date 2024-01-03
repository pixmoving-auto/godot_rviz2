extends Sprite

var brake_report = ActuationStatus.new()
var brake_scale = -1  # 调整刹车值

func _ready():
	brake_report.subscribe("/vehicle/status/actuation_status", false)

func _process(_delta):
	if !brake_report.has_new():
		return
	var brake_value = brake_report.get_brake()

	# 将刹车值映射到 ProgressBar 的范围 [0, 100],限制刹车值在 [0, brake_scale] 范围内
	var mapped_brake = clamp(brake_value, 0.0, brake_scale)
	
	# 更新 ProgressBar 的值
	$ProgressBar.value = mapped_brake * brake_scale
	brake_report.set_old()

