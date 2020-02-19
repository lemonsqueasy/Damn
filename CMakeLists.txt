cmake_minimum_required(VERSION 3.15)
project(Damn)
set(MAC_OS 1)

set(CMAKE_CXX_STANDARD 17)

set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)
set(QT_CORE_FRAMEWORK ${LIB_PATH}/QtCore.framework)

include_directories(${LIB_INCLUDE_PATH})
link_directories(${LIB_PATH})

add_executable(${PROJECT_NAME} source/main.cpp source/tool_functions/tool_functions.cpp source/tool_functions/tool_functions.h source/globals/Globals.cpp source/globals/Globals.h source/LEventReceiver.cpp source/LEventReceiver.h)

target_link_libraries(${PROJECT_NAME} ${QT_CORE_FRAMEWORK})

target_link_libraries(${PROJECT_NAME} -lIrrlicht -lGLEW -lglfw -lirrKlang)
if(MAC_OS)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
endif()
