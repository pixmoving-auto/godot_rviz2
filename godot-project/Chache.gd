extends ProgressBar

var brake_report = BrakeReport.new()
var brake_scale = 100.0  # 调整刹车值的缩放因子

func _ready():
	brake_report.subscribe("/vehicle/status/brake_status", false)

func _process(_delta):
	if !brake_report.has_new():
		return

	var brake_value = brake_report.get_brake_value()

	# 将刹车值映射到 ProgressBar 的范围 [0, 100]
	var mapped_brake = clamp(brake_value, 0.0, brake_scale)  # 限制刹车值在 [0, brake_scale] 范围内
	# 更新 ProgressBar 的值
	value = mapped_brake

	brake_report.set_old()
