//
//  TapToStart.m
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "TapToStart.h"
#import "GameScene.h"

@implementation TapToStart
{
    CCSprite *background;;
    CCSprite *grass;
    CCSprite *grassNext;
    CCSprite *tap;
    CCSprite *bird;
    CCSprite *getready;
    
    CCPhysicsNode *_physicsNode;
}

+ (TapToStart *)scene
{
    return [[self alloc] init];
}

- (id)init
{
    self = [super init];
    if (!self) return(nil);
    
    //Set the World touchable
    self.userInteractionEnabled = YES;
    
    //Adding background
    background = [CCSprite spriteWithImageNamed:@"background.png"];
    background.position = ccp(self.contentSize.width / 2, self.contentSize.height / 2);
    [self addChild:background];
    
    _physicsNode = [CCPhysicsNode node];
    _physicsNode.gravity = ccp(0, -890.f);
    _physicsNode.debugDraw = NO;
    _physicsNode.collisionDelegate = self;
    [self addChild:_physicsNode];
    
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
    
    //Adding tap logo
    tap = [CCSprite spriteWithImageNamed:@"tap.png"];
    tap.position = ccp(self.contentSize.width / 2, self.contentSize.height / 2);
    [self addChild:tap];
    
    //Adding the bird
    bird = [CCSprite spriteWithImageNamed:@"bird.png"];
    bird.position = ccp(self.contentSize.width/2 - 80, self.contentSize.height/2 + 50);
    [self addChild:bird];
    
    //Adding getready logo
    getready = [CCSprite spriteWithImageNamed:@"getready.png"];
    getready.positionType = CCPositionTypeNormalized;
    getready.position = ccp(0.5f, 0.75f);
    [self addChild:getready];
    
    [self schedule:@selector(moveScene:) interval:0.002f];
    return self;
}

- (void)touchBegan:(UITouch *)touch withEvent:(UIEvent *)event
{
    [[CCDirector sharedDirector] replaceScene:[GameScene scene]];
    CCLOG(@"It's time to play!");
}

- (void)moveScene:(CCTime)delta
{
    CCActionMoveTo *moveGrass;
    CCActionMoveTo *moveGrassNext;
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
@end
