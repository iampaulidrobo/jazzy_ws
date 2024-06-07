cmake_minimum_required(VERSION 3.8)
project(minimum_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
#[=[@(I)push
1)Adding the dependant packages and can be found in ros2 overlay workspace
2)Making our source file into executable and setting up required ament dependencies
3)Storing file executable's to 'install' folder.
]=]

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)
install(DIRECTORY include/
  DESTINATION include
)

add_executable(minimum_pub_node src/minimum_pub.cpp)
ament_target_dependencies(minimum_pub_node rclcpp std_msgs)

add_executable(minimum_sub_node src/minimum_sub.cpp)
ament_target_dependencies(minimum_sub_node rclcpp std_msgs)

install(TARGETS
  minimum_pub_node
  minimum_sub_node

  DESTINATION lib/${PROJECT_NAME})
#!@push

#@(II)push -add a library and link it to the executable
add_library(minimum_pub_main_lib src/minimum_pub_main_lib.cpp)
ament_target_dependencies(minimum_pub_main_lib rclcpp std_msgs)

add_library(minimum_sub_main_lib src/minimum_sub_main_lib.cpp)
ament_target_dependencies(minimum_sub_main_lib rclcpp std_msgs)


install(TARGETS minimum_pub_main_lib
 minimum_sub_main_lib
 
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

add_executable(minimum_pub_main_node src/minimum_pub_main.cpp)
ament_target_dependencies(minimum_pub_main_node rclcpp std_msgs)
target_link_libraries(minimum_pub_main_node minimum_pub_main_lib)

add_executable(minimum_sub_main_node src/minimum_sub_main.cpp)
ament_target_dependencies(minimum_sub_main_node rclcpp std_msgs)
target_link_libraries(minimum_sub_main_node minimum_sub_main_lib
)


install(TARGETS
  minimum_pub_main_node
  # minimum_sub_main_node
  DESTINATION lib/${PROJECT_NAME})
#!@(II)push

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
