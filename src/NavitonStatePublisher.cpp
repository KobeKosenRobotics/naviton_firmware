#include "NavitonStatePublisher.h"

NavitonStatePublisher::NavitonStatePublisher() : 
    _publisher()
{
}

NavitonStatePublisher::NavitonStatePublisher(const char *topic_name) : 
    _publisher(topic_name, 9)
{
}

void NavitonStatePublisher::Init(ros::NodeHandle& nh)
{
    _publisher.Init(nh);
}

void NavitonStatePublisher::Publish()
{
    _publisher.Publish();
}

void NavitonStatePublisher::SetPosition(double x, double y, double z)
{
    _publisher.array.data[0] = x;
    _publisher.array.data[1] = y;
    _publisher.array.data[2] = z;
}

void NavitonStatePublisher::SetRotation(double w, double x, double y, double z)
{
    _publisher.array.data[3] = w;
    _publisher.array.data[4] = x;
    _publisher.array.data[5] = y;
    _publisher.array.data[6] = z;
}

void NavitonStatePublisher::SetWheelVelocity(double left, double right)
{
    _publisher.array.data[7] = left;
    _publisher.array.data[8] = right;
}
