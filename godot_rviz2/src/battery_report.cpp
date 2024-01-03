#include "string"
#include "battery_report.hpp"

void VcuReport1::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("get_battery"), &VcuReport1::get_battery);
    TOPIC_SUBSCRIBER_BIND_METHODS(VcuReport1);
}

int VcuReport1::get_battery() 
{
    const auto last_msg = get_last_msg();
    if (!last_msg) return 0;  // Modify this accordingly based on your message structure

    // Access the gear information from the message and return it
    return last_msg.value()->car_power_state;  // Update this line based on the actual field name in your message
}