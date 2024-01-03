#include "string"

#include "brake_report.hpp"  


// 获取油门百分比的方法
void ActuationStatus::_bind_methods()
{
  ClassDB::bind_method(D_METHOD("get_brake"), &ActuationStatus::get_brake);
  TOPIC_SUBSCRIBER_BIND_METHODS(ActuationStatus);
}

float ActuationStatus::get_brake()
{
  const auto last_msg = get_last_msg();
  if (!last_msg) return 0.0;

  return last_msg.value()->status.brake_status;
}