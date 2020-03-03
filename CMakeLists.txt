cmake_minimum_required(VERSION 3.15)
project(Damn)
set(MAC_OS 1)

set(CMAKE_CXX_STANDARD 17)

#irrlicht
set(IRRLICHT_LIB_PATH ${PROJECT_SOURCE_DIR}/library/irrlicht_1.8.4/lib)
set(IRRLICHT_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/irrlicht_1.8.4/include)
#irrklang
set(IRRKLANG_LIB_PATH ${PROJECT_SOURCE_DIR}/library/irrklang/lib)
set(IRRKLANG_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/irrklang/include)
#bullet
set(BULLET_LIB_PATH  ${PROJECT_SOURCE_DIR}/library/bullet3/lib)
set(BULLET_LIB_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/library/bullet3/include)
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
        ${IRRKLANG_LIB_INCLUDE_PATH}
        ${BULLET_LIB_INCLUDE_PATH}
        ${FREETYPE_LIB_INCLUDE_PATH}
        ${OPENGL_LIB_INCLUDE_PATH}
)
link_directories(
        ${IRRLICHT_LIB_PATH}
        ${IRRKLANG_LIB_PATH}
        ${BULLET_LIB_PATH}
        ${FREETYPE_LIB_PATH}
        ${OPENGL_LIB_PATH}
)


add_executable(${PROJECT_NAME}
        src/main.cpp
        src/GraphicWorld/GraphicWorld.cpp
        src/GraphicWorld/GraphicWorld.h
        src/Tools/tools.cpp
        src/Tools/tools.h
        src/GraphicWorld/GUIDisplayer/GuiFont/CGUITTFont.cpp
        src/GraphicWorld/GUIDisplayer/GuiFont/CGUITTFont.h
        src/GraphicWorld/GUIDisplayer/GuiFont/irrUString.h
        src/GraphicWorld/EventReceiver.cpp
        src/GraphicWorld/EventReceiver.h src/GraphicWorld/GUIDisplayer/TextDisplayer.cpp src/GraphicWorld/GUIDisplayer/TextDisplayer.h src/GraphicWorld/GUIDisplayer/GUIDisplayer.cpp src/GraphicWorld/GUIDisplayer/GUIDisplayer.h)

target_link_libraries(${PROJECT_NAME} -lIrrlicht)
target_link_libraries(${PROJECT_NAME} -lirrklang)
target_link_libraries(${PROJECT_NAME}
        -lBullet3Collision
        -lBullet3Common
        -lBullet3Dynamics
        -lBullet3Geometry
        -lBullet3OpenCL_clew
        -lBulletCollision
        -lBulletDynamics
        -lBulletInverseDynamics
        -lBulletSoftBody
        -lLinearMath
        -lclew
        -lBulletRobotics
        -lConvexDecomposition
        -lGIMPACTUtils
        -lHACD
        -lBulletInverseDynamicsUtils
        -lBulletFileLoader
        -lBulletWorldImporter
        -lBulletXmlWorldImporter
        -lVHACD
        )
target_link_libraries(${PROJECT_NAME} -lfreetype)
target_link_libraries(${PROJECT_NAME} -lGLEW -lglfw)
target_link_libraries(${PROJECT_NAME} ${QT_CORE_FRAMEWORK})
if(MAC_OS)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
endif()
