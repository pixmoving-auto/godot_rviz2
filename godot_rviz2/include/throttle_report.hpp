
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <tier4_vehicle_msgs/msg/actuation_status_stamped.hpp>


class ActuationStatusThrottle : public Reference 
{
    GDCLASS(ActuationStatusThrottle, Reference);
    TOPIC_SUBSCRIBER(ActuationStatusThrottle, tier4_vehicle_msgs::msg::ActuationStatusStamped);

public:
    float get_throttle();

    ActuationStatusThrottle() = default;
    ~ActuationStatusThrottle() = default;

protected:
    static void _bind_methods();
};