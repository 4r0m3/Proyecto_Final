# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\beta_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\beta_autogen.dir\\ParseCache.txt"
  "beta_autogen"
  )
endif()
