// Copyright 2020-2022 The MathWorks, Inc.
// Common copy functions for imu_interface/IMUmsg
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
#include "imu_interface/msg/im_umsg.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class IMU_INTERFACE_EXPORT ros2_imu_interface_msg_IMUmsg_common : public MATLABROS2MsgInterface<imu_interface::msg::IMUmsg> {
  public:
    virtual ~ros2_imu_interface_msg_IMUmsg_common(){}
    virtual void copy_from_struct(imu_interface::msg::IMUmsg* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const imu_interface::msg::IMUmsg* msg, MultiLibLoader loader, size_t size = 1);
};
  void ros2_imu_interface_msg_IMUmsg_common::copy_from_struct(imu_interface::msg::IMUmsg* msg, const matlab::data::Struct& arr,
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
        //imu
        const matlab::data::StructArray imu_arr = arr["imu"];
        auto msgClassPtr_imu = getCommonObject<sensor_msgs::msg::Imu>("ros2_sensor_msgs_msg_Imu_common",loader);
        msgClassPtr_imu->copy_from_struct(&msg->imu,imu_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'imu' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'imu' is wrong type; expected a struct.");
    }
    try {
        //mag_field
        const matlab::data::StructArray mag_field_arr = arr["mag_field"];
        auto msgClassPtr_mag_field = getCommonObject<sensor_msgs::msg::MagneticField>("ros2_sensor_msgs_msg_MagneticField_common",loader);
        msgClassPtr_mag_field->copy_from_struct(&msg->mag_field,mag_field_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'mag_field' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'mag_field' is wrong type; expected a struct.");
    }
    try {
        //rawstr
        const matlab::data::CharArray rawstr_arr = arr["rawstr"];
        msg->rawstr = rawstr_arr.toAscii();
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'rawstr' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'rawstr' is wrong type; expected a string.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T ros2_imu_interface_msg_IMUmsg_common::get_arr(MDFactory_T& factory, const imu_interface::msg::IMUmsg* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","header","imu","mag_field","rawstr"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("imu_interface/IMUmsg");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::msg::Header>("ros2_std_msgs_msg_Header_common",loader);
    outArray[ctr]["header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // imu
    auto currentElement_imu = (msg + ctr)->imu;
    auto msgClassPtr_imu = getCommonObject<sensor_msgs::msg::Imu>("ros2_sensor_msgs_msg_Imu_common",loader);
    outArray[ctr]["imu"] = msgClassPtr_imu->get_arr(factory, &currentElement_imu, loader);
    // mag_field
    auto currentElement_mag_field = (msg + ctr)->mag_field;
    auto msgClassPtr_mag_field = getCommonObject<sensor_msgs::msg::MagneticField>("ros2_sensor_msgs_msg_MagneticField_common",loader);
    outArray[ctr]["mag_field"] = msgClassPtr_mag_field->get_arr(factory, &currentElement_mag_field, loader);
    // rawstr
    auto currentElement_rawstr = (msg + ctr)->rawstr;
    outArray[ctr]["rawstr"] = factory.createCharArray(currentElement_rawstr);
    }
    return std::move(outArray);
  } 
class IMU_INTERFACE_EXPORT ros2_imu_interface_IMUmsg_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~ros2_imu_interface_IMUmsg_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
    virtual std::shared_ptr<void> generateCppMessage(ElementType /*type*/, const matlab::data::StructArray& /* arr */, MultiLibLoader /* loader */, std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
    virtual matlab::data::StructArray generateMLMessage(ElementType  /*type*/ ,void*  /* msg */, MultiLibLoader /* loader */ , std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* /*commonObjMap*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          ros2_imu_interface_IMUmsg_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<imu_interface::msg::IMUmsg,ros2_imu_interface_msg_IMUmsg_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         ros2_imu_interface_IMUmsg_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<imu_interface::msg::IMUmsg,ros2_imu_interface_msg_IMUmsg_common>>();
  }
  std::shared_ptr<void> ros2_imu_interface_IMUmsg_message::generateCppMessage(ElementType /*type*/, 
                                           const matlab::data::StructArray& arr,
                                           MultiLibLoader loader,
                                           std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>* commonObjMap){
    auto msg = std::make_shared<imu_interface::msg::IMUmsg>();
    ros2_imu_interface_msg_IMUmsg_common commonObj;
    commonObj.mCommonObjMap = commonObjMap;
    commonObj.copy_from_struct(msg.get(), arr[0], loader);
    return msg;
  }
  matlab::data::StructArray ros2_imu_interface_IMUmsg_message::generateMLMessage(ElementType  /*type*/ ,
                                                    void*  msg ,
                                                    MultiLibLoader  loader ,
                                                    std::map<std::string,std::shared_ptr<MATLABROS2MsgInterfaceBase>>*  commonObjMap ){
    ros2_imu_interface_msg_IMUmsg_common commonObj;	
    commonObj.mCommonObjMap = commonObjMap;	
    MDFactory_T factory;
    return commonObj.get_arr(factory, (imu_interface::msg::IMUmsg*)msg, loader);			
 }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(ros2_imu_interface_msg_IMUmsg_common, MATLABROS2MsgInterface<imu_interface::msg::IMUmsg>)
CLASS_LOADER_REGISTER_CLASS(ros2_imu_interface_IMUmsg_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER