#include <irrlicht/irrlicht.h>
#include <QtCore/QtCore>


#include "tool_functions/tool_functions.h"
#include "globals/Globals.h"

int main(int argc, char *argv[])
{

    lemon::Globals();




    irr::video::IVideoDriver* driver = lemon::Globals::device->getVideoDriver();
    irr::scene::ISceneManager* smgr = lemon::Globals::device->getSceneManager();
    //IGUIEnvironment* guienv = device->getGUIEnvironment();


    //加载雷神3地图
    lemon::Globals::device->getFileSystem()->addFileArchive(lemon::tool_functions::getExePath("../media/map-20kdm2.pk3"));
    irr::scene::IAnimatedMesh* mapMesh = smgr->getMesh("20kdm2.bsp");
    if (!mapMesh)
    {
        lemon::Globals::device->drop();
        return 1;
    }
    //scene::ISceneNode* mapNode = smgr->addOctreeSceneNode(mapMesh->getMesh(0), 0, -1, 1024);
    irr::scene::ISceneNode* mapNode = smgr->addAnimatedMeshSceneNode(mapMesh);
    if(mapNode)
    {
        mapNode->setPosition(irr::core::vector3df(-1300,-144,-1249));
    }





    irr::scene::IAnimatedMesh* peopleMesh = smgr->getMesh(lemon::tool_functions::getExePath("../media/sydney.md2"));
    if (!peopleMesh)
    {
        lemon::Globals::device->drop();
        return 1;
    }
    irr::scene::IAnimatedMeshSceneNode* peopleNode = smgr->addAnimatedMeshSceneNode(peopleMesh, 0, -1, irr::core::vector3df(0,0,0),
            irr::core::vector3df(0,0,0), irr::core::vector3df(1.0f, 1.0f, 1.0f),false);

    if (peopleNode)
    {
        peopleNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        peopleNode->setMD2Animation(irr::scene::EMAT_STAND);
        peopleNode->setMaterialTexture( 0, driver->getTexture(lemon::tool_functions::getExePath("../media/sydney.bmp")) );
    }








    smgr->addCameraSceneNodeFPS();



    bool getESC = false;
    while(lemon::Globals::device->run() && !getESC)
    {

        driver->beginScene(true, true, irr::video::SColor(255,0,0,0));

        smgr->drawAll();

        driver->endScene();

        lemon::Globals::device->sleep(10);

        if(lemon::Globals::lReceiver->IsKeyDown(irr::KEY_ESCAPE))
            getESC = true;

    }


    lemon::Globals::device->drop();

    return 0;
}




