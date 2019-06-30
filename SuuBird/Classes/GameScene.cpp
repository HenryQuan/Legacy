//
//  GameScene.cpp
//  SuuBird
//
//  Created by Henry on 13/7/14.
//
//

#include "GameScene.h"
#include "GameOverScene.h"

// 这里不用变
#define maxY 300.0f
#define minY 40.f

USING_NS_CC;

#pragma mark - 类定义
Game::Game()
{
}

Game::~Game()
{
}

#pragma mark - Scene定义
Scene* Game::createScene()
{
    // 建立一个有Physics的Scene 。。。 别问我为毛这样
    auto scene = Scene::createWithPhysics();
    // 就是那个红红的框
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    // 重力设定。。。为毛是 负的980
    scene->getPhysicsWorld()->setGravity(Vect(0, -980.665f));
    
    // 你懂得
    auto layer = Game::create();
    layer->setPhyWorld(scene->getPhysicsWorld());
    
    scene -> addChild(layer);
    return scene;
}

#pragma mark - Scene初始化
bool Game::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    // 这里是为了触碰 我也不知道为什么 3.0 这么变态！！
    auto listener = EventListenerTouchOneByOne::create();
    listener -> onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    // 下面👇的一堆的简写
    initData();
    
    // Collision
    auto contactLister = EventListenerPhysicsContact::create();
    contactLister -> onContactBegin = CC_CALLBACK_1(Game::onContactBegin, this);
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(contactLister, this);
    
    return true;
}

#pragma mark - 各种初始化
void Game::initData()
{
    //全都加载上
    loadPhysicsWorld();
    loadBackground();
    loadBird();
    loadPillar();
    loadGrass();
    loadBestScore();
    loadCurrentScore();
    loadTimesNumber();
    
    // 关闭加分
    addScore = true;
    
    // 计时器
    this->schedule(schedule_selector(Game::moveScene), .0025f);
	this->scheduleUpdate();
}

#pragma mark - 物理世界
void Game::loadPhysicsWorld()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 搞一个边缘
	auto edgeSp = Sprite::create();
    // 这里是搞摩擦力啥的，和cocos2d的用法有差别
    auto edgeMaterial = PhysicsMaterial::PhysicsMaterial(0.f, 0.5f, 1.0f);
    auto body = PhysicsBody::createEdgeBox(visibleSize, edgeMaterial, 3);
    // 放到中间
    edgeSp->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeSp->setPhysicsBody(body);
    this->addChild(edgeSp);
}

#pragma mark - 背景图片
void Game::loadBackground()
{
    //背景 蓝色
    auto backGround = LayerColor::create(Color4B(Color3B(103.f, 204.f, 250.f)));
    // 坐标点左下角，就不用SetPosition了
    backGround -> setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    this -> addChild(backGround);
}

#pragma mark - 你的那个鸟
void Game::loadBird()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 你的鸟 SuuBird 🐦
    theBird = Sprite::createWithSpriteFrameName("thebird.png");
    theBird -> setPosition(visibleSize.width * 0.25, visibleSize.height / 2);
    theBird -> setPhysicsBody(PhysicsBody::createBox(Size(theBird -> getContentSize().width - 10, theBird -> getContentSize().height - 10)));
    // 不会翻转
    theBird -> getPhysicsBody() -> setRotationEnable(false);
    theBird -> getPhysicsBody() -> setTag(1);
    theBird -> getPhysicsBody() -> setCategoryBitmask(1);
    theBird -> getPhysicsBody() -> setContactTestBitmask(-1);
    theBird -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(theBird);
    
}

#pragma mark - 管子 一共4个
void Game::loadPillar()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 计算随机数
    rangeY = maxY - minY;
    randomY = (arc4random() % rangeY) + minY;
    randomYNext = (arc4random() % rangeY) + minY;
    
    // 你懂得为啥要两倍
    intervalDistance = 220.f;
    
    // 上面柱子
    theTopPillar = Sprite::createWithSpriteFrameName("pillar.png");
    // 改这个根本没用
    theTopPillar -> setAnchorPoint(Vec2(0, 0));
    // 连位置都要琢磨一下
    theTopPillar -> setPosition(theTopPillar -> getContentSize().width / 2 + visibleSize.width, visibleSize.height - randomY);
    theTopPillar -> setPhysicsBody(PhysicsBody::createBox(theTopPillar -> getContentSize()));
    // 改成静止，要不然 就 呵呵😄了
    theTopPillar -> getPhysicsBody() -> setDynamic(false);
    theTopPillar -> getPhysicsBody() -> setTag(2);
    theTopPillar -> getPhysicsBody() -> setCategoryBitmask(2);
    theTopPillar -> getPhysicsBody() -> setContactTestBitmask(-1);
    theTopPillar -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(theTopPillar);
    
    // 同上
    theBottomPillar = Sprite::createWithSpriteFrameName("pillar.png");
    theBottomPillar -> setAnchorPoint(Vec2(0, 0));
    theBottomPillar -> setPosition(visibleSize.width + theBottomPillar -> getContentSize().width / 2,
                                   visibleSize.height - randomY - intervalDistance - theBottomPillar -> getContentSize().height);
    theBottomPillar -> setPhysicsBody(PhysicsBody::createBox(theBottomPillar -> getContentSize()));
    theBottomPillar -> getPhysicsBody() -> setDynamic(false);
    theBottomPillar -> getPhysicsBody() -> setTag(3);
    theBottomPillar -> getPhysicsBody() -> setCategoryBitmask(3);
    theBottomPillar -> getPhysicsBody() -> setContactTestBitmask(-1);
    theBottomPillar -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(theBottomPillar);
    
    // 同上
    theTopPillarNext = Sprite::createWithSpriteFrameName("pillar.png");
    theTopPillarNext -> setAnchorPoint(Vec2(0, 0));
    // 必须要是randomYNext 要不然 前两个柱子 一样高
    theTopPillarNext -> setPosition(visibleSize.width * 1.5f  + theTopPillarNext -> getContentSize().width, visibleSize.height - randomYNext);
    theTopPillarNext -> setPhysicsBody(PhysicsBody::createBox(theTopPillarNext -> getContentSize()));
    theTopPillarNext -> getPhysicsBody() -> setDynamic(false);
    theTopPillarNext -> getPhysicsBody() -> setTag(4);
    theTopPillarNext -> getPhysicsBody() -> setCategoryBitmask(4);
    theTopPillarNext -> getPhysicsBody() -> setContactTestBitmask(-1);
    theTopPillarNext -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(theTopPillarNext);
    
    // 同上
    theBottomPillarNext = Sprite::createWithSpriteFrameName("pillar.png");
    theBottomPillarNext -> setAnchorPoint(Vec2(0, 0));
    theBottomPillarNext -> setPosition(visibleSize.width * 1.5f + theBottomPillarNext -> getContentSize().width, visibleSize.height - randomYNext - intervalDistance - theBottomPillarNext -> getContentSize().height);
    theBottomPillarNext -> setPhysicsBody(PhysicsBody::createBox(theBottomPillarNext -> getContentSize()));
    theBottomPillarNext -> getPhysicsBody() -> setDynamic(false);
    theBottomPillarNext -> getPhysicsBody() -> setTag(5);
    theBottomPillarNext -> getPhysicsBody() -> setCategoryBitmask(5);
    theBottomPillarNext -> getPhysicsBody() -> setContactTestBitmask(-1);
    theBottomPillarNext -> getPhysicsBody() -> setCollisionBitmask(-1);    this -> addChild(theBottomPillarNext);
}

#pragma mark - 草，草下一个
void Game::loadGrass()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 可爱的小草
    grass = Sprite::createWithSpriteFrameName("grass.png");
    auto grassMaterial = PhysicsMaterial::PhysicsMaterial(0.f, 0.5f, 1.0f);
    // 好像加了 Physics 的都没用了
    grass -> setAnchorPoint(Vec2(0, 0));
    //这里我把草的高度减半， 要不然会挡住下面的柱子
    grass -> setPosition(Vec2(visibleSize.width/2, 0));
    grass -> setPhysicsBody(PhysicsBody::createBox(grass -> getContentSize(), grassMaterial));
    // 会动就出事了。。。 你懂得
    grass -> getPhysicsBody() -> setDynamic(false);
    grass -> getPhysicsBody() -> setTag(6);
    grass -> getPhysicsBody() -> setCategoryBitmask(6);
    grass -> getPhysicsBody() -> setContactTestBitmask(-1);
    grass -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(grass);
    
    //同上
    grassNext = Sprite::createWithSpriteFrameName("grass.png");
    auto grassNextMaterial = PhysicsMaterial::PhysicsMaterial(0.f, 0.5f, 1.0f);
    grassNext -> setAnchorPoint(Vec2(0, 0));
    grassNext -> setPosition(Vec2(visibleSize.width * 1.5, 0));
    grassNext -> setPhysicsBody(PhysicsBody::createBox(grassNext -> getContentSize(), grassNextMaterial));
    grassNext -> getPhysicsBody() -> setDynamic(false);
    grassNext -> getPhysicsBody() -> setTag(7);
    grassNext -> getPhysicsBody() -> setCategoryBitmask(7);
    grassNext -> getPhysicsBody() -> setContactTestBitmask(-1);
    grassNext -> getPhysicsBody() -> setCollisionBitmask(-1);
    this -> addChild(grassNext);
}

#pragma mark - 最高分
void Game::loadBestScore()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    bestscore = UserDefault::getInstance() -> getIntegerForKey("BestScore");
    // 原创部分 1
    auto bestLabel = Label::createWithSystemFont("", "STHeitiK-Light", 48.f);
    // 这个在左上角
    bestLabel -> setString(StringUtils::format("Best : %d", bestscore));
    bestLabel -> setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    bestLabel -> setPosition(0, visibleSize.height);
    this -> addChild(bestLabel);
}

#pragma mark - 打完一次的分 给GameOverScene做准备
void Game::loadCurrentScore()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 为了GameOverScene
    scoreLabel = Label::createWithSystemFont("0", "STHeitiK-Light", 128.f);
    scoreLabel -> setPosition(visibleSize.width / 2, visibleSize.height * 0.85);
    this -> addChild(scoreLabel);
}

#pragma mark - 几倍分数
void Game::loadTimesNumber()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 原创部分 2
    timesNumber =Label::createWithSystemFont("x1", "STHeitiK-Light", 48.f);
    // 放右上角
    timesNumber -> setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    timesNumber -> setPosition(visibleSize.width, visibleSize.height);
    this -> addChild(timesNumber);
}

#pragma mark - 触碰事件 就是让鸟飞高那么一点点
bool Game::onTouchBegan(Touch *touch, Event *unused_event)
{
    CCLOG("Yeah");
    // 按一下屏幕 就飞那么一点点
    theBird -> getPhysicsBody() ->setVelocity(Vect(0, 300));
    return true;
}

#pragma mark - 移动场景
void Game::moveScene(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 0.2 太尼玛慢了 所以 直接 16倍 哈哈哈哈。。。
    auto moveTopPillar = MoveTo::create(0.0025f, Vec2(theTopPillar -> getPosition().x - 3.2, theTopPillar -> getPosition().y));
    theTopPillar -> runAction(moveTopPillar);
    
    auto moveBottomPillar = MoveTo::create(0.0025f, Vec2(theBottomPillar -> getPosition().x - 3.2, theBottomPillar -> getPosition().y));
    theBottomPillar -> runAction(moveBottomPillar);
    
    auto moveTopPillarNext = MoveTo::create(0.0025f, Vec2(theTopPillarNext -> getPosition().x - 3.2, theTopPillarNext -> getPosition().y));
    theTopPillarNext -> runAction(moveTopPillarNext);
    
    auto moveBottomPillarNext = MoveTo::create(0.0025f, Vec2(theBottomPillarNext -> getPosition().x - 3.2, theBottomPillarNext -> getPosition().y));
    theBottomPillarNext -> runAction(moveBottomPillarNext);
    
    // 循环的实现
    if  (theTopPillar -> getPosition().x < -theTopPillar -> getContentSize().width/2)
    {
        randomY = (arc4random() % rangeY) + minY;
        
        theTopPillar -> setPosition(theTopPillar -> getContentSize().width / 2 + visibleSize.width, visibleSize.height - randomY);
        theBottomPillar -> setPosition(visibleSize.width + theBottomPillar -> getContentSize().width / 2,
                                       visibleSize.height - randomY - intervalDistance - theBottomPillar -> getContentSize().height);
        
        addScore = true;
    }
    
    if (theTopPillarNext -> getPosition().x < -theTopPillarNext -> getContentSize().width/2)
    {
        randomYNext = (arc4random() % rangeY) + minY;
        
        theTopPillarNext -> setPosition(theTopPillarNext-> getContentSize().width / 2 + visibleSize.width, visibleSize.height - randomYNext);
        theBottomPillarNext -> setPosition(visibleSize.width + theBottomPillarNext -> getContentSize().width / 2,
                                           visibleSize.height - randomYNext - intervalDistance - theBottomPillarNext -> getContentSize().height);
        
        addScore = true;
    }
    
    // 加分
    if (theTopPillar -> getPosition().x < theBird -> getPosition().x || theTopPillarNext -> getPosition().x < theBird -> getPosition().x)
    {
        if (addScore == true)
        {
            // 记录过了的柱子数
            passedNum += 1;
            
            // 小于 11 的话 特许处理
            if (passedNum <= 11)
            {
                if (passedNum == 11)
                {
                    timesNum += 1;
                }
            }
            // 大过11
            if (passedNum > 11)
            {
                //得到个位的数字
                passedNumDigit = passedNum - ((passedNum / 10)* 10);
                // 如果是 1 的话 倍数加上一
                if (passedNumDigit == 1)
                {
                    timesNum += 1;
                }
            }
            
            // 分数算法
            score += 1 * timesNum;
            // 改变分数
            scoreLabel -> setString(StringUtils::format("%d", score));
            // 改变倍数
            timesNumber -> setString(StringUtils::format("x%d", timesNum));
            addScore = false;
        }
    }
    
    // 草地的循环实现
    auto moveGrassA = MoveTo::create(0.0025f, Vec2(grass -> getPosition().x - 3.2, grass -> getPosition().y));
    grass -> runAction(moveGrassA);
    auto moveGrassB = MoveTo::create(0.0025f, Vec2(grassNext -> getPosition().x - 3.2, grassNext -> getPosition().y));
    grassNext -> runAction(moveGrassB);
    
    if (grass -> getPosition().x <= visibleSize.width / 2)
    {
        grassNext -> setPosition(grass -> getPosition().x + visibleSize.width, grass -> getPosition().y);
    }
    
    if (grassNext -> getPosition().x <= visibleSize.width / 2)
    {
        grass -> setPosition(grassNext -> getPosition().x + visibleSize.width, grassNext -> getPosition().y);
    }
}

bool Game::onContactBegin(PhysicsContact& contact)
{
    GameOver();
    return true;
}

void Game::GameOver()
{
    UserDefault::getInstance() -> setIntegerForKey("CurrentScore", score);
    auto scene = GameOver::createScene();
    Director::getInstance() -> replaceScene(scene);
}
