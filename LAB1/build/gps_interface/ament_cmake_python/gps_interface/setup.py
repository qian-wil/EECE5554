from setuptools import find_packages
from setuptools import setup

setup(
    name='gps_interface',
    version='0.0.0',
    packages=find_packages(
        include=('gps_interface', 'gps_interface.*')),
)
