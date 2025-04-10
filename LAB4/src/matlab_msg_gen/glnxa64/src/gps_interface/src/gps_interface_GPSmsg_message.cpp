// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for gps_interface/GPSmsg
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4265)
#pragma warning(disable : 4456)
#pragma warning(disable : 4458)
#pragma warning(disable : 4946)
#pragma warning(disable : 4244)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "gps_interface/msg/gp_smsg.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class GPS_INTERFACE_EXPORT ros2_gps_interface_msg_GPSmsg_common : public MATLABROS2MsgInterface<gps_interface::msg::GPSmsg> {
  public:
    virtual ~ros2_gps_interface_msg_GPSmsg_common(){}
    virtual void copy_from_struct(gps_interface::msg::GPSmsg* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const gps_interface::msg::GPSmsg* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_gps_interface_msg_GPSmsg_common::copy_from_struct(gps_interface::msg::GPSmsg* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["header"];
        auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'header' is wrong type; expected a struct.");
    }
    try {
        //latitude
        const matlab::data::TypedArray<double> latitude_arr = arr["latitude"];
        msg->latitude = latitude_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'latitude' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'latitude' is wrong type; expected a double.");
    }
    try {
        //longitude
        const matlab::data::TypedArray<double> longitude_arr = arr["longitude"];
        msg->longitude = longitude_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'longitude' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'longitude' is wrong type; expected a double.");
    }
    try {
        //altitude
        const matlab::data::CharArray altitude_arr = arr["altitude"];
        msg->altitude = altitude_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'altitude' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'altitude' is wrong type; expected a string.");
    }
    try {
        //hdop
        const matlab::data::TypedArray<double> hdop_arr = arr["hdop"];
        msg->hdop = hdop_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'hdop' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'hdop' is wrong type; expected a double.");
    }
    try {
        //utm_easting
        const matlab::data::TypedArray<double> utm_easting_arr = arr["utm_easting"];
        msg->utm_easting = utm_easting_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'utm_easting' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'utm_easting' is wrong type; expected a double.");
    }
    try {
        //utm_northing
        const matlab::data::TypedArray<double> utm_northing_arr = arr["utm_northing"];
        msg->utm_northing = utm_northing_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'utm_northing' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'utm_northing' is wrong type; expected a double.");
    }
    try {
        //utc
        const matlab::data::CharArray utc_arr = arr["utc"];
        msg->utc = utc_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'utc' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'utc' is wrong type; expected a string.");
    }
    try {
        //zone
        const matlab::data::TypedArray<int64_t> zone_arr = arr["zone"];
        msg->zone = zone_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'zone' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'zone' is wrong type; expected a int64.");
    }
    try {
        //letter
        const matlab::data::CharArray letter_arr = arr["letter"];
        msg->letter = letter_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'letter' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'letter' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_gps_interface_msg_GPSmsg_common::get_arr(MDFactory_T& factory, const gps_interface::msg::GPSmsg* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","latitude","longitude","altitude","hdop","utm_easting","utm_northing","utc","zone","letter"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("gps_interface/GPSmsg");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // latitude
    auto currentElement_latitude = (msg + ctr)->latitude;
    outArray[ctr]["latitude"] = factory.createScalar(currentElement_latitude);
    // longitude
    auto currentElement_longitude = (msg + ctr)->longitude;
    outArray[ctr]["longitude"] = factory.createScalar(currentElement_longitude);
    // altitude
    auto currentElement_altitude = (msg + ctr)->altitude;
    outArray[ctr]["altitude"] = factory.createCharArray(currentElement_altitude);
    // hdop
    auto currentElement_hdop = (msg + ctr)->hdop;
    outArray[ctr]["hdop"] = factory.createScalar(currentElement_hdop);
    // utm_easting
    auto currentElement_utm_easting = (msg + ctr)->utm_easting;
    outArray[ctr]["utm_easting"] = factory.createScalar(currentElement_utm_easting);
    // utm_northing
    auto currentElement_utm_northing = (msg + ctr)->utm_northing;
    outArray[ctr]["utm_northing"] = factory.createScalar(currentElement_utm_northing);
    // utc
    auto currentElement_utc = (msg + ctr)->utc;
    outArray[ctr]["utc"] = factory.createCharArray(currentElement_utc);
    // zone
    auto currentElement_zone = (msg + ctr)->zone;
    outArray[ctr]["zone"] = factory.createScalar(currentElement_zone);
    // letter
    auto currentElement_letter = (msg + ctr)->letter;
    outArray[ctr]["letter"] = factory.createCharArray(currentElement_letter);
    }
    return std::move(outArray);
  } 
class GPS_INTERFACE_EXPORT ros2_gps_interface_GPSmsg_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_gps_interface_GPSmsg_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_gps_interface_GPSmsg_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<gps_interface::msg::GPSmsg,ros2_gps_interface_msg_GPSmsg_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_gps_interface_GPSmsg_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<gps_interface::msg::GPSmsg,ros2_gps_interface_msg_GPSmsg_common>>();
  }
  std::shared_ptr<void> ros2_gps_interface_GPSmsg_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<gps_interface::msg::GPSmsg>();
    ros2_gps_interface_msg_GPSmsg_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_gps_interface_GPSmsg_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_gps_interface_msg_GPSmsg_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (gps_interface::msg::GPSmsg*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_gps_interface_msg_GPSmsg_common, MATLABROS2MsgInterface<gps_interface::msg::GPSmsg>)
CLASS_LOADER_REGISTER_CLASS(ros2_gps_interface_GPSmsg_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER