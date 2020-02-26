//
// Created by Mon Le on 2020/2/25.
//

#include "LSkyBox.h"

namespace lemon
{
    LSkyBox::LSkyBox()
    {
        if(setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_tb.png"),LSkyBox::TOP) &&
        setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png"),LSkyBox::BOTTOM) &&
        setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png"),LSkyBox::LEFT) &&
        setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png"),LSkyBox::RIGHT) &&
        setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png"),LSkyBox::FRONT) &&
        setTexture(lemon::lemon_functions::getExePath("../media/map/skybox_wall.png"),LSkyBox::BACK)) {
            if(!setSkyBoxSceneNode()) {
                exit(0);
            }
        } else {
            exit(0);
        }

    }

    bool LSkyBox::setTexture(const char *texturePath, const int surfaceId)
    {
        switch(surfaceId){
            case LSkyBox::TOP:
                this->topTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            case LSkyBox::BOTTOM:
                this->bottomTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            case LSkyBox::LEFT:
                this->leftTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            case LSkyBox::RIGHT:
                this->rightTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            case LSkyBox::FRONT:
                this->frontTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            case LSkyBox::BACK:
                this->backTexture = lemon::Globals::videoDriver->getTexture(texturePath);
                return true;
            default:
                return false;
        }
    }

    bool LSkyBox::setSkyBoxSceneNode()
    {

        this->skyBoxSceneNode = lemon::Globals::iSceneManager->addSkyBoxSceneNode(
                this->topTexture,
                this->bottomTexture,
                this->leftTexture,
                this->rightTexture,
                this->frontTexture,
                this->backTexture
                );

        if(this->skyBoxSceneNode != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool LSkyBox::setVisible(bool isVisible)
    {
        if(){

        }else{

        }
    }

}