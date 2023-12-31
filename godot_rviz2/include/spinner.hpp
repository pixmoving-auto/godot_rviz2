//
//  Copyright 2022 Yukihiro Saito. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#pragma once
#include "core/reference.h"
#include "godot_rviz2.hpp"
#include "rclcpp/rclcpp.hpp"

class GodotRviz2Spinner : public Reference
{
  GDCLASS(GodotRviz2Spinner, Reference);

public:
  GodotRviz2Spinner(){};
  ~GodotRviz2Spinner(){};
  inline void spin_some() { rclcpp::spin_some(GodotRviz2::get_instance().get_node()); }

protected:
  static void _bind_methods();
};
