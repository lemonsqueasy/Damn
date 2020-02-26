cmake_minimum_required(VERSION 3.15)
project(Damn)
set(MAC_OS 1)

set(CMAKE_CXX_STANDARD 17)

set(LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)
set(QT_CORE_FRAMEWORK ${LIB_PATH}/QtCore.framework)

include_directories(${LIB_INCLUDE_PATH})
link_directories(${LIB_PATH})

add_executable(${PROJECT_NAME} source/main.cpp source/lemon_functions/lemon_functions.cpp source/lemon_functions/lemon_functions.h source/Globals/Globals.cpp source/Globals/Globals.h source/LEventReceiver/LEventReceiver.cpp source/LEventReceiver/LEventReceiver.h source/Scenes/LSkyBox.cpp source/Scenes/LSkyBox.h source/Scenes/LMap.cpp source/Scenes/LMap.h)

target_link_libraries(${PROJECT_NAME} ${QT_CORE_FRAMEWORK})

target_link_libraries(${PROJECT_NAME} -lIrrlicht -lGLEW -lglfw -lirrKlang)
if(MAC_OS)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
endif()
