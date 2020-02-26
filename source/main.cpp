

#include <irrlicht/irrlicht.h>
#include <QtCore/QtCore>


#include "lemon_functions/lemon_functions.h"
#include "Globals/Globals.h"


int main(int argc, char *argv[])
{

    lemon::Globals();


    irr::scene::ISceneNode* skyBox = lemon::Globals::iSceneManager->addSkyBoxSceneNode(
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_tb.png")),
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_tb.png")),
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png")),
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png")),
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png")),
            lemon::Globals::videoDriver->getTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png")));


    irr::scene::IAnimatedMesh* mapMesh = lemon::Globals::iSceneManager->getMesh(lemon::lemon_functions::getExePath("../media/map/map.obj"));
    irr::scene::ISceneNode* mapSceneNode = nullptr;
    if (mapMesh)
    {
        mapSceneNode = lemon::Globals::iSceneManager->addOctreeSceneNode(mapMesh->getMesh(0));
        mapSceneNode->setMaterialFlag(irr::video::EMF_LIGHTING,false);
    }

    mapSceneNode->setScale(irr::core::vector3df(100,100,100));





    irr::scene::ITriangleSelector* selector = 0;

    if (mapSceneNode)
    {
        mapSceneNode->setPosition(irr::core::vector3df(0, 0, 0));
        //mapSceneNode->setMaterialTexture( 0, driver->getTexture(lemon::lemon_functions::getExePath("../media/sydney.bmp")));

        selector = lemon::Globals::iSceneManager->createOctreeTriangleSelector(
                mapMesh->getMesh(0), mapSceneNode, 128);
        mapSceneNode->setTriangleSelector(selector);
        // We're not done with this selector yet, so don't drop it.
    }



    irr::SKeyMap* lKeyMapArray = new irr::SKeyMap[5];
    lKeyMapArray[0].KeyCode = irr::KEY_KEY_W;
    lKeyMapArray[0].Action = irr::EKA_MOVE_FORWARD;
    lKeyMapArray[1].KeyCode = irr::KEY_KEY_S;
    lKeyMapArray[1].Action = irr::EKA_MOVE_BACKWARD;
    lKeyMapArray[2].KeyCode = irr::KEY_KEY_A;
    lKeyMapArray[2].Action = irr::EKA_STRAFE_LEFT;
    lKeyMapArray[3].KeyCode = irr::KEY_KEY_D;
    lKeyMapArray[3].Action = irr::EKA_STRAFE_RIGHT;
    lKeyMapArray[4].KeyCode = irr::KEY_SPACE;
    lKeyMapArray[4].Action = irr::EKA_JUMP_UP;


    irr::scene::ICameraSceneNode* camera =
            lemon::Globals::iSceneManager->addCameraSceneNodeFPS(0, 100.0f, .2f, 0, lKeyMapArray, 5, true, 7.f);
    camera->setPosition(irr::core::vector3df(0,100,0));
    camera->setTarget(irr::core::vector3df(0,100,1));
    camera->setFarValue(500000);


    if (selector)
    {
        irr::scene::ISceneNodeAnimator* anim = lemon::Globals::iSceneManager->createCollisionResponseAnimator(
                selector, camera, irr::core::vector3df(30,30,30),
                irr::core::vector3df(0,-10,0), irr::core::vector3df(0,30,0));
        selector->drop(); // As soon as we're done with the selector, drop it.
        camera->addAnimator(anim);
        anim->drop();  // And likewise, drop the animator when we're done referring to it.
    }


    lemon::Globals::irrlichtDevice->getCursorControl()->setVisible(false);

    while(lemon::Globals::irrlichtDevice->run())
    {

        lemon::Globals::videoDriver->beginScene(true, true, irr::video::SColor(255,0,0,0));
        lemon::Globals::iSceneManager->drawAll();
        lemon::Globals::videoDriver->endScene();


        if(lemon::Globals::lReceiver->IsKeyDown(irr::KEY_ESCAPE))
            break;
        lemon::Globals::irrlichtDevice->sleep(7);
    }


    lemon::Globals::irrlichtDevice->drop();

    return 0;


}

