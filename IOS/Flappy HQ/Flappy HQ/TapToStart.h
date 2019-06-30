//
//  TapToStart.h
//  Flappy HQ
//
//  Created by 权一恒 on 28/05/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "cocos2d.h"
#import "cocos2d-ui.h"

@interface TapToStart : CCScene
<CCPhysicsCollisionDelegate>

+ (TapToStart *)scene;
- (id)init;

@end
