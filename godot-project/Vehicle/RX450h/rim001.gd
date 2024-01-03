extends Spatial

# 旋转速度
var rotation_speed = 5.0

func _process(delta):
	# 计算旋转角度
	var rotation_delta = Vector3(0, rotation_speed * delta, 0)
	
	# 提供旋转轴（Y轴），以及旋转角度
	rotate(Vector3(0, 1, 0), rotation_delta)
