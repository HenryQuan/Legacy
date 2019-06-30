#include "AppDelegate.h"
#include "WelcomeScene.h"

USING_NS_CC;

#define ScreenWidth Director::getInstance()->getVisibleSize().width
#define ScreenHeight Director::getInstance()->getVisibleSize().height

#pragma mark - 类定义
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

#pragma mark - 完成加载后
bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        //这里必须改成这样，要不然那窗口都不知道真么样的说 Suu
        //这个只是Demo ， 想加强自己搞去 ， 作为小白的我只能帮到这里了 哈哈哈哈哈哈
        glview = GLView::createWithRect("SuuBird Demo", Rect(0, 0, 640, 960));
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);
    
    // 就是各种自动适应
    // ＃if ＃elif ＃endif 真尼玛好用！！
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // 如果是 iPhone 4 以前的设备
    if (ScreenHeight < 960)
    {
        glview -> setDesignResolutionSize(640, 960, ResolutionPolicy::NO_BORDER);
    }
    // 如果不是iPhone 或者 iPod Touch
    if (ScreenWidth > 640)
    {
        glview -> setDesignResolutionSize(640, 960, ResolutionPolicy::EXACT_FIT);
    }
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // 安卓的全部自动适合，反正每个手机的分辨率都尼玛不一样！！！
    glview -> setDesignResolutionSize(640, 960, ResolutionPolicy::EXACT_FIT);
#elif (!CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID && !CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    // 其他平台 也是， MAC，Win32，Linux 等。。。
    glview -> setDesignResolutionSize(640, 960, ResolutionPolicy::EXACT_FIT);
#endif
    
    // 和IOS的用法一样。。。 很神奇
    if (!UserDefault::getInstance() -> getBoolForKey("FirstLaunchSuuBird"))
    {
        UserDefault::getInstance() -> setBoolForKey("FirstLaunchSuuBird", true);
        //就是玩完一次后的分数
        UserDefault::getInstance() -> setIntegerForKey("CurrentScore", 0);
        //这个是最好的得分
        UserDefault::getInstance() -> setIntegerForKey("BestScore", 0);
    }

    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // Read in the spriteframe
    SpriteFrameCache::getInstance() -> addSpriteFramesWithFile("SuuBird@2x.plist");
    
    // create a scene. it's an autorelease object
    auto scene = Welcome::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

#pragma mark - 就是你懂得 反正游戏要停止
// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

#pragma mark - 饿这个就是让游戏继续运行
// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
