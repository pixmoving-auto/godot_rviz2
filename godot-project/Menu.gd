extends Control

func _ready():
	visible = false

func _input(_event):
	if Input.is_action_just_pressed("ui_select"):
		visible = not visible


# extends Control

# # 声明成员变量
# var bgm_playing = false
# var bgm_player : AudioStreamPlayer

# # 当节点第一次进入场景树时调用
# func _ready():
# 	# 设置按钮初始可见性为false
# 	visible = false
# 	# 获取 AudioStreamPlayer 节点
# 	bgm_player = $AudioStreamPlayer
# 	# 设置 BGM 文件路径
# 	var bgm_path = "res://resource/BGM.wav"
# 	bgm_player.stream = preload(bgm_path)

# # 处理输入事件
# func _input(_event):
# 	# 当按下 "ui_select" 键时切换按钮的可见性
# 	if Input.is_action_just_pressed("ui_select"):
# 		visible = not visible

# 		# 如果按钮可见，播放BGM；否则，停止BGM
# 		if visible:
# 			play_bgm()
# 		else:
# 			stop_bgm()

# # 播放BGM的函数
# func play_bgm():
# 	bgm_player.play()
# 	# 更新标志以指示BGM正在播放
# 	bgm_playing = true

# # 停止BGM的函数
# func stop_bgm():
# 	bgm_player.stop()
# 	# 更新标志以指示BGM未在播放
# 	bgm_playing = false

# # Called every frame. 'delta' is the elapsed time since the previous frame.
# func _process(_delta):
# 	# 如果BGM正在播放，将按钮设置为可见
# 	if bgm_playing:
# 		visible = true
