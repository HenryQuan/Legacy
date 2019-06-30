//
//  WelcomeScene.h
//  SuuBird
//
//  Created by Henry on 5/7/14.
//
//

#ifndef __SuuBird__WelcomeScene__
#define __SuuBird__WelcomeScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Welcome : public Layer
{
public:
#pragma mark - 类定义
    Welcome();
    virtual ~Welcome();
    
#pragma mark - Scene定义
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(Welcome);
    
#pragma mark - 更种Sprite定义
    void initData();
    void loadBackground();
    void loadLogo();
    void loadButtons();
    void loadPhysicsWorld(PhysicsWorld*);
    
#pragma mark - callback
    void gameStart();
    void goToInfo();
};

#endif /* defined(__SuuBird__WelcomeScene__) */
