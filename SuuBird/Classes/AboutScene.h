//
//  AboutScene.h
//  SuuBird
//
//  Created by Henry on 12/7/14.
//
//

#ifndef __SuuBird__AboutScene__
#define __SuuBird__AboutScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class About : public Layer
{
public:
#pragma mark - 类定义
    About();
    virtual ~About();
    
#pragma mark - Scene定义
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(About);
    
#pragma mark - 你懂得
    void initData();
    
#pragma mark - Callback
    void GoBackWelcome();
};
#endif /* defined(__SuuBird__AboutScene__) */
