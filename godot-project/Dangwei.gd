extends Label

var gear_report = GearReport.new()

func _ready():
	gear_report.subscribe("/vehicle/status/gear_status", false)

func _process(_delta):
	if !gear_report.has_new():
		return

	var current_gear = gear_report.get_current_gear()

	# 将当前档位显示在 Label 上
	text = "Gear: " + str(current_gear)

	gear_report.set_old()
