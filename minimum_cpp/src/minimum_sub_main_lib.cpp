#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "minimum_cpp/minimum_sub_main.hpp"

using std::placeholders::_1;

MainSub::MainSub()
    : Node("main_sub")
{
  subscription_ =
      this->create_subscription<std_msgs::msg::String>("main_topic", 10, std::bind(&MainSub::topic_callback, this, _1));
}
void MainSub::topic_callback(std_msgs::msg::String::UniquePtr msg)
{

  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}
