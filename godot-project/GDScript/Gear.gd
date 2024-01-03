extends Sprite

var gear_report = GearReport.new()

func _ready():
	gear_report.subscribe("/vehicle/status/gear_status", false)


func _process(_delta):
	if !gear_report.has_new():
		print("No new data.")
		return

	var current_gear = gear_report.get_gear()
	print("Current gear:", current_gear)

	# 根据订阅到的档位值进行映射
	var gear_text = match_gear(current_gear)
	print("Mapped gear text:", gear_text)


	# 将当前档位显示在 GearLabel 上
	$GearLabel.text = gear_text

	gear_report.set_old()

# 根据档位值进行映射
func match_gear(gear_value):
	match gear_value:
		0: return "NONE"
		1: return "N"	# "NEUTRAL"
		2: return "D"	# "DRIVE"
		20: return "R"  # "REVERSE"
		22: return "P"	# "PARK"
		# 如果有其他值，可以在这里继续添加映射关系
		_: return "UNKNOWN"
