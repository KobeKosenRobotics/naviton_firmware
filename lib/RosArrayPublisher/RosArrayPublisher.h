/// @file RosArrayPublisher.h
/// @brief MultiArray publisher using rosserial
/// @date 2020.10.31
/// @author Shunya Hara

#ifndef ROS_ARRAY_PUBLISHER_H
#define ROS_ARRAY_PUBLISHER_H
#include <ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Int32MultiArray.h>

/// @brief 
/// @param Publishする配列の型 
template<typename T>
class RosArrayPublisher
{
    public:
        /// @brief 空コンストラクラ
        RosArrayPublisher() : _array_pub("", &array)
        {
        }

        /// @brief コンストラクタ
        /// @param nh rosのノードハンドル
        /// @param topic_name publishするtopic名
        /// @param array_size publishする配列の要素数
        RosArrayPublisher(const char *topic_name, int array_size) :
        _array_pub(topic_name, &array)
        {
            array.data = decltype(array.data)(malloc(sizeof(array.data) * array_size));
            array.data_length = array_size;
            for(int i = 0; i < array_size; i++)
            {
                array.data[i] = 0.0;
            }
        }

        /// @brief advertiseする関数
        void Init(ros::NodeHandle& nh)
        {
            nh.advertise(_array_pub);
        }

        /// @brief publishする関数
        void Publish()
        {
            _array_pub.publish(&array);
        }

        /// @brief publishするデータを入れるオブジェクト array.data[1]のようにアクセスする
        T array;

    private:
        ros::Publisher _array_pub;
};

#endif