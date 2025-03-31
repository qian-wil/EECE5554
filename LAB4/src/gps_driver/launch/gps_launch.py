from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
  port_arg = DeclareLaunchArgument(
    'gps_port',
    default_value = '/dev/pts/1',
    description = 'Port for GPS'
  )
  
  gps_node = Node(
    package = 'gps_driver',
    executable = 'gps_driver',
    output = 'screen',
    emulate_tty = True,
    parameters=[
      {'gps_port': LaunchConfiguration('gps_port')},
    ],
  )
  
  return LaunchDescription(
    [
      port_arg,
      gps_node,
    ]
  )

