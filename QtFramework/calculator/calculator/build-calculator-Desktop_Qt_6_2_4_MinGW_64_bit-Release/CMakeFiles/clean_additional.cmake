# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Resource_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Resource_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\calculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calculator_autogen.dir\\ParseCache.txt"
  "Resource_autogen"
  "calculator_autogen"
  )
endif()
