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
/// @tparam Publishする配列の型 
template<typename T>
class RosArrayPublisher
{
    public:
        /// @brief 空コンストラクラ
        RosArrayPublisher();

        /// @brief コンストラクタ
        /// @param nh rosのノードハンドル
        /// @param topic_name publishするtopic名
        /// @param array_size publishする配列の要素数
        RosArrayPublisher(ros::NodeHandle& nh,const char *topic_name,int array_size);

        /// @brief publishする関数
        void Publish();

        /// @brief publishするデータを入れるオブジェクト array.data[1]のようにアクセスする
        T array;

    private:
        ros::Publisher _array_pub;
};

#endif