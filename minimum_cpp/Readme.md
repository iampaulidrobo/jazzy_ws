@push-defines the changes done as well as implementation of the commands
!@push

The package consists of four nodes -2 publisher and 2 subcriber .
The pair approaches different ways to develop them in rospackage- with and without header.
Commands to run each pair.

In terminal-1
ros2 run minimum_cpp minimum_pub_main_node 
In terminal-2
ros2 run minimum_cpp minimum_sub_main_node 



In terminal-1
ros2 run minimum_cpp minimum_pub_node 
In terminal-2
ros2 run minimum_cpp minimum_sub_node 