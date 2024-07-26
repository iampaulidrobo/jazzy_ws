import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
        config = os.path.join(
        get_package_share_directory('minimum_param'),
        'config',
        'test_config_file.yaml'
        )
        return LaunchDescription([
        Node(
            package="minimum_param",
            executable="minimum_param",
            name="custom_minimum_param",
            output="screen",
            emulate_tty=True,
            # parameters=[
            #     {"my_parameter": "earth"}
            # ]
            parameters=[config]
        )
    ])