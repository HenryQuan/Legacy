//
//  AboutScene.m
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "AboutScene.h"
#import "IntroScene.h"

@implementation AboutScene
{
    CCNodeColor *background;
    
    CCLabelTTF *About;
    CCLabelTTF *Suu;
    CCLabelTTF *HQ;
    CCLabelTTF *Master;
    
    CCButton *backButton;
    CCSpriteFrame *backImage;
}

+ (AboutScene *)scene
{
    return [[self alloc] init];
}

- (id)init
{
    self = [super init];
    if (!self) return(nil);
    
    //Adding background
    background = [CCNodeColor nodeWithColor:[CCColor blackColor]];
    [self addChild:background];
    
    //Adding title "About"
    About = [CCLabelTTF labelWithString:@"About" fontName:@"Arial" fontSize:24.0f];
    About.positionType = CCPositionTypeNormalized;
    About.position = ccp(0.5f, 0.95f);
    [self addChild:About];
    
    //Adding sb Suu
    Suu = [CCLabelTTF labelWithString:@"Image resources from Flappy Bird\nSpecial thanks to Suu\n\nAlthough he is stupid,\nhis code really helped me a lot\n\nby HenryQuan\n1/6/2014" fontName:@"Arial" fontSize:16.f];
    Suu.positionType = CCPositionTypeNormalized;
    Suu.position = ccp(0.5f, 0.5f);
    [self addChild:Suu];
    
    //Adding version
    HQ = [CCLabelTTF labelWithString:@"version: 1.2" fontName:@"Arial" fontSize:18.0f];
    HQ.positionType = CCPositionTypeNormalized;
    HQ.position = ccp(0.5f, 0.08f);
    [self addChild:HQ];
    
    Master = [CCLabelTTF labelWithString:@"Master told me to write 1.2" fontName:@"Arial" fontSize:14.0f];
    Master.positionType = CCPositionTypeNormalized;
    Master.position = ccp(0.5f, 0.05f);
    [self addChild:Master];
    
    //Adding Back Button
    backImage = [CCSpriteFrame frameWithImageNamed:@"back.png"];
    backButton = [CCButton buttonWithTitle:@"" spriteFrame:backImage];
    backButton.positionType = CCPositionTypeNormalized;
    backButton.position = ccp(0.1f, 0.95f);
    [backButton setTarget:self selector:@selector(BackToInfo:)];
    [self addChild:backButton];
    
    CCLOG(@"Done");
    
	return self;
}

- (void)BackToInfo:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[IntroScene scene] withTransition:[CCTransition transitionPushWithDirection:CCTransitionDirectionRight duration:0.5f]];
    CCLOG(@"Go back to intro");
}

@end
