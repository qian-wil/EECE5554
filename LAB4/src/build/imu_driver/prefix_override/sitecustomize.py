import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/qianw/EECE5554/LAB4/src/install/imu_driver'
