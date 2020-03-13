cmake_minimum_required(VERSION 3.15)
project(Damn)
set(MAC_OS 1)

set(CMAKE_CXX_STANDARD 11)

#irrlicht
set(IRRLICHT_LIB_PATH ${PROJECT_SOURCE_DIR}/library/irrlicht/lib)
set(IRRLICHT_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/irrlicht/include)
#bullet
set(BULLET_LIB_PATH  ${PROJECT_SOURCE_DIR}/library/bullet3/lib)
set(BULLET_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/bullet3/include)
#irrbullet
set(IRRBULLET_LIB_PATH  ${PROJECT_SOURCE_DIR}/library/irrbullet/lib)
set(IRRBULLET_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/irrbullet/include)
#SFML
set(SFML_LIB_PATH ${PROJECT_SOURCE_DIR}/library/SFML/lib)
set(SFML_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/SFML/include)
#freetype
set(FREETYPE_LIB_PATH ${PROJECT_SOURCE_DIR}/library/freetype/lib)
set(FREETYPE_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/library/freetype/include)
#opengl
set(OPENGL_LIB_PATH ${PROJECT_SOURCE_DIR}/library/opengl/lib)
set(OPENGL_LIB_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/library/opengl/include)
#qt
set(QT_CORE_FRAMEWORK ${PROJECT_SOURCE_DIR}/library/qt/QtCore.framework)

include_directories(
        ${IRRLICHT_LIB_INCLUDE_PATH}
        ${BULLET_LIB_INCLUDE_PATH}
        ${IRRBULLET_LIB_INCLUDE_PATH}
        ${SFML_LIB_INCLUDE_PATH}
        ${FREETYPE_LIB_INCLUDE_PATH}
        ${OPENGL_LIB_INCLUDE_PATH}
)
link_directories(
        ${IRRLICHT_LIB_PATH}
        ${BULLET_LIB_PATH}
        ${IRRBULLET_LIB_PATH}
        ${SFML_LIB_PATH}
        ${FREETYPE_LIB_PATH}
        ${OPENGL_LIB_PATH}
)


add_executable(${PROJECT_NAME}
        src/main.cpp
        src/ToolsAndStructs/structs.h
        src/ToolsAndStructs/tools.h
        src/ToolsAndStructs/tools.cpp
        src/LemonWorld/EventReceiver.cpp
        src/LemonWorld/EventReceiver.h
        src/LemonWorld/GUIDisplayer/GuiFont/CGUITTFont.cpp
        src/LemonWorld/GUIDisplayer/GuiFont/CGUITTFont.h
        src/LemonWorld/GUIDisplayer/GuiFont/irrUString.h
        src/LemonWorld/GUIDisplayer/GUIDisplayer.cpp
        src/LemonWorld/GUIDisplayer/GUIDisplayer.h
        src/LemonWorld/GUIDisplayer/TextDisplayer.cpp
        src/LemonWorld/GUIDisplayer/TextDisplayer.h
        src/LemonWorld/LemonWorld.cpp src/LemonWorld/LemonWorld.h src/test/testMain.cpp src/LemonWorld/WorldDriver.cpp src/LemonWorld/WorldDriver.h src/LemonWorld/LemonRigidObject.cpp src/LemonWorld/LemonRigidObject.h src/LemonWorldObjects/Board.cpp src/LemonWorldObjects/Board.h src/LemonWorldObjects/Brick.cpp src/LemonWorldObjects/Brick.h src/LemonWorldObjects/Ball.cpp src/LemonWorldObjects/Ball.h)

target_link_libraries(${PROJECT_NAME} -lIrrlicht)
target_link_libraries(${PROJECT_NAME} -lBullet)
target_link_libraries(${PROJECT_NAME} -lIrrBullet)
target_link_libraries(${PROJECT_NAME}
        -lsfml-system-d
        -lsfml-audio-d
        -lsfml-network-d
        -lsfml-window-d
        -lsfml-graphics-d
        )
target_link_libraries(${PROJECT_NAME} -lfreetype)
target_link_libraries(${PROJECT_NAME} -lGLEW -lglfw)
target_link_libraries(${PROJECT_NAME} ${QT_CORE_FRAMEWORK})
if(MAC_OS)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
endif()
