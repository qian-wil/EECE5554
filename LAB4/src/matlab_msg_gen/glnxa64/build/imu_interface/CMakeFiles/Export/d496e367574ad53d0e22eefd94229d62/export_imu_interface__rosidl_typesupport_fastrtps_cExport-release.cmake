#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "imu_interface::imu_interface__rosidl_typesupport_fastrtps_c" for configuration "Release"
set_property(TARGET imu_interface::imu_interface__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(imu_interface::imu_interface__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libimu_interface__rosidl_typesupport_fastrtps_c.so"
  IMPORTED_SONAME_RELEASE "libimu_interface__rosidl_typesupport_fastrtps_c.so"
  )

list(APPEND _cmake_import_check_targets imu_interface::imu_interface__rosidl_typesupport_fastrtps_c )
list(APPEND _cmake_import_check_files_for_imu_interface::imu_interface__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/libimu_interface__rosidl_typesupport_fastrtps_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
