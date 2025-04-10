#!/usr/bin/env python3
#Thanh Dao
#1/25/2025
#LAB1

import rclpy
import serial
import utm
from rclpy.node import Node
from rclpy.parameter import Parameter
from gps_interface.msg import GPSmsg
import argparse

baud_rate = 4800 #4800 for this device

class GPS_Driver(Node):
  def __init__(self):
    super().__init__('gps_driver')
    self.publisher_ = self.create_publisher(GPSmsg, 'gps', 10)
    timer_period = 0.1 # seconds to read the GPS data from serial port
    self.timer = self.create_timer(timer_period, self.timer_callback)
    
    #Declares the parameters set in the launch file
    self.declare_parameters(namespace = '', parameters=[('gps_port', '/dev/pts/1'),])
    
  def timer_callback(self):
    msg = GPSmsg()
    port1 = self.get_parameter('gps_port').value
    print('Opening serial at port: ' + str(port1))
    gps = serial.Serial(port1, baudrate=baud_rate, timeout=3.0)
    if gps.isOpen():
      try:
        line = gps.readline()
        line = line.decode('utf-8')
        if line.startswith('$GPGGA'):
          easting, northing, zone_num, zone_letter, lat, longi, alti, HDP, gps_time_str, gps_time_sec, gps_time_nsec = parse_gps(line)
          msg.header.stamp.sec = int(float(gps_time_sec))
          msg.header.stamp.nanosec = int(gps_time_nsec)
          msg.header.frame_id = 'GPS1_Frame'
          msg.latitude = lat
          msg.longitude = longi
          msg.altitude = alti
          msg.hdop = float(HDP)
          msg.utm_easting = easting
          msg.utm_northing = northing
          msg.utc = gps_time_str
          msg.zone = zone_num
          msg.letter = zone_letter
          self.publisher_.publish(msg)
          #self.get_logger().info('Publishing: "%s"' % msg)
      except serial.serialutil.SerialException:
        print("Something is wrong with the GPS")
    gps.close()
      

def main(args=None):
  rclpy.init(args=args)
  
  gps_driver = GPS_Driver()
  
  rclpy.spin(gps_driver)
  
  
  gps_driver.destroy_node()
  rclpy.shutdown()



#Takes in a GPGGA line, splts it, converts it UTM and returns the UTM easting, northing,
#zone number, zone letter, so on
def parse_gps(line):
  #Split the line into its components, delimited by commas
  parts = line.split(',')
  
  #Separate each component to its own string for handling
  time_UTC_string = parts[1]
  lat = parts[2]
  latdir= parts[3]
  longi = parts[4]
  longidir = parts[5]
  qualIndic = parts [6]
  numSat = parts[7]
  HDP = parts[8]
  alti = parts[9]
  altiUnits = [10]
  geoSep = parts[11]
  geoSepUnits = parts[12]
  ageCorrection = parts[13]
  cStationID, checkSum = parts[14].split('*')
  checkSum = '*' + checkSum #Fix the formatting
  
  #Converting the NMEA format to UTM
  
  latDD = DMStoDD(lat, latdir)
  lonDD = DMStoDD(longi, longidir)
  easting, northing, zone_num, zone_letter = utm.from_latlon(latDD, lonDD)
      
  hours = float(time_UTC_string[0:2])
  minutes = float(time_UTC_string[2:4])
  seconds = float(time_UTC_string[4:])
  seconds_decimal = seconds - int(seconds)
  time_UTC_nsec = int(seconds_decimal*10**9)
  
  time_UTC_sec = hours*3600 + minutes*60 + seconds
  
  alti = alti + ',M'
  
  return easting, northing, zone_num, zone_letter, latDD, lonDD, alti, HDP, time_UTC_string, time_UTC_sec, time_UTC_nsec

#Function that takes in the NMEA format lat or long in the form of Degrees, minutes,
#and direction, then converts that to a signed decimal degrees 
#where (+) indicates north/east and (-) south/west
def DMStoDD(DMS, DMSdir):
  if DMSdir == 'N'or DMSdir == "S":
    degree = float(DMS[0:2])
    minutes = float(DMS[2:])
    decimal = minutes/60
    DD = degree + decimal
  
    if DMSdir == 'N':
      return DD
    else:
      return -DD
  else:
    degree = float(DMS[0:3])
    minutes = float(DMS[3:])
    decimal = minutes/60
    DD = degree + decimal
    
    if DMSdir == 'E':
      return DD
    else:
      return -DD

if __name__ == '__main__':
  main()
  


