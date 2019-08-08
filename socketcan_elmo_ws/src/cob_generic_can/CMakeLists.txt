cmake_minimum_required(VERSION 2.8.3)
project(cob_generic_can)

find_package(catkin REQUIRED COMPONENTS roscpp )

###################################
## catkin specific configuration ##
###################################

catkin_package(
    CATKIN_DEPENDS roscpp 
    INCLUDE_DIRS common/include
    LIBRARIES ${PROJECT_NAME}_socketdriver 
)

###########
## Build ##
###########

include_directories(common/include ${Boost_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})

# add project libs
add_library(${PROJECT_NAME}_socketdriver common/src/cansocketdriver.cpp)


# link libraries
target_link_libraries(${PROJECT_NAME}_socketdriver ${catkin_LIBRARIES})



#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}_socketdriver
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY common/include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
