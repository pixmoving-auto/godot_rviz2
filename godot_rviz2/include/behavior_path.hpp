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
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include "autoware_auto_planning_msgs/msg/path.hpp"

class BehaviorPath : public Reference
{
  GDCLASS(BehaviorPath, Reference);
  TOPIC_SUBSCRIBER(BehaviorPath, autoware_auto_planning_msgs::msg::Path);

public:
  Array get_triangle_strip_with_velocity(const float width);
  Array get_drivable_area_triangle_strips(const float width);

  BehaviorPath() = default;
  ~BehaviorPath() = default;

protected:
  static void _bind_methods();
};
