#ifndef GPS_INTERFACE__VISIBILITY_CONTROL_H_
#define GPS_INTERFACE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define GPS_INTERFACE_EXPORT __attribute__ ((dllexport))
    #define GPS_INTERFACE_IMPORT __attribute__ ((dllimport))
  #else
    #define GPS_INTERFACE_EXPORT __declspec(dllexport)
    #define GPS_INTERFACE_IMPORT __declspec(dllimport)
  #endif
  #ifdef GPS_INTERFACE_BUILDING_LIBRARY
    #define GPS_INTERFACE_PUBLIC GPS_INTERFACE_EXPORT
  #else
    #define GPS_INTERFACE_PUBLIC GPS_INTERFACE_IMPORT
  #endif
  #define GPS_INTERFACE_PUBLIC_TYPE GPS_INTERFACE_PUBLIC
  #define GPS_INTERFACE_LOCAL
#else
  #define GPS_INTERFACE_EXPORT __attribute__ ((visibility("default")))
  #define GPS_INTERFACE_IMPORT
  #if __GNUC__ >= 4
    #define GPS_INTERFACE_PUBLIC __attribute__ ((visibility("default")))
    #define GPS_INTERFACE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define GPS_INTERFACE_PUBLIC
    #define GPS_INTERFACE_LOCAL
  #endif
  #define GPS_INTERFACE_PUBLIC_TYPE
#endif
#endif  // GPS_INTERFACE__VISIBILITY_CONTROL_H_
// Generated 02-Apr-2025 19:48:01
 