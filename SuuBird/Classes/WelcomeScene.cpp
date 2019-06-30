//
//  WelcomeScene.cpp
//  SuuBird
//
//  Created by Henry on 5/7/14.
//
//

#include "WelcomeScene.h"
#include "AboutScene.h"
#include "GameScene.h"

USING_NS_CC;

//四个点 一定要顺时针 要不然无限闪退 ＋ 不懂为啥 ＋ 想砸电脑
static const float GroundShape[] = {-320.f, -302.f, -320.f, 182.f, 320.f, -94.f, 320.f, -302.f};

#pragma mark - 累定义
Welcome::Welcome()
{
}

Welcome::~Welcome()
{
}

#pragma mark - Scene定义
Scene* Welcome::createScene()
{
    //你懂得
    auto scene = Scene::create();
    auto layer = Welcome::create();
    scene -> addChild(layer);
    return scene;
}

#pragma mark - Scene初始化
bool Welcome::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    // It is easy ^_^
    initData();
    
    return true;
}

#pragma mark - 你懂得
void Welcome::initData()
{
    //你懂得
    loadBackground();
    loadLogo();
    loadButtons();
}

#pragma mark - 加载背景
void Welcome::loadBackground()
{
    //背景 蓝色
    auto backGround = LayerColor::create(Color4B(Color3B(103.f, 204.f, 250.f)));
    backGround -> setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    addChild(backGround);
    CCLOG("backGround");
    
    //Ground
    auto ground = Sprite::createWithSpriteFrameName("ground.png");
    ground -> setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    ground -> setPosition(0, 0);
    this -> addChild(ground);
    CCLOG("ground");
}

#pragma mark - 你的SuuBird //难看死的LOGO
void Welcome::loadLogo()
{
    Size deviceSize = Director::getInstance() -> getWinSize();
    
    //SuuBird 难看死的LOGO
    auto titleSprite = Sprite::createWithSpriteFrameName("suubird.png");
    titleSprite -> setPosition(deviceSize.width/2, deviceSize.height * 0.75);
    this -> addChild(titleSprite);
}

#pragma mark - 开始游戏按钮 和 Info按钮
void Welcome::loadButtons()
{
    Size deviceSize = Director::getInstance() -> getWinSize();
    
    //开始游戏按钮
    auto startButtonText = Label::createWithSystemFont("TAP TO START", "STHeitiK-Light", 28.f);
    auto startButton = MenuItemLabel::create(startButtonText, CC_CALLBACK_0(Welcome::gameStart, this));
    startButton -> setPosition(Point(0, 0));
    
    //Info按钮
    auto infoButtonText = Label::createWithSystemFont("i", "STHeitiK-Light", 48.f);
    auto infoButton = MenuItemLabel::create(infoButtonText, CC_CALLBACK_0(Welcome::goToInfo, this));
    infoButton -> setPosition(-120, 0);
    
    //加载到一个菜单里，很麻烦呀啊啊啊啊啊啊
    auto menu = Menu::create(infoButton ,startButton, NULL);
    this -> addChild(menu);
}

#pragma mark - 开始游戏的Callback
void Welcome::gameStart()
{
    CCLOG("GameScene");
    //切换到GameScene
    auto scene = Game::createScene();
    Director::getInstance() -> replaceScene(scene);
}

#pragma mark - 去Info
void Welcome::goToInfo()
{
    CCLOG("AboutScene");
    //切换到AboutScene
    auto scene = About::createScene();
    Director::getInstance() -> replaceScene(scene);
}