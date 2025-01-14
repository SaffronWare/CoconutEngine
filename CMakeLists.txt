﻿# CMakeList.txt : CMake project for CoconutEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

project ("Sandbox")

set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

file(GLOB SOURCES 
	"Sandbox/*.cpp"
	"Sandbox/*.h"
	"CoconutEngine/include/*.h"
	"CoconutEngine/source/*.cpp"
)

add_library(GLFW STATIC IMPORTED)
set_target_properties(GLFW PROPERTIES IMPORTED_LOCATION  "${LIB_DIR}/glfw-3.4/lib-vc-2022/glfw3.lib" )
target_include_directories(GLFW INTERFACE "${LIB_DIR}/glfw-3.4/include")

add_library(GLAD "${LIB_DIR}/OpenGL/src/glad.c")
target_include_directories(GLAD PUBLIC "${LIB_DIR}/OpenGL/include")


add_executable (Sandbox   ${SOURCES})

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

target_link_libraries(Sandbox PRIVATE glm::glm)

target_include_directories(Sandbox PRIVATE 
	"CoconutEngine/include"
	"${LIB_DIR}/ImGui"         
    "${LIB_DIR}/ImGui/backends"
	"${LIB_DIR}/STB_IMAGE"
)

target_link_libraries(Sandbox PUBLIC GLAD)
target_link_libraries(Sandbox PUBLIC GLFW)

add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
         "${LIB_DIR}/glfw-3.4/lib-vc-2022/glfw3.dll" ${CMAKE_BINARY_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/CoconutEngine/shaders" "${CMAKE_BINARY_DIR}/shaders"
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sandbox PROPERTY CXX_STANDARD 20)
endif()

