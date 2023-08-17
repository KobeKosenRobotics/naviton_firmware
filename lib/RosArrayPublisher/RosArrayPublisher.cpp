#include "RosArrayPublisher.h"

template<typename T>
RosArrayPublisher<T>::RosArrayPublisher()
{

}

template<typename T>
RosArrayPublisher<T>::RosArrayPublisher(ros::NodeHandle& nh, const char *topic_name, int array_size) :
    _array_pub(topic_name, &array)
{
    array.data=decltype(array.data)(malloc(sizeof (array.data)*array_size));
    array.data_length=array_size;
    for(int i=0;i<array_size;i++){
        array.data[i]=0.0;
    }
    nh.advertise(_array_pub);
}

template<typename T>
void RosArrayPublisher<T>::Publish()
{
    _array_pub.publish(&array);
}