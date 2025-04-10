#ifndef IMU_INTERFACE__VISIBILITY_CONTROL_H_
#define IMU_INTERFACE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define IMU_INTERFACE_EXPORT __attribute__ ((dllexport))
    #define IMU_INTERFACE_IMPORT __attribute__ ((dllimport))
  #else
    #define IMU_INTERFACE_EXPORT __declspec(dllexport)
    #define IMU_INTERFACE_IMPORT __declspec(dllimport)
  #endif
  #ifdef IMU_INTERFACE_BUILDING_LIBRARY
    #define IMU_INTERFACE_PUBLIC IMU_INTERFACE_EXPORT
  #else
    #define IMU_INTERFACE_PUBLIC IMU_INTERFACE_IMPORT
  #endif
  #define IMU_INTERFACE_PUBLIC_TYPE IMU_INTERFACE_PUBLIC
  #define IMU_INTERFACE_LOCAL
#else
  #define IMU_INTERFACE_EXPORT __attribute__ ((visibility("default")))
  #define IMU_INTERFACE_IMPORT
  #if __GNUC__ >= 4
    #define IMU_INTERFACE_PUBLIC __attribute__ ((visibility("default")))
    #define IMU_INTERFACE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define IMU_INTERFACE_PUBLIC
    #define IMU_INTERFACE_LOCAL
  #endif
  #define IMU_INTERFACE_PUBLIC_TYPE
#endif
#endif  // IMU_INTERFACE__VISIBILITY_CONTROL_H_
// Generated 02-Apr-2025 19:48:03
 