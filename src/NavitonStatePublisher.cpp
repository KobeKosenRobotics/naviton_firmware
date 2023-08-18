#include "NavitonStatePublisher.h"

NavitonStatePublisher::NavitonStatePublisher()
{

}

void NavitonStatePublisher::Publish()
{
    _publisher.Publish();
}