// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from gps_interface:msg/GPSmsg.idl
// generated code does not contain a copyright notice

#ifndef GPS_INTERFACE__MSG__DETAIL__GP_SMSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GPS_INTERFACE__MSG__DETAIL__GP_SMSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "gps_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "gps_interface/msg/detail/gp_smsg__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace gps_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gps_interface
cdr_serialize(
  const gps_interface::msg::GPSmsg & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gps_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gps_interface::msg::GPSmsg & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gps_interface
get_serialized_size(
  const gps_interface::msg::GPSmsg & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gps_interface
max_serialized_size_GPSmsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gps_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gps_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gps_interface, msg, GPSmsg)();

#ifdef __cplusplus
}
#endif

#endif  // GPS_INTERFACE__MSG__DETAIL__GP_SMSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
