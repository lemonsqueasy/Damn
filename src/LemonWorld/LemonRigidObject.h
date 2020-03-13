//
// Created by Mon Le on 2020/3/13.
//

#ifndef DAMN_LEMONRIGIDOBJECT_H
#define DAMN_LEMONRIGIDOBJECT_H

#include <irrBulletRigidBody.h>
#include <irrBulletGImpactMeshShape.h>
#include "irrlicht.h"

namespace lemon
{
    class LemonRigidObject
    {
    public:
        LemonRigidObject(const char* name,const char* meshPath, float mass, bool flagOfFPlayer, bool selfLight = false,
                         irr::core::vector3df initPosition  = {0, 0, 0},
                         irr::core::vector3df initRotition  = {0, 0, 0},
                         irr::core::vector3df initScale  = {1, 1, 1}
                         );

        ~LemonRigidObject();

        virtual void onAction();//动作回调

        const char* getName() const;//获取名称

        const char* getMeshPath() const;//获取网表模型路径

        irr::core::vector3df getPosition() const;//获取坐标
        bool setPosition(irr::core::vector3df position);//设置坐标

        irr::core::vector3df getRotation() const;//获取旋转
        bool setRotation(irr::core::vector3df rotation);//设置旋转

        irr::core::vector3df getScale() const;//获取缩放
        bool setScale(irr::core::vector3df scale);//设置缩放

        bool isFPlayer() const;//查询主角
        bool setFPlayer(bool flagOfFPlayer);//设置主角

        float getMass() const;//获取质量

        bool setFriction(float friction);//设置摩擦系数

        void completeOb(
                irr::scene::IMesh* iMesh,
                irr::scene::IMeshSceneNode* iMeshSceneNode,
                IGImpactMeshShape* igImpactMeshShape,
                IRigidBody* iRigidBody
            );

        irr::core::vector3df getInitPosition() const;
        irr::core::vector3df getInitRotition() const;
        irr::core::vector3df getInitScale() const;
        bool isSelfLight() const;


    private:
        static constexpr float ERR_VALUE = -99999;
        const char* name;
        const char* meshPath;
        float mass;
        irr::scene::IMesh* iMesh;
        irr::scene::IMeshSceneNode* iMeshSceneNode;
        IGImpactMeshShape* igImpactMeshShape;
        IRigidBody* iRigidBody;
        bool flagOfFPlayer;

        irr::core::vector3df initPosition;
        irr::core::vector3df initRotition;
        irr::core::vector3df initScale;
        bool flagSelfLight;

    };
}



#endif //DAMN_LEMONRIGIDOBJECT_H
