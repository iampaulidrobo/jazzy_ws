#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


class MainSub: public rclcpp::Node
{
private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  void topic_callback(std_msgs::msg::String::UniquePtr msg);

public:
    MainSub();
    
};

