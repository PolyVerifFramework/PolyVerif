# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_avp_demo_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED avp_demo_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(avp_demo_FOUND FALSE)
  elseif(NOT avp_demo_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(avp_demo_FOUND FALSE)
  endif()
  return()
endif()
set(_avp_demo_CONFIG_INCLUDED TRUE)

# output package information
if(NOT avp_demo_FIND_QUIETLY)
  message(STATUS "Found avp_demo: 1.0.0 (${avp_demo_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'avp_demo' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${avp_demo_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(avp_demo_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${avp_demo_DIR}/${_extra}")
endforeach()
