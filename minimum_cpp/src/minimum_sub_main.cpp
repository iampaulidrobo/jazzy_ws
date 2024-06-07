#include "rclcpp/rclcpp.hpp"
#include "minimum_cpp/minimum_sub_main.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MainSub>());
  rclcpp::shutdown();
  return 0;
}