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

#include "dynamic_objects.hpp"

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <string>
#define EIGEN_MPL2_ONLY
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

using Label = autoware_auto_perception_msgs::msg::ObjectClassification;

void DynamicObjects::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_triangle_points"), &DynamicObjects::get_triangle_points);
  TOPIC_SUBSCRIBER_BIND_METHODS(DynamicObjects);
}

PoolVector3Array DynamicObjects::get_triangle_points(bool only_known_objects)
{
  PoolVector3Array triangle_points;
  const auto last_msg = get_last_msg();
  if (!last_msg) return triangle_points;

  for (const auto & object : last_msg.value()->objects) {
    if (only_known_objects && object.classification.front().label == Label::UNKNOWN) continue;
    const auto & pose = object.kinematics.initial_pose_with_covariance.pose;
    const auto & shape = object.shape;
    const auto z_offset = shape.dimensions.z * 0.5;
    geometry_msgs::msg::Polygon polygon;
    to_polygon2d(pose, shape, polygon);
    if (polygon.points.empty()) return triangle_points;

    // upper
    for (size_t i = 2; i < polygon.points.size(); ++i) {
      triangle_points.append(Vector3(
        polygon.points.at(0).x, polygon.points.at(0).z + z_offset, -polygon.points.at(0).y));
      triangle_points.append(Vector3(
        polygon.points.at(i - 1).x, polygon.points.at(i - 1).z + z_offset,
        -polygon.points.at(i - 1).y));
      triangle_points.append(Vector3(
        polygon.points.at(i).x, polygon.points.at(i).z + z_offset, -polygon.points.at(i).y));
    }
    // lower
    for (size_t i = 2; i < polygon.points.size(); ++i) {
      triangle_points.append(Vector3(
        polygon.points.at(0).x, polygon.points.at(0).z - z_offset, -polygon.points.at(0).y));
      triangle_points.append(Vector3(
        polygon.points.at(i).x, polygon.points.at(i).z - z_offset, -polygon.points.at(i).y));
      triangle_points.append(Vector3(
        polygon.points.at(i - 1).x, polygon.points.at(i - 1).z - z_offset,
        -polygon.points.at(i - 1).y));
    }
    // side
    for (size_t i = 1; i <= polygon.points.size(); ++i) {
      size_t j = (i == polygon.points.size()) ? 0 : i;
      triangle_points.append(Vector3(
        polygon.points.at(i - 1).x, polygon.points.at(i - 1).z + z_offset,
        -polygon.points.at(i - 1).y));
      triangle_points.append(Vector3(
        polygon.points.at(i - 1).x, polygon.points.at(i - 1).z - z_offset,
        -polygon.points.at(i - 1).y));
      triangle_points.append(Vector3(
        polygon.points.at(j).x, polygon.points.at(j).z + z_offset, -polygon.points.at(j).y));
      triangle_points.append(Vector3(
        polygon.points.at(i - 1).x, polygon.points.at(i - 1).z - z_offset,
        -polygon.points.at(i - 1).y));
      triangle_points.append(Vector3(
        polygon.points.at(j).x, polygon.points.at(j).z - z_offset, -polygon.points.at(j).y));
      triangle_points.append(Vector3(
        polygon.points.at(j).x, polygon.points.at(j).z + z_offset, -polygon.points.at(j).y));
    }
  }

  return triangle_points;
}
