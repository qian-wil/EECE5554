#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import serial
import time
import utm
import argparse
import rospy
from math import sin, pi
from gps_driver.msg import Customgps  # Import your custom message
from std_msgs.msg import Header  # Import Header for the custom message


def convertToUTM(LatitudeSigned, LongitudeSigned):
    """Convert latitude and longitude to UTM."""
    UTMVals = utm.from_latlon(LatitudeSigned, LongitudeSigned)
    UTMEasting = UTMVals[0]     # Easting
    UTMNorthing = UTMVals[1]    # Northing
    UTMZone = UTMVals[2]        # Zone number
    UTMLetter = UTMVals[3]      # Zone letter
    
    return [UTMEasting, UTMNorthing, UTMZone, UTMLetter]

def UTCtoUTCEpoch(UTC):
    """Convert UTC time to epoch time."""
    start_of_day = time.mktime(time.gmtime()) - time.gmtime().tm_hour*3600 - time.gmtime().tm_min*60 - time.gmtime().tm_sec
    hours = int(UTC[:2])
    minutes = int(UTC[2:4])
    seconds = float(UTC[4:])
    UTC_seconds = hours * 3600 + minutes * 60 + seconds
    CurrentTime = start_of_day + UTC_seconds
    CurrentTimeSec = int(CurrentTime)  # Integer part (total seconds)
    CurrentTimeNsec = int((CurrentTime - CurrentTimeSec) * 1e9)  # Nanoseconds (fractional part)
    
    return [CurrentTimeSec, CurrentTimeNsec]

def ReadFromSerial(serialPortAddr):
    """Read a GPGGA string from the serial port."""
    serialPort = serial.Serial(serialPortAddr)
    gpggaRead = serialPort.readline().decode('utf-8', errors='ignore').strip()  
    serialPort.close()  # Close the port
    return gpggaRead

def isGPGGAinString(inputString):
    """Check if the GPGGA string is present."""
    if '$GPGGA' in inputString:
        print('Great success!')
    else:
        print('GPGGA not found in string.')

def degMinstoDegDec(LatOrLong):
    """Convert latitude or longitude from DDmm.mm to decimal degrees."""
    deg = LatOrLong[:-7]  
    mins = LatOrLong[-7:]  
    degrees = float(deg)
    minutes = float(mins)
    decimal_degrees = degrees + (minutes / 60.0)
    return decimal_degrees

def LatLongSignConvention(LatOrLong, LatOrLongDir):
    """Apply sign convention for latitude and longitude."""
    if LatOrLongDir == "S" or LatOrLongDir == "W":
        LatOrLong = -LatOrLong  
    print(f"Signed Value: {LatOrLong}")
    return LatOrLong

# Main execution
def gps_publisher(serial_port):
    # Initialize the ROS node
    rospy.init_node('gps_driver', anonymous=True)

    # Create a ROS publisher
    pub = rospy.Publisher('gps_data', Customgps, queue_size=10)
    
    # Set the publishing rate (e.g., 1 Hz)
    rate = rospy.Rate(1)  

    while not rospy.is_shutdown():
        gpggaRead = ReadFromSerial(serial_port)
        print(f"Raw GPGGA Read: {gpggaRead}")  # Print raw GPGGA string
        gpggaSplit = gpggaRead.split(',')

        if len(gpggaSplit) > 1:
            UTC = gpggaSplit[1]

            # Convert Latitude
            try:
                Latitude = gpggaSplit[2]
                LatitudeDir = gpggaSplit[3]
                LatitudeDecimal = degMinstoDegDec(Latitude)
                LatitudeSigned = LatLongSignConvention(LatitudeDecimal, LatitudeDir)
                print(f"Latitude: {LatitudeSigned} {LatitudeDir}")  # Debug print
            except (ValueError, IndexError) as e:
                rospy.logwarn(f"Error processing Latitude: {e}")
                LatitudeSigned = None  # You can choose how to handle this

            # Convert Longitude
            try:
                Longitude = gpggaSplit[4]
                LongitudeDir = gpggaSplit[5]
                LongitudeDecimal = degMinstoDegDec(Longitude)
                LongitudeSigned = LatLongSignConvention(LongitudeDecimal, LongitudeDir)
                print(f"Longitude: {LongitudeSigned} {LongitudeDir}")  # Debug print
            except (ValueError, IndexError) as e:
                rospy.logwarn(f"Error processing Longitude: {e}")
                LongitudeSigned = None  # You can choose how to handle this

            # Convert Altitude
            try:
                altitude = float(gpggaSplit[10])
                print(f"Altitude: {altitude}")  # Debug print
            except (ValueError, IndexError) as e:
                rospy.logwarn(f"Error processing Altitude: {e}")
                altitude = None  # Default value or None

            # Convert HDOP
            if len(gpggaSplit) > 8 and gpggaSplit[8] != '':
                try:
                    HDOP = float(gpggaSplit[8])
                    print(f"HDOP: {HDOP}")  # Debug print
                except ValueError:
                    rospy.logwarn(f"Invalid HDOP value: {gpggaSplit[8]}")
                    HDOP = None
            else:
                rospy.logwarn("No valid HDOP value received")
                HDOP = None

            if LatitudeSigned is not None and LongitudeSigned is not None:
                try:
                    utm_vals = convertToUTM(LatitudeSigned, LongitudeSigned)
                    UTMEasting, UTMNorthing, UTMZone, UTMLetter = utm_vals
                    print(f"UTM Values: Easting: {UTMEasting}, Northing: {UTMNorthing}, Zone: {UTMZone}, Letter: {UTMLetter}")  # Debug print
                except Exception as e:
                    rospy.logwarn(f"Error converting to UTM: {e}")
                    UTMEasting = UTMNorthing = UTMZone = UTMLetter = None

            try:
                CurrentTimeSec, CurrentTimeNsec = UTCtoUTCEpoch(UTC)
            except Exception as e:
                rospy.logwarn(f"Error converting UTC time: {e}")
                CurrentTimeSec = CurrentTimeNsec = None

            # Publish GPS message only if essential fields are valid
            if LatitudeSigned is not None and LongitudeSigned is not None:
                gps_msg = Customgps()

                gps_msg.header = Header()
                gps_msg.header.frame_id = 'GPS1_Frame'
                gps_msg.header.stamp.secs = CurrentTimeSec if CurrentTimeSec is not None else 0
                gps_msg.header.stamp.nsecs = CurrentTimeNsec if CurrentTimeNsec is not None else 0
                gps_msg.latitude = LatitudeSigned
                gps_msg.longitude = LongitudeSigned
                gps_msg.altitude = altitude if altitude is not None else 0
                gps_msg.utm_easting = UTMEasting if UTMEasting is not None else 0
                gps_msg.utm_northing = UTMNorthing if UTMNorthing is not None else 0
                gps_msg.zone = UTMZone if UTMZone is not None else ''
                gps_msg.letter = UTMLetter if UTMLetter is not None else ''
                gps_msg.hdop = HDOP if HDOP is not None else 0
                gps_msg.gpgga_read = gpggaRead

                pub.publish(gps_msg)
                rospy.loginfo(f"Published GPS Data: {gps_msg}")
        
        rate.sleep()

if __name__ == "__main__":
    
    serial_port = "/dev/ttyUSB0" 

    try:
        gps_publisher(serial_port)
    except rospy.ROSInterruptException:
        pass
