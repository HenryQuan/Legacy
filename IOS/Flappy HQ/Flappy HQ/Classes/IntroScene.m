//
//  IntroScene.m
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright HenryQuan 2014年. All rights reserved.
//
// -----------------------------------------------------------------------

#import "IntroScene.h"
#import "TapToStart.h"
#import "AboutScene.h"

@implementation IntroScene
{
    CCSprite *backGround;
    CCSprite *FlappyHQ;
    
    CCSprite *grass;
    CCSprite *grassNext;
    
    CCButton *about;
    CCButton *startGame;
    
    CCSpriteFrame *aboutFrame;
    CCSpriteFrame *startGameFrame;
    
    CCLabelTTF *HQ;
    
    CCPhysicsNode *_physicsNode;
    CCNode *outLine;
    
    CCSprite *bird;
}


+ (IntroScene *)scene
{
	return [[self alloc] init];
}

- (id)init
{
    self = [super init];
    if (!self) return(nil);
    
    //Set the world touchable
    self.userInteractionEnabled = YES;
    
    //Adding a background picture
    backGround = [CCSprite spriteWithImageNamed:@"background.png"];
    backGround.position = ccp(self.contentSize.width / 2, self.contentSize.height / 2);
    [self addChild:backGround];
    
    _physicsNode = [CCPhysicsNode node];
    _physicsNode.gravity = ccp(0, -980.f);
    _physicsNode.debugDraw = NO;
    [self addChild:_physicsNode];
    
    CGRect worldRect = CGRectMake(0, 0, [CCDirector sharedDirector].viewSize.width, [CCDirector sharedDirector].viewSize.height);
    outLine = [CCNode node];
    outLine.physicsBody = [CCPhysicsBody bodyWithPolylineFromRect:worldRect cornerRadius:0];
    outLine.physicsBody.friction = 1.0f;
    outLine.physicsBody.elasticity = 0.5f;
    outLine.physicsBody.type = CCPhysicsBodyTypeStatic;
    [_physicsNode addChild:outLine];
    
    //Adding the grass
    grass = [CCSprite spriteWithImageNamed:@"grass.png"];
    grass.anchorPoint = ccp(0, 0);
    grass.position = ccp(0, 0);
    grass.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, grass.contentSize} cornerRadius:0.0f];
    grass.physicsBody.friction = 1.0f;
    grass.physicsBody.elasticity = 0.5f;
    grass.physicsBody.type = CCPhysicsBodyTypeStatic;
    [_physicsNode addChild:grass];
    
    //Adding grassNext
    grassNext = [CCSprite spriteWithImageNamed:@"grass.png"];
    grassNext.anchorPoint = ccp(0, 0);
    grassNext.position = ccp(self.contentSize.width, 0);
    grassNext.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, grassNext.contentSize} cornerRadius:0.0f];
    grassNext.physicsBody.friction = 1.0f;
    grassNext.physicsBody.elasticity = 0.5f;
    grassNext.physicsBody.type = CCPhysicsBodyTypeStatic;
    [_physicsNode addChild:grassNext];
    
    //Adding the title Flappy HQ
    FlappyHQ = [CCSprite spriteWithImageNamed:@"FlappyHQ.png"];
    FlappyHQ.position = ccp(self.contentSize.width / 2, self.contentSize.height / 2 + 125);
    [self addChild:FlappyHQ];
    
    //Adding about button
    aboutFrame = [CCSpriteFrame frameWithImageNamed:@"about.png"];
    about = [CCButton buttonWithTitle:@"" spriteFrame:aboutFrame];
    about.position = ccp(self.contentSize.width / 2 + 80, 130);
    [about setTarget:self selector:@selector(goToAbout:)];
    [self addChild:about];
    
    //Adding startgame button
    startGameFrame = [CCSpriteFrame frameWithImageNamed:@"startgame.png"];
    startGame = [CCButton buttonWithTitle:@"" spriteFrame:startGameFrame];
    startGame.position = ccp(self.contentSize.width / 4, 130);
    [startGame setTarget:self selector:@selector(gameStart:)];
    [self addChild:startGame];
    
    //Adding HQ label
    HQ = [CCLabelTTF labelWithString:@"HQ 2014" fontName:@"Arial" fontSize:18.0f];
    HQ.position = ccp(self.contentSize.width / 2, 10);
    [self addChild:HQ];
    
    bird = [CCSprite spriteWithImageNamed:@"bird.png"];
    bird.positionType = CCPositionTypeNormalized;
    bird.position = ccp(0.5f, 0.5f);
    [self addChild:bird];
    
    //Let the Grass move
    [self schedule:@selector(moveGrass:) interval:0.002f];
    
    CCLOG(@"Background, Buttons, grass, label added");
    
	return self;
}

- (void)gameStart:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[TapToStart scene] withTransition:[CCTransition transitionFadeWithColor:[CCColor whiteColor] duration:1.0f]];
    CCLOG(@"Go to TapToStartScene");
}

- (void)goToAbout:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[AboutScene scene] withTransition:[CCTransition transitionPushWithDirection:CCTransitionDirectionLeft duration:0.5f]];
    CCLOG(@"Got to AboutScene");
}

- (void)moveGrass:(CCTime)delta
{
    CCActionMoveTo *moveGrass;
    CCActionMoveTo *moveGrassNext;
    
    moveGrass = [CCActionMoveTo actionWithDuration:0.002f position:ccp(grass.position.x - 0.2, grass.position.y)];
    [grass runAction:moveGrass];
    
    moveGrassNext = [CCActionMoveTo actionWithDuration:0.002f position:ccp(grassNext.position.x - 0.2, grass.position.y)];
    [grassNext runAction:moveGrassNext];
    
    if (grass.position.x <= 0)
    {
        grassNext.position = ccp(grass.position.x + self.contentSize.width, grass.position.y);
    }
    if (grassNext.position.x <= 0)
    {
        grass.position = ccp(grassNext.position.x + self.contentSize.width, grassNext.position.y);
    }
}

@end
