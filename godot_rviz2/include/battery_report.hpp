
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <pix_robobus_driver_msgs/msg/bms_report.hpp>


class BmsReportBattery : public Reference 
{
    GDCLASS(BmsReportBattery, Reference);
    TOPIC_SUBSCRIBER(BmsReportBattery, pix_robobus_driver_msgs::msg::BmsReport);

public:
    int get_battery();

    BmsReportBattery() = default;
    ~BmsReportBattery() = default;

protected:
    static void _bind_methods();
};