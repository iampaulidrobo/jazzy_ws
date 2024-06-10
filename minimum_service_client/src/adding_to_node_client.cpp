#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "minimum_srv/srv/add_three_ints.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher()
        : Node("adding_to_node_client"), count_(0)
    {
        client=this->create_client<minimum_srv::srv::AddThreeInts>("add_three_ints");

        publisher_ = this->create_publisher<std_msgs::msg::String>("advance_fibo", 10);

        auto timer_callback =
            [this]() -> void
        {
            auto message = std_msgs::msg::String();
            message.data = "Check for count: " + std::to_string(count_++);
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            this->publisher_->publish(message);
            thread_.push_back(std::thread(std::bind(&MinimalPublisher::callClient, this, count_)));
        };
        
        timer_ = this->create_wall_timer(2000ms, timer_callback);
    }
    void callClient(int count_)
    {
        
        auto request = std::make_shared<minimum_srv::srv::AddThreeInts::Request>();
        request->a = count_;
        request->b = count_ + 1;
        request->c = count_ + 2;
        while (!client->wait_for_service(1s))
        {
            // // if (!rclcpp::ok())
            // {
            //     RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            // // }
             RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        }
        auto result = client->async_send_request(request);
        
        try
        {
            auto response = result.get();
            RCLCPP_INFO(this->get_logger(), "%d + %d + %d =%ld", request->a, request->b, request->c, response->sum);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Error");
        }
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

    rclcpp::Client<minimum_srv::srv::AddThreeInts>::SharedPtr client;
   std::vector<std::thread> thread_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}