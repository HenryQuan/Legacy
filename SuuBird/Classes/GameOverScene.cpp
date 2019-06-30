//
//  GameOverScene.cpp
//  SuuBird
//
//  Created by Henry on 13/7/14.
//
//

#include "GameOverScene.h"
#include "GameScene.h"

USING_NS_CC;

#pragma mark - 类定义
GameOver::GameOver()
{
}
GameOver::~GameOver()
{
}

#pragma mark - Scene定义
Scene* GameOver::createScene()
{
    //你懂得
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene -> addChild(layer);
    return scene;
}

#pragma mark - Scene初始化
bool GameOver::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    // 这里是为了触碰 我也不知道为什么 3.0 这么变态！！
    auto listener = EventListenerTouchOneByOne::create();
    listener -> onTouchBegan = CC_CALLBACK_2(GameOver::onTouchBegan, this);
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    // It is easy ^_^
    initData();
    
    return true;
}

#pragma mark - 各种初始化。。。
void GameOver::initData()
{
    Size deviceSize = Director::getInstance() -> getWinSize();
    
    currentScore = UserDefault::getInstance() -> getIntegerForKey("CurrentScore");
    bestScore = UserDefault::getInstance() -> getIntegerForKey("BestScore");
    
    if (currentScore > bestScore)
    {
        bestScore = currentScore;
    }
    
    //黑背景
    auto backGround = LayerColor::create(Color4B(Color3B(0.f, 0.f, 0.f)));
    backGround -> setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    this -> addChild(backGround);
    CCLOG("backGround");
    
    //文字 不知为何只能有四行 多了显示不出来
    auto Text = Label::createWithSystemFont("", "STHeitiK-Light", 128.f);
    Text -> setString(StringUtils::format("%d", currentScore));
    Text -> setColor(Color3B::WHITE);
    Text -> setPosition(deviceSize.width / 2, deviceSize.height *0.75);
    this -> addChild(Text);
    
    auto bestScoreLabel = Label::createWithSystemFont("", "STHeitiK-Light", 68.f);
    bestScoreLabel -> setString(StringUtils::format("Best: %d", bestScore));
    bestScoreLabel -> setColor(Color3B::WHITE);
    bestScoreLabel -> setPosition(deviceSize.width / 2, deviceSize.height /2);
    this -> addChild(bestScoreLabel);
    
    UserDefault::getInstance() -> setIntegerForKey("BestScore", bestScore);
}

void GameOver::GoBackGame()
{
    auto scene = Game::createScene();
    Director::getInstance() -> replaceScene(scene);
}

bool GameOver::onTouchBegan(Touch *touch, Event *unused_event)
{
    GameOver::GoBackGame();
    return true;
}