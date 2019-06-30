//
//  GameOverScene.m
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "GameOverScene.h"
#import "TapToStart.h"

@implementation GameOverScene
{
    CCNodeColor *background;
    
    CCLabelTTF *yourScore;
    CCLabelTTF *scoreLabel;
    CCLabelTTF *bestScoreLabel;
    
    CCButton *tapToRestart;
    
    int bestscore;
    int currentscore;
}

+ (GameOverScene *)scene
{
	return [[self alloc] init];
}

- (id)init
{
    self = [super init];
    if (!self) return(nil);
    
    background = [CCNodeColor nodeWithColor:[CCColor blackColor]];
    [self addChild:background];
    
    bestscore = [[NSUserDefaults standardUserDefaults] integerForKey:@"bestscore"];
    currentscore = [[NSUserDefaults standardUserDefaults] integerForKey:@"currentscore"];
    
    if (currentscore > bestscore)
    {
        [[NSUserDefaults standardUserDefaults] setInteger:currentscore forKey:@"bestscore"];
    }
    
    bestscore = [[NSUserDefaults standardUserDefaults] integerForKey:@"bestscore"];
    currentscore = [[NSUserDefaults standardUserDefaults] integerForKey:@"currentscore"];
    
    yourScore = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"%i", currentscore] fontName:@"Arial" fontSize:80.f];
    yourScore.positionType = CCPositionTypeNormalized;
    yourScore.position = ccp(0.5f, 0.55f);
    [self addChild:yourScore];
    
    scoreLabel = [CCLabelTTF labelWithString:@"Your Score" fontName:@"Arial" fontSize:36.f];
    scoreLabel.positionType = CCPositionTypeNormalized;
    scoreLabel.position = ccp(0.5f, 0.7f);
    [self addChild:scoreLabel];
    
    bestScoreLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"Best:%d",bestscore] fontName:@"Arial" fontSize:32.f];
    bestScoreLabel.positionType = CCPositionTypeNormalized;
    bestScoreLabel.position = ccp(0.5f, 0.35f);
    [self addChild:bestScoreLabel];
    
    tapToRestart = [CCButton buttonWithTitle:@"Tap to restart" fontName:@"Arial" fontSize:28.f];
    tapToRestart.positionType = CCPositionTypeNormalized;
    tapToRestart.position = ccp(0.5f, 0.15f);
    [tapToRestart setTarget:self selector:@selector(tapToPlay:)];
    [self addChild:tapToRestart];
    
    [[NSUserDefaults standardUserDefaults] setInteger:0 forKey:@"currentscore"];
    
    return self;
}

- (void)tapToPlay:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[TapToStart scene] withTransition:[CCTransition transitionFadeWithColor:[CCColor whiteColor] duration:1.0f]];
}

@end
