cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0048 NEW)
project(mrs_vins_mono_estimator_plugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  mrs_uav_managers
  mrs_uav_state_estimators
  )

set(LIBRARIES
  MrsUavStateEstimators_VinsMono
  )

catkin_package(
  CATKIN_DEPENDS
  mrs_uav_managers
  mrs_uav_state_estimators
  )

find_package(mrs_uav_state_estimators REQUIRED)

###########
## Build ##
###########

add_library(MrsUavStateEstimators_VinsMono
  src/vins_mono_plugin.cpp
  )

add_dependencies(MrsUavStateEstimators_VinsMono
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
  )

target_link_libraries(MrsUavStateEstimators_VinsMono
  ${catkin_LIBRARIES}
  )

target_include_directories(MrsUavStateEstimators_VinsMono
  PRIVATE
  ${catkin_INCLUDE_DIRS}
  )

## --------------------------------------------------------------
## |                           Install                          |
## --------------------------------------------------------------

install(TARGETS ${LIBRARIES}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
  )

install(DIRECTORY custom_configs
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

install(FILES estimator_plugins.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )
