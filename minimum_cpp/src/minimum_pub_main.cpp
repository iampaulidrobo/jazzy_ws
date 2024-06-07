#include "rclcpp/rclcpp.hpp"
#include "minimum_cpp/minimum_pub_main.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MainPub>());
  rclcpp::shutdown();
  return 0;
}