
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <autoware_auto_vehicle_msgs/msg/gear_report.hpp>


class GearReport : public Reference 
{
    GDCLASS(GearReport, Reference);
    TOPIC_SUBSCRIBER(GearReport, autoware_auto_vehicle_msgs::msg::GearReport);

public:
    int get_gear();

    GearReport() = default;
    ~GearReport() = default;

protected:
    static void _bind_methods();
};