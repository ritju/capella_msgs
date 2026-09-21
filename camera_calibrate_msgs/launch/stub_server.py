from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='camera_calibrate_msgs',
            executable='stub_server',
            name='stub_server',
            output='screen'
        ),
    ])