//
//  GameOverScene.h
//  SuuBird
//
//  Created by Henry on 13/7/14.
//
//

#ifndef __SuuBird__GameOverScene__
#define __SuuBird__GameOverScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class GameOver : public Layer
{
public:
#pragma mark - 类定义
    GameOver();
    virtual ~GameOver();
    
#pragma mark - Scene定义
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(GameOver);
private:
    
#pragma mark - 你懂得
    void initData();
    
    void GoBackGame();
    
    bool onTouchBegan(Touch *touch, Event *unused_event);
    
    int currentScore;
    int bestScore;
};

#endif /* defined(__SuuBird__GameOverScene__) */
