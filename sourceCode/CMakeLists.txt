cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/ CACHE PATH "Project specific path. Set manually if it was not found.")

#Chooses the right dependencies folder for your OS

if("${CMAKE_SYSTEM}" MATCHES "Darwin")
	set(DEPENDENCIES_PATH ${CMAKE_SOURCE_DIR}/dependencies/dependencies_osx/ CACHE PATH "Project specific path. Set manually if it was not found.")

else()
	set(DEPENDENCIES_PATH ${CMAKE_SOURCE_DIR}/dependencies/dependencies/ CACHE PATH "Project specific path. Set manually if it was not found.")

endif()
#==========================================


set(RESOURCES_PATH ${CMAKE_SOURCE_DIR}/resources/ CACHE PATH "Project specific path. Set manually if it was not found.")
set(SHADERS_PATH ${CMAKE_SOURCE_DIR}/src/shaders/ CACHE PATH "Project specific path. Set manually if it was not found.")

include(${CMAKE_MODULE_PATH}/DefaultProject.cmake)
