 @push-defines the changes done as well as implementation of the commands
!@push


In terminal-1
 ros2 run minimum_param minimum_param 
In terminal-2

 ros2 param set /minimal_param_node my_parameter earth


In terminal-1
 ros2 launch minimum_param minimum_param_launch.py 
We have changed our name in launch file
In terminal-2

 ros2 param set /custom_minimum_param my_parameter earth



