extends Sprite

var battery_report = BmsReportBattery.new()

func _ready():
	battery_report.subscribe("/pix_robobus/bms_report", false)

func _process(_delta):
	if !battery_report.has_new():
		return
	var battery_value = battery_report.get_battery()

	# 更新 ProgressBar 的值
	$ProgressBar.value = battery_value
	battery_report.set_old()

