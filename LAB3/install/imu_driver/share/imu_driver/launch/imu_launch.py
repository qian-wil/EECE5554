from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
  port_arg = DeclareLaunchArgument(
    'port',
    default_value = '/dev/pts/6/',
    description = 'Port for IMU'
  )
  
  imu_node = Node(
    package = 'imu_driver',
    executable = 'imu_driver',
    output = 'screen',
    emulate_tty = True,
    parameters=[
      {'port': LaunchConfiguration('port')},
    ],
  )
  
  return LaunchDescription(
    [
      port_arg,
      imu_node,
    ]
  )

