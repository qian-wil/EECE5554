#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gps_interface::gps_interface__rosidl_typesupport_introspection_cpp" for configuration "Release"
set_property(TARGET gps_interface::gps_interface__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(gps_interface::gps_interface__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgps_interface__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_RELEASE "libgps_interface__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _cmake_import_check_targets gps_interface::gps_interface__rosidl_typesupport_introspection_cpp )
list(APPEND _cmake_import_check_files_for_gps_interface::gps_interface__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/libgps_interface__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
