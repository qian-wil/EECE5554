// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gps_interface:msg/GPSmsg.idl
// generated code does not contain a copyright notice

#ifndef GPS_INTERFACE__MSG__DETAIL__GP_SMSG__BUILDER_HPP_
#define GPS_INTERFACE__MSG__DETAIL__GP_SMSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gps_interface/msg/detail/gp_smsg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gps_interface
{

namespace msg
{

namespace builder
{

class Init_GPSmsg_letter
{
public:
  explicit Init_GPSmsg_letter(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  ::gps_interface::msg::GPSmsg letter(::gps_interface::msg::GPSmsg::_letter_type arg)
  {
    msg_.letter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_zone
{
public:
  explicit Init_GPSmsg_zone(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_letter zone(::gps_interface::msg::GPSmsg::_zone_type arg)
  {
    msg_.zone = std::move(arg);
    return Init_GPSmsg_letter(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_utc
{
public:
  explicit Init_GPSmsg_utc(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_zone utc(::gps_interface::msg::GPSmsg::_utc_type arg)
  {
    msg_.utc = std::move(arg);
    return Init_GPSmsg_zone(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_utm_northing
{
public:
  explicit Init_GPSmsg_utm_northing(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_utc utm_northing(::gps_interface::msg::GPSmsg::_utm_northing_type arg)
  {
    msg_.utm_northing = std::move(arg);
    return Init_GPSmsg_utc(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_utm_easting
{
public:
  explicit Init_GPSmsg_utm_easting(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_utm_northing utm_easting(::gps_interface::msg::GPSmsg::_utm_easting_type arg)
  {
    msg_.utm_easting = std::move(arg);
    return Init_GPSmsg_utm_northing(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_hdop
{
public:
  explicit Init_GPSmsg_hdop(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_utm_easting hdop(::gps_interface::msg::GPSmsg::_hdop_type arg)
  {
    msg_.hdop = std::move(arg);
    return Init_GPSmsg_utm_easting(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_altitude
{
public:
  explicit Init_GPSmsg_altitude(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_hdop altitude(::gps_interface::msg::GPSmsg::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_GPSmsg_hdop(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_longitude
{
public:
  explicit Init_GPSmsg_longitude(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_altitude longitude(::gps_interface::msg::GPSmsg::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_GPSmsg_altitude(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_latitude
{
public:
  explicit Init_GPSmsg_latitude(::gps_interface::msg::GPSmsg & msg)
  : msg_(msg)
  {}
  Init_GPSmsg_longitude latitude(::gps_interface::msg::GPSmsg::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_GPSmsg_longitude(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

class Init_GPSmsg_header
{
public:
  Init_GPSmsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GPSmsg_latitude header(::gps_interface::msg::GPSmsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GPSmsg_latitude(msg_);
  }

private:
  ::gps_interface::msg::GPSmsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gps_interface::msg::GPSmsg>()
{
  return gps_interface::msg::builder::Init_GPSmsg_header();
}

}  // namespace gps_interface

#endif  // GPS_INTERFACE__MSG__DETAIL__GP_SMSG__BUILDER_HPP_
