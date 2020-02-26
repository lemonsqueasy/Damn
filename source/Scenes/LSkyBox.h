//
// Created by Mon Le on 2020/2/25.
//
#ifndef DAMN_SKYBOX_H
#define DAMN_SKYBOX_H
#include <irrlicht/irrlicht.h>
#include "../Globals/Globals.h"
#include "../lemon_functions/lemon_functions.h"

namespace lemon
{
    class LSkyBox
    {
    public:
        LSkyBox();
        ~LSkyBox();
        enum{
            TOP,
            BOTTOM,
            LEFT,
            RIGHT,
            FRONT,
            BACK
        };

        bool setVisible(bool isVisible);





    private:
        //场景节点
        irr::scene::ISceneNode* skyBoxSceneNode = nullptr;
        //skybox的四个面
        irr::video::ITexture* topTexture = nullptr;
        irr::video::ITexture* bottomTexture = nullptr;
        irr::video::ITexture* leftTexture = nullptr;
        irr::video::ITexture* rightTexture = nullptr;
        irr::video::ITexture* frontTexture = nullptr;
        irr::video::ITexture* backTexture = nullptr;
        //设置每个面的纹理
        bool setTexture(const char * texturePath,const int surfaceId);
        //设置场景节点
        bool setSkyBoxSceneNode();





    };
}



#endif //DAMN_SKYBOX_H
