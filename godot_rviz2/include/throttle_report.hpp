
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <tier4_vehicle_msgs/msg/actuation_status_stamped.hpp>


class ActuationStatus : public Reference 
{
    GDCLASS(ActuationStatus, Reference);
    TOPIC_SUBSCRIBER(ActuationStatus, tier4_vehicle_msgs::msg::ActuationStatusStamped);

public:
    float get_throttle();

    ActuationStatus() = default;
    ~ActuationStatus() = default;

protected:
    static void _bind_methods();
};