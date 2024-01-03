
#pragma once

#include "core/reference.h"
#include "core/ustring.h"
#include "core/variant.h"
#include "topic_subscriber.hpp"

#include <pix_robobus_driver_msgs/msg/vcu_report1.hpp>


class VcuReport1 : public Reference 
{
    GDCLASS(VcuReport1, Reference);
    TOPIC_SUBSCRIBER(VcuReport1, pix_robobus_driver_msgs::msg::VcuReport1);

public:
    int get_battery();

    VcuReport1() = default;
    ~VcuReport1() = default;

protected:
    static void _bind_methods();
};