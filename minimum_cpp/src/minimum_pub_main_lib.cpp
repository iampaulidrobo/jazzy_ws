#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "minimum_cpp/minimum_pub_main.hpp"

using namespace std::chrono_literals;

MainPub::MainPub()
    : Node("main_pub"), count_(0)
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("main_topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&MainPub::timer_callback, this));
}
void MainPub::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(this->count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    this->publisher_->publish(message);
}
