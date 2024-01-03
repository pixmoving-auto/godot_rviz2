
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <tier4_vehicle_msgs/msg/actuation_status_stamped.hpp>


class ActuationStatusBrake : public Reference 
{
    GDCLASS(ActuationStatusBrake, Reference);
    TOPIC_SUBSCRIBER(ActuationStatusBrake, tier4_vehicle_msgs::msg::ActuationStatusStamped);

public:
    float get_brake();

    ActuationStatusBrake() = default;
    ~ActuationStatusBrake() = default;

protected:
    static void _bind_methods();
};