// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from imu_interface:msg/IMUmsg.idl
// generated code does not contain a copyright notice

#ifndef IMU_INTERFACE__MSG__DETAIL__IM_UMSG__BUILDER_HPP_
#define IMU_INTERFACE__MSG__DETAIL__IM_UMSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "imu_interface/msg/detail/im_umsg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace imu_interface
{

namespace msg
{

namespace builder
{

class Init_IMUmsg_rawstr
{
public:
  explicit Init_IMUmsg_rawstr(::imu_interface::msg::IMUmsg & msg)
  : msg_(msg)
  {}
  ::imu_interface::msg::IMUmsg rawstr(::imu_interface::msg::IMUmsg::_rawstr_type arg)
  {
    msg_.rawstr = std::move(arg);
    return std::move(msg_);
  }

private:
  ::imu_interface::msg::IMUmsg msg_;
};

class Init_IMUmsg_mag_field
{
public:
  explicit Init_IMUmsg_mag_field(::imu_interface::msg::IMUmsg & msg)
  : msg_(msg)
  {}
  Init_IMUmsg_rawstr mag_field(::imu_interface::msg::IMUmsg::_mag_field_type arg)
  {
    msg_.mag_field = std::move(arg);
    return Init_IMUmsg_rawstr(msg_);
  }

private:
  ::imu_interface::msg::IMUmsg msg_;
};

class Init_IMUmsg_imu
{
public:
  explicit Init_IMUmsg_imu(::imu_interface::msg::IMUmsg & msg)
  : msg_(msg)
  {}
  Init_IMUmsg_mag_field imu(::imu_interface::msg::IMUmsg::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_IMUmsg_mag_field(msg_);
  }

private:
  ::imu_interface::msg::IMUmsg msg_;
};

class Init_IMUmsg_header
{
public:
  Init_IMUmsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUmsg_imu header(::imu_interface::msg::IMUmsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IMUmsg_imu(msg_);
  }

private:
  ::imu_interface::msg::IMUmsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::imu_interface::msg::IMUmsg>()
{
  return imu_interface::msg::builder::Init_IMUmsg_header();
}

}  // namespace imu_interface

#endif  // IMU_INTERFACE__MSG__DETAIL__IM_UMSG__BUILDER_HPP_
