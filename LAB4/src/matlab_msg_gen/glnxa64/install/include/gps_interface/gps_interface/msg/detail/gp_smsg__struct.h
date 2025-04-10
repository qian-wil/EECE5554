// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gps_interface:msg/GPSmsg.idl
// generated code does not contain a copyright notice

#ifndef GPS_INTERFACE__MSG__DETAIL__GP_SMSG__STRUCT_H_
#define GPS_INTERFACE__MSG__DETAIL__GP_SMSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'altitude'
// Member 'utc'
// Member 'letter'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GPSmsg in the package gps_interface.
typedef struct gps_interface__msg__GPSmsg
{
  std_msgs__msg__Header header;
  double latitude;
  double longitude;
  rosidl_runtime_c__String altitude;
  double hdop;
  double utm_easting;
  double utm_northing;
  rosidl_runtime_c__String utc;
  int64_t zone;
  rosidl_runtime_c__String letter;
} gps_interface__msg__GPSmsg;

// Struct for a sequence of gps_interface__msg__GPSmsg.
typedef struct gps_interface__msg__GPSmsg__Sequence
{
  gps_interface__msg__GPSmsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gps_interface__msg__GPSmsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GPS_INTERFACE__MSG__DETAIL__GP_SMSG__STRUCT_H_
