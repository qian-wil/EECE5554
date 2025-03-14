#!/usr/bin/env python3
import serial
import rospy
from std_msgs.msg import Header
from vn_driver.msg import Vectornav  
from math import radians, cos, sin

def convert_to_quaternion(roll, pitch, yaw):
    roll = radians(roll)
    pitch = radians(pitch)
    yaw = radians(yaw)
    
    cy = cos(yaw * 0.5)
    sy = sin(yaw * 0.5)
    cp = cos(pitch * 0.5)
    sp = sin(pitch * 0.5)
    cr = cos(roll * 0.5)
    sr = sin(roll * 0.5)
    
    w = cr * cp * cy + sr * sp * sy
    x = sr * cp * cy - cr * sp * sy
    y = cr * sp * cy + sr * cp * sy
    z = cr * cp * sy - sr * sp * cy
    
    return x, y, z, w

def parse_vnymr(data):
    fields = data.strip().split(',')
    print(f"raw VNYMR data: {data}")
    if fields[0] == "$VNYMR" and len(fields) >= 13:
        try:
            yaw, pitch, roll = float(fields[1]), float(fields[2]), float(fields[3])
            magX, magY, magZ = float(fields[4]), float(fields[5]), float(fields[6]) 
            accX, accY, accZ = float(fields[7]), float(fields[8]), float(fields[9])
            gyroX, gyroY, gyroZ = float(fields[10]), float(fields[11]), float(fields[12].split('*')[0])
            quatX, quatY, quatZ, quatW = convert_to_quaternion(roll, pitch, yaw)
            
            print(f"Acceleration: x={accX}, y={accY}, z={accZ}")
            print(f"Gyroscope: x={gyroX}, y={gyroY}, z={gyroZ}")
            print(f"Orientation: roll={roll}, pitch={pitch}, yaw={yaw}")
            print(f"Magnetometer: x={magX}, y={magY}, z={magZ}")
            print(f"Quaternion: x={quatX}, y={quatY}, z={quatZ}, w={quatW}")
            
            return {
                "acc": (accX, accY, accZ),
                "gyro": (gyroX, gyroY, gyroZ),
                "orientation": (roll, pitch, yaw),
                "magnetometer": (magX, magY, magZ),
                "quaternion": (quatX, quatY, quatZ, quatW)
            }
        except ValueError as e:
            rospy.logwarn(f"cant parse data: {e}")
            return None
    else:
        print("wrong format")
        return None


def imu_publisher(serial_port):
    rospy.init_node('imu_driver', anonymous=True)
    pub = rospy.Publisher('imu_data', Vectornav, queue_size=10)
    rate = rospy.Rate(40)  
    
    ser = serial.Serial(serial_port, 115200, timeout=1)
    print(f"port {serial_port}")

    while not rospy.is_shutdown():
        if ser.in_waiting > 0:
            line = ser.readline().decode('ascii', errors='ignore').strip()
            print(f"line: {line}")  
            imu_data = parse_vnymr(line)
            
            if imu_data:
                imu_msg = Vectornav()
    
                imu_msg.header = Header()
                imu_msg.header.stamp = rospy.Time.now()
                imu_msg.header.frame_id = "imu1_frame"
                
                imu_msg.imu.header = imu_msg.header
                imu_msg.imu.orientation.x = imu_data["quaternion"][0]
                imu_msg.imu.orientation.y = imu_data["quaternion"][1]
                imu_msg.imu.orientation.z = imu_data["quaternion"][2]
                imu_msg.imu.orientation.w = imu_data["quaternion"][3]
                imu_msg.imu.angular_velocity.x = imu_data["gyro"][0]
                imu_msg.imu.angular_velocity.y = imu_data["gyro"][1]
                imu_msg.imu.angular_velocity.z = imu_data["gyro"][2]
                imu_msg.imu.linear_acceleration.x = imu_data["acc"][0]
                imu_msg.imu.linear_acceleration.y = imu_data["acc"][1]
                imu_msg.imu.linear_acceleration.z = imu_data["acc"][2]

                imu_msg.mag_field.header = imu_msg.header
                imu_msg.mag_field.magnetic_field.x = imu_data["magnetometer"][0]
                imu_msg.mag_field.magnetic_field.y = imu_data["magnetometer"][1]
                imu_msg.mag_field.magnetic_field.z = imu_data["magnetometer"][2]

                imu_msg.raw_imu_string = line.strip()  
                pub.publish(imu_msg)
                rospy.loginfo(f"published data: {imu_msg}")
            else:
                print("can't parse data") 

        rate.sleep()

    ser.close()
    print("port closed")  

if __name__ == "__main__":
    serial_port = rospy.get_param('serial_port', '/dev/ttyUSB0')  # Default value
    baud_rate = rospy.get_param('baud_rate', 115200)  
    try:
        imu_publisher(serial_port)
    except rospy.ROSInterruptException:
        pass
