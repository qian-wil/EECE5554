import rclpy
import serial
from rclpy.node import Node
from rclpy.parameter import Parameter
from imu_interface.msg import IMUmsg
import numpy as np
import math
import time

# Global variables
global baud_rate
baud_rate = 115200

class IMU_Driver(Node):
  def __init__(self):
    super().__init__('imu_driver')
    self.publisher_ = self.create_publisher(IMUmsg, 'imu', 10)
    timer_period = 0.025 # seconds to read the IMU data from serial port
    self.timer = self.create_timer(timer_period, self.timer_callback)
    
    #Declares the parameters set in the launch file
    self.declare_parameters(namespace = '', parameters=[('imu_port', '/dev/ttyUSB0'),])
    
    #Set and open the port for the IMU
    self.port1 = self.get_parameter('imu_port').value
    try:
      print("Opening the IMU on serial port: " + self.port1)
      self.imu = serial.Serial(self.port1, baudrate = baud_rate, timeout=3.0)
      command = '$VNWRG,07,40*XX\r'
      self.imu.write(command.encode('utf-8'))
      response = self.imu.readline().decode('utf-8').strip()
      print('VectorNav response: '+ response)
    except:
      print("There was an error opening the port")
    
    
  def timer_callback(self):
    msg = IMUmsg()
    #Check if the IMU is open then read a line, record the time
    if self.imu.isOpen():
      line = self.imu.readline()
      current_time = time.time()
      # At 115200
      try:
        line = line.decode('utf-8').strip()
        # If the line starts with the header we want, parse the line and publish the IMU data
        if str(line).startswith('$VNYMR'):
          yaw, pitch, roll, mag_x, mag_y, mag_z, a_x, a_y, a_z, ar_x, ar_y, ar_z = parse_imu(line)
          quart = euler_to_quart(roll, pitch, yaw)
          msg.imu.orientation.x = quart[0]
          msg.imu.orientation.y = quart[1]
          msg.imu.orientation.z = quart[2]
          msg.imu.orientation.w = quart[3]
          msg.imu.angular_velocity.x = ar_x
          msg.imu.angular_velocity.y = ar_y
          msg.imu.angular_velocity.z = ar_z
          msg.imu.linear_acceleration.x = a_x
          msg.imu.linear_acceleration.y = a_y
          msg.imu.linear_acceleration.z = a_z
          msg.mag_field.magnetic_field.x = mag_x
          msg.mag_field.magnetic_field.y = mag_y
          msg.mag_field.magnetic_field.z = mag_z
        # Save a raw string of the data just in case something goes wrong
        msg.rawstr = str(line)
        msg.header.stamp.sec = int(current_time)
        msg.header.stamp.nanosec = int(current_time%int(current_time)*10**9)
        msg.header.frame_id = "IMU1_Frame"
        # Publish the data
        self.publisher_.publish(msg)
      except:
      
        print('Skipping line due to error decoding or parsing line')
      

    
    
def parse_imu(line):
  print(line)
  VN_parts = line.split(',')
  yaw = float(VN_parts[1])
  pitch = float(VN_parts[2])
  roll = float(VN_parts[3])
  mag_x = float(VN_parts[4])
  mag_y = float(VN_parts[5])
  mag_z = float(VN_parts[6])
  a_x = float(VN_parts[7])
  a_y = float(VN_parts[8])
  a_z = float(VN_parts[9])
  ar_x = float(VN_parts[10])
  ar_y = float(VN_parts[11])
  # The split handles the checksum at the end of the line
  ar_z = float(VN_parts[12].split('*')[0])
  
  #line.strip('\x00')
  #print(line)
  
  #try: 
  #  VN_parts = line.split(',')
  #  yaw = float(VN_parts[1])
  #  pitch = float(VN_parts[2])
  #  roll = float(VN_parts[3])
  #  mag_x = float(VN_parts[4])
  #  mag_y = float(VN_parts[5])
  #  mag_z = float(VN_parts[6])
  #  a_x = float(VN_parts[7])
  #  a_y = float(VN_parts[8])
  #  a_z = float(VN_parts[9])
  #  ar_x = float(VN_parts[10])
  #  ar_y = float(VN_parts[11])
    # The split handles the checksum at the end of the file
  #  ar_z = float(VN_parts[12].split('*')[0])
  #except:
  #  print('There was an issue parsing the line after removing null character')
  #  yaw = float(0)
  #  pitch = float(0)
  #  roll = float(0)
  #  mag_x = float(0)
  #  mag_y = float(0)
  #  mag_z = float(0)
  #  a_x = float(0)
  #  a_y = float(0)
  #  a_z = float(0)
  #  ar_x = float(0)
  #  ar_y = float(0)
  #  ar_z = float(0)
  
  return yaw, pitch, roll, mag_x, mag_y, mag_z, a_x, a_y, a_z, ar_x, ar_y, ar_z
    
def euler_to_quart(roll, pitch, yaw):
  # Convert angles to radians
  roll = roll*math.pi/180
  pitch = pitch*math.pi/180
  yaw = yaw*math.pi/180

  # Compute the quarterions
  qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
  qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
  qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
  qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
 
  return [qx, qy, qz, qw]

def main(args=None):
  rclpy.init(args=args)
  
  imu_driver = IMU_Driver()
  
  rclpy.spin(imu_driver)
  
  
  imu_driver.destroy_node()
  rclpy.shutdown()
  
if __name__ == '__main__':
  main()
