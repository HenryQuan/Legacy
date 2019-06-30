//
//  GameScene.h
//  SuuBird
//
//  Created by Henry on 13/7/14.
//
//

#ifndef __SuuBird__GameScene__
#define __SuuBird__GameScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class Game : public Layer
{
public:
#pragma mark - 类定义
    Game();
    virtual ~Game();
    
#pragma mark - Scene定义

    static Scene* createScene();
    CREATE_FUNC(Game);
    
private:
    
#pragma mark - 各种Sprite定义
    virtual bool init();
    void initData();
    void loadBackground();
    void loadBird();
    void loadPillar();
    void loadGrass();
    void loadBestScore();
    void loadCurrentScore();
    void loadPhysicsWorld();
    void loadTimesNumber();
    
#pragma mark - 触碰事件
    void moveScene(float dt);
    bool onTouchBegan(Touch *touch, Event *unused_event);
    bool onContactBegin(PhysicsContact& contact);
    
    void GameOver();
   
#pragma mark - 物理世界
    void setPhyWorld(PhysicsWorld* world){m_world = world;}
	PhysicsWorld* m_world;
    
    // 鸟
    Sprite* theBird;
    // 草地
    Sprite* grass;
    Sprite* grassNext;
    // 四个管子
    Sprite* theTopPillar;
    Sprite* theBottomPillar;
    Sprite* theTopPillarNext;
    Sprite* theBottomPillarNext;
    // 分数 和 倍数
    Label* scoreLabel;
    Label* timesNumber;
    
    // 苦比的全局
    int rangeY;
    int randomY;
    int randomYNext;
    float intervalDistance;
    
    
    
    // 加分
    bool addScore = false;
    
    std::string ScoreString;
    
    int score = 0;
    int timesNum = 1;
    int passedNum = 0;
    int passedNumDigit;
    int bestscore;
};

#endif /* defined(__SuuBird__GameScene__) */
