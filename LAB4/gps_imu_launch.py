# Launches both the GPS and IMU driver simultaneously
# Need to assign ports for each driver

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
  port_arg_gps = DeclareLaunchArgument(
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
  port_arg_imu = DeclareLaunchArgument(
    'imu_port',
    default_value = '/dev/pts/2',
    description = 'Port for IMU'
  )
  
  imu_node = Node(
    package = 'imu_driver',
    executable = 'imu_driver',
    output = 'screen',
    emulate_tty = True,
    parameters=[
      {'imu_port': LaunchConfiguration('imu_port')},
    ],
  )
  
  return LaunchDescription(
    [
      port_arg_gps,
      port_arg_imu,
      gps_node,
      imu_node,
    ]
  )

