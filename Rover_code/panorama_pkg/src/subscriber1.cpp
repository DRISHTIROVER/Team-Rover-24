#include <ros/ros.h>
#include <sensor_msgs/Image.h>

void imageRightRectifiedCallback(const sensor_msgs::Image::ConstPtr &msg)
{
    ROS_INFO("Right Rectified image received from ZED - Size: %dx%d", msg->width, msg->height);
}

void imageLeftRectifiedCallback(const sensor_msgs::Image::ConstPtr &msg)
{
    ROS_INFO("Left Rectified image received from ZED - Size: %dx%d", msg->width, msg->height);
}

/**
 * Node main function
 */
int main(int argc, char **argv)
{

    // Node initialization
    ros::init(argc, argv, "frame_listener");
    ros::NodeHandle n;

    // Subscribers
    ros::Subscriber subRightRectified = n.subscribe("/camera/image_raw", 10, imageRightRectifiedCallback);
    ros::Subscriber subLeftRectified = n.subscribe("/camera/image_raw", 10, imageLeftRectifiedCallback);

    // Node execution
    ros::spin();

    return 0;
}