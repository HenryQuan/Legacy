//
//  GameScene.m
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "GameScene.h"
#import "GameOverScene.h"
#import "IntroScene.h"
#import "HQ.h"

#define maxY 300.f
#define minY 40.f

@implementation GameScene
{
    CCSprite *background;
    
    CCSprite *grass;
    CCSprite *grassNext;
    
    CCSprite *topPillar;
    CCSprite *bottomPillar;
    CCSprite *topPillarNext;
    CCSprite *bottomPillarNext;
    
    CCPhysicsNode *_physicsNode;
    HQ *bird;
    
    int score;
    CCLabelTTF *scoreLabel;
    
    int bestScore;
    CCLabelTTF *bestLabel;
    
    CCNode *outLine;
    
    int rangeY;
    float randomY;
    float randomYNext;
    float betweenDistance;
    
    BOOL addScore;
    
    CCActionMoveTo *moveTopPillar;
    CCActionMoveTo *moveBottomPillar;
    CCActionMoveTo *moveTopPillarNext;
    CCActionMoveTo *moveBottomPillarNext;
    CCActionMoveTo *moveGrass;
    CCActionMoveTo *moveGrassNext;
}

+ (GameScene *)scene
{
	return [[self alloc] init];
}

- (id)init
{
    self = [super init];
    if (!self) return(nil);
    
    //Set the world touchablle
    self.userInteractionEnabled = YES;
    score = 0;
    
    //Adding Background
    background = [CCSprite spriteWithImageNamed:@"background.png"];
    background.position = ccp(self.contentSize.width / 2, self.contentSize.height / 2);
    [self addChild:background];
    
    //Adding Physiacnode
    _physicsNode = [CCPhysicsNode node];
    _physicsNode.gravity = ccp(0, -890.f);
    _physicsNode.debugDraw = NO;
    _physicsNode.collisionDelegate = self;
    [self addChild:_physicsNode];
    
    //Adding the outLine
    CGRect worldRect = CGRectMake(0, 0, [CCDirector sharedDirector].viewSize.width, [CCDirector sharedDirector].viewSize.height);
    outLine = [CCNode node];
    outLine.physicsBody = [CCPhysicsBody bodyWithPolylineFromRect:worldRect cornerRadius:0];
    outLine.physicsBody.friction = 1.0f;
    outLine.physicsBody.elasticity = 0.5f;
    outLine.physicsBody.type = CCPhysicsBodyTypeStatic;
    [_physicsNode addChild:outLine];
    
    //Adding the bird
    bird = [HQ spriteWithImageNamed:@"bird.png"];
    bird.position = ccp(self.contentSize.width/2 - 80, self.contentSize.height/2 + 50);
    bird.physicsBody = [CCPhysicsBody bodyWithRect:CGRectMake(0, 1, bird.contentSize.width-2, bird.contentSize.height-1) cornerRadius:0.0f];
    bird.userInteractionEnabled = YES;
    bird.physicsBody.allowsRotation = NO;
    bird.physicsBody.collisionGroup = @"birdGroup";
    bird.physicsBody.collisionType = @"birdCollision";
    bird.physicsBody.collisionCategories = @[@"bird"];
    [_physicsNode addChild:bird z:1];
    
    [bird.physicsBody applyForce:ccp(0, 0)];
    
    //Calculate the height
    rangeY = maxY - minY;
    randomY = (arc4random() % rangeY) + minY;
    randomYNext = (arc4random() % rangeY) + minY;
    
    //Set the distance between 2 pillars
    betweenDistance = 110.f;
    
    //Adding first toppillar
    topPillar = [CCSprite spriteWithImageNamed:@"bottomPillar.png"];
    topPillar.anchorPoint = ccp(0, 0);
    topPillar.position = ccp(self.contentSize.width, self.contentSize.height - randomY);
    topPillar.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, topPillar.contentSize} cornerRadius:0.0f];
    topPillar.physicsBody.type = CCPhysicsBodyTypeStatic;
    topPillar.physicsBody.collisionGroup = @"pillarGroup";
    topPillar.physicsBody.collisionType = @"pillarCollision";
    topPillar.physicsBody.collisionMask = @[@"bird"];
    [_physicsNode addChild:topPillar];
    
    //Adding first bottompillar
    bottomPillar = [CCSprite spriteWithImageNamed:@"topPillar.png"];
    bottomPillar.anchorPoint = ccp(0, 0);
    bottomPillar.position = ccp(self.contentSize.width, self.contentSize.height - randomY - betweenDistance - bottomPillar.contentSize.height);
    bottomPillar.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, bottomPillar.contentSize} cornerRadius:0.0f];
    bottomPillar.physicsBody.type = CCPhysicsBodyTypeStatic;
    bottomPillar.physicsBody.collisionGroup = @"pillarGroup";
    bottomPillar.physicsBody.collisionType = @"pillarCollision";
    bottomPillar.physicsBody.collisionMask = @[@"bird"];
    [_physicsNode addChild:bottomPillar];
    
    //Adding first toppillar
    topPillarNext = [CCSprite spriteWithImageNamed:@"bottomPillar.png"];
    topPillarNext.anchorPoint = ccp(0, 0);
    topPillarNext.position = ccp(self.contentSize.width * 1.5f + topPillarNext.contentSize.width/2, self.contentSize.height - randomYNext);
    topPillarNext.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, topPillarNext.contentSize} cornerRadius:0.0f];
    topPillarNext.physicsBody.type = CCPhysicsBodyTypeStatic;
    topPillarNext.physicsBody.collisionGroup = @"pillarGroup";
    topPillarNext.physicsBody.collisionType = @"pillarCollision";
    topPillarNext.physicsBody.collisionMask = @[@"bird"];
    [_physicsNode addChild:topPillarNext];
    
    //Adding first bottompillar
    bottomPillarNext = [CCSprite spriteWithImageNamed:@"topPillar.png"];
    bottomPillarNext.anchorPoint = ccp(0, 0);
    bottomPillarNext.position = ccp(self.contentSize.width * 1.5f + bottomPillarNext.contentSize.width/2,
                                    self.contentSize.height - randomYNext - betweenDistance - bottomPillarNext.contentSize.height);
    
    bottomPillarNext.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, bottomPillarNext.contentSize} cornerRadius:0.0f];
    bottomPillarNext.physicsBody.type = CCPhysicsBodyTypeStatic;
    bottomPillarNext.physicsBody.collisionGroup = @"pillarGroup";
    bottomPillarNext.physicsBody.collisionType = @"pillarCollision";
    bottomPillarNext.physicsBody.collisionMask = @[@"bird"];
    [_physicsNode addChild:bottomPillarNext];
    
    //Adding the grass
    grass = [CCSprite spriteWithImageNamed:@"grass.png"];
    grass.anchorPoint = ccp(0, 0);
    grass.position = ccp(0, 0);
    grass.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, grass.contentSize} cornerRadius:0.0f];
    grass.physicsBody.friction = 1.0f;
    grass.physicsBody.elasticity = 0.5f;
    grass.physicsBody.type = CCPhysicsBodyTypeStatic;
    grass.physicsBody.collisionGroup = @"grassGroup";
    grass.physicsBody.collisionType = @"grassCollision";
    [_physicsNode addChild:grass];
    
    //Adding grassNext
    grassNext = [CCSprite spriteWithImageNamed:@"grass.png"];
    grassNext.anchorPoint = ccp(0, 0);
    grassNext.position = ccp(self.contentSize.width, 0);
    grassNext.physicsBody = [CCPhysicsBody bodyWithRect:(CGRect){CGPointZero, grassNext.contentSize} cornerRadius:0.0f];
    grassNext.physicsBody.friction = 1.0f;
    grassNext.physicsBody.elasticity = 0.5f;
    grassNext.physicsBody.type = CCPhysicsBodyTypeStatic;
    grassNext.physicsBody.collisionGroup = @"grassGroup";
    grassNext.physicsBody.collisionType = @"grassCollision";
    [_physicsNode addChild:grassNext];

    //Adding score label
    scoreLabel = [CCLabelTTF labelWithString:@"0" fontName:@"Arial" fontSize:56.f];
    scoreLabel.positionType = CCPositionTypeNormalized;
    scoreLabel.position = ccp(0.5f, 0.85f);
    [self addChild:scoreLabel];
    
    bestScore = [[NSUserDefaults standardUserDefaults] integerForKey:@"bestscore"];
    bestLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"Best:%d",bestScore] fontName:@"Arial" fontSize:16.f];
    bestLabel.positionType = CCPositionTypeNormalized;
    bestLabel.position = ccp(0.5f, 0.98f);
    [self addChild:bestLabel];
    
    addScore = YES;
    
    [self schedule:@selector(moveGame:) interval:0.002f];
    
	return self;
}

- (void)touchBegan:(UITouch *)touch withEvent:(UIEvent *)event
{
    bird.physicsBody.velocity = CGPointMake(0, 300);
    [[OALSimpleAudio sharedInstance]playEffect:@"sfx_wing.caf"];
}

- (void)moveGame:(CCTime)delta
{
    moveTopPillar = [CCActionMoveTo actionWithDuration:0.002f position:ccp(topPillar.position.x - 0.2, topPillar.position.y)];
    moveBottomPillar = [CCActionMoveTo actionWithDuration:0.002f position:ccp(bottomPillar.position.x - 0.2, bottomPillar.position.y)];
    moveTopPillarNext = [CCActionMoveTo actionWithDuration:0.002f position:ccp(topPillarNext.position.x - 0.2, topPillarNext.position.y)];
    moveBottomPillarNext = [CCActionMoveTo actionWithDuration:0.002f position:ccp(bottomPillarNext.position.x - 0.2, bottomPillarNext.position.y)];
    
    [topPillar runAction:moveTopPillar];
    [bottomPillar runAction:moveBottomPillar];
    [topPillarNext runAction:moveTopPillarNext];
    [bottomPillarNext runAction:moveBottomPillarNext];
    
    if (topPillar.position.x < - topPillar.contentSize.width)
    {
        randomY = (arc4random() % rangeY) + minY;
        topPillar.position = ccp(self.contentSize.width, self.contentSize.height - randomY);
        bottomPillar.position = ccp(self.contentSize.width, self.contentSize.height - randomY - betweenDistance - bottomPillar.contentSize.height);
        addScore = YES;
    }
    if (topPillarNext.position.x < -topPillarNext.contentSize.width)
    {
        randomYNext = (arc4random() % rangeY) + minY;
        topPillarNext.position = ccp(self.contentSize.width, self.contentSize.height - randomYNext);
        bottomPillarNext.position = ccp(self.contentSize.width, self.contentSize.height - randomYNext - betweenDistance - bottomPillarNext.contentSize.height);
        addScore = YES;
    }
    
    if (topPillar.position.x < bird.position.x || topPillarNext.position.x < bird.position.x)
    {
        if (addScore == YES)
        {
            score = score + 1;
            scoreLabel.string = [NSString stringWithFormat:@"%d",score];
            [[OALSimpleAudio sharedInstance]playEffect:@"sfx_point.aif"];
            addScore = NO;
        }
    }
    
    moveGrass = [CCActionMoveTo actionWithDuration:0.002f position:ccp(grass.position.x - 0.2, grass.position.y)];
    moveGrassNext = [CCActionMoveTo actionWithDuration:0.002f position:ccp(grassNext.position.x - 0.2, grassNext.position.y)];
    
    [grass runAction:moveGrass];
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

- (BOOL)ccPhysicsCollisionBegin:(CCPhysicsCollisionPair *)pair birdCollision:(CCNode *)bird grassCollision:(CCNode *)grassGround
{
    [[OALSimpleAudio sharedInstance]playEffect:@"sfx_hit.caf"];
    [self gameOver];
    [self gotoGameOverScene];
    return YES;
}

- (BOOL)ccPhysicsCollisionBegin:(CCPhysicsCollisionPair *)pair birdCollision:(CCNode *)bird pillarCollision:(CCNode *)pillar
{
    
    [[OALSimpleAudio sharedInstance]playEffect:@"sfx_hit.caf"];
    [self gameOver];
    [self gotoGameOverScene];
    return YES;
}

- (void)gameOver
{
    NSString *currentScore;
    currentScore = scoreLabel.string;
    
    [[NSUserDefaults standardUserDefaults] setInteger:[currentScore integerValue] forKey:@"currentscore"];
    self.userInteractionEnabled = NO;
    [self unscheduleAllSelectors];
}

- (void)gotoGameOverScene
{
    [[CCDirector sharedDirector] replaceScene:[GameOverScene scene] withTransition:[CCTransition transitionFadeWithColor:[CCColor whiteColor] duration:1.0f]];
}

@end
