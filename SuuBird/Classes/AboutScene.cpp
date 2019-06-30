//
//  AboutScene.cpp
//  SuuBird
//
//  Created by Henry on 12/7/14.
//
//

#include "AboutScene.h"
#include "WelcomeScene.h"

USING_NS_CC;

#pragma mark - 类定义
About::About()
{
}

About::~About()
{
}

#pragma mark - Scene定义
Scene* About::createScene()
{
    //你懂得
    auto scene = Scene::create();
    auto layer = About::create();
    scene -> addChild(layer);
    return scene;
}

#pragma mark - Scene初始化
bool About::init()
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
void About::initData()
{
    Size deviceSize = Director::getInstance() -> getWinSize();
    
    //黑背景
    auto backGround = LayerColor::create(Color4B(Color3B(0.f, 0.f, 0.f)));
    backGround -> setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    this -> addChild(backGround);
    CCLOG("backGround");
    
    //文字 不知为何只能有四行 多了显示不出来
    auto Text = Label::createWithSystemFont("A game made by Henry\nspecial thanks\nFool Bird for the name\nDesigned By Suu", "STHeitiK-Light", 36.f);
    Text -> setColor(Color3B::WHITE);
    Text -> setPosition(deviceSize.width / 2, deviceSize.height / 2);
    this -> addChild(Text);
    
    //Back按钮，不知为毛那个位置。。。 很难搞。。。 想砸电脑 ＋ 10086
    auto backButtonText = Label::createWithSystemFont("Back", "STHeitiK-Light", 48.f);
    auto backButton = MenuItemLabel::create(backButtonText, CC_CALLBACK_0(About::GoBackWelcome, this));
    backButton -> setAnchorPoint(Point::ANCHOR_MIDDLE);
    backButton -> setPosition(0 - deviceSize.width *0.4, 0 + deviceSize.height * 0.4);
    
    //扔到一个 菜单里 ， 好麻烦啊啊啊啊啊啊啊啊啊啊啊啊啊啊
    auto menu = Menu::create(backButton, NULL);
    this -> addChild(menu);
}

#pragma mark - 回去的Callback
void About::GoBackWelcome()
{
    CCLOG("WelcomeScene");
    //切换到WelcomeScene
    auto scene = Welcome::createScene();
    Director::getInstance() -> replaceScene(scene);
}