#define PLIST_PATH @"/var/mobile/Library/Preferences/HenryQuan.MCPEMod.plist"
#import <substrate.h>
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

inline bool GetBool(NSString *key) 
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

// keep all ur items after u die
void die()
{
}

// no falling damage
float causeFallDamage()
{
return 0.f;
}

// full armor
int playergetArmorValue()
{
return 20;
}

// walking speed
float twospeed()
{
return 2.f;
}

float onespeed()
{
return 1.f;
}

float threespeed()
{
return 3.f;
}

float fourspeed()
{
return 4.f;
}

float eightspeed()
{
return 8.f;
}

// never die
void hurt()
{
}

// zombie never move
void nothing()
{
}

bool isSurvival()
{
return true;
}

bool isnotSurvival()
{
return false;
}

bool isCreative()
{
return true;
}

bool isnotCreative()
{
return false;
}

bool (*old__ZN11LocalPlayer10isSneakingEv)();


bool $__ZN11LocalPlayer10isSneakingEv() 
{


return true;


}


void (*old__ZN12CreativeMode13initAbilitiesER9Abilities)();
void (*old__ZN12SurvivalMode13initAbilitiesER9Abilities)();

void $__ZN12SurvivalMode13initAbilitiesER9Abilities()
{
old__ZN12SurvivalMode13initAbilitiesER9Abilities();
}

void $__ZN12CreativeMode13initAbilitiesER9Abilities()
{
old__ZN12CreativeMode13initAbilitiesER9Abilities();
}

UIButton *Sneaking;
UIButton *Gamemode;

UIButton *Handspeed;
//Hooking
%ctor
{
if (GetBool(@"keep")) 
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player3dieEP6Entity")),(void*)die,NULL);
}

if (GetBool(@"fall"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN3Mob15causeFallDamageEf")),(void*)causeFallDamage,NULL);
}

if (GetBool(@"armor"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player13getArmorValueEv")),(void*)playergetArmorValue,NULL);
}

if (GetBool(@"walk"))
{

}

if (GetBool(@"god"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player4hurtEP6Entityi")),(void*)hurt,NULL);
}

if (GetBool(@"zombiemove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Zombie6aiStepEv")),(void*)nothing,NULL);
}
if (GetBool(@"skeletonmove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN8Skeleton6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"spidermove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Spider6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"creepermove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN7Creeper6aiStepEv")),(void*)nothing,NULL);
}
if (GetBool(@"pigzombiemove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Zombie6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"endermanmove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN8EnderMan6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"sliverfishmove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN10Sliverfish6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"slimemove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN5Slime6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"chickenmove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN7Chicken6aiStepEv")),(void*)nothing,NULL);
}

if (GetBool(@"stevemove"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player6aiStepEv")),(void*)nothing,NULL);
}
if (GetBool(@"damage"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN12ItemInstance12hurtAndBreakEiP3Mob")),(void*)nothing,NULL);
}


if (GetBool(@"speedup"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN10DiggerItem15getDestroySpeedEP12ItemInstanceP4Tile")),(void*)eightspeed,NULL);
}
}

%hook minecraftpeAppDelegate
- (void)applicationDidBecomeActive:(id)application
{
%orig();

UIAlertView *alert = [[UIAlertView alloc]initWithTitle:@"MCPEMod 0.9.5" message:@"Hacked successfully by HenryQuan\n^_^" delegate:nil cancelButtonTitle:@"Enjoy!" otherButtonTitles:nil];
[alert show];
[alert release];

}

%end

%hook minecraftpeViewController
- (void)viewDidLoad
{


if (GetBool(@"sneak")||GetBool(@"fly")||GetBool(@"handspeed"))

{

%orig();
Sneaking = [UIButton buttonWithType:UIButtonTypeRoundedRect];

Sneaking.frame = CGRectMake(0, 90, 45, 25);



[Sneaking setTitle:@"1x" forState:UIControlStateNormal];

    
[Sneaking setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    
Sneaking.backgroundColor = [UIColor blackColor];

[Sneaking addTarget:self action:@selector(myButtonPressed) forControlEvents:UIControlEventTouchUpInside];

[[self view] addSubview:Sneaking];


UILabel *walking = [[UILabel alloc] initWithFrame:CGRectMake(0, 70, 60, 25)];
walking.text = @"walk";
[[self view] addSubview:walking];

Gamemode = [UIButton buttonWithType:UIButtonTypeRoundedRect];

Gamemode.frame = CGRectMake(0, 130, 45, 25);



[Gamemode setTitle:@"Sur" forState:UIControlStateNormal];

  
[Gamemode setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
   
Gamemode.backgroundColor = [UIColor blackColor];

[Gamemode addTarget:self action:@selector(modePressed) forControlEvents:UIControlEventTouchUpInside];

[[self view] addSubview:Gamemode];


UILabel *flying = [[UILabel alloc] initWithFrame:CGRectMake(0, 110, 60, 25)];
flying.text = @"fly";
[[self view] addSubview:flying];

Handspeed = [UIButton buttonWithType:UIButtonTypeRoundedRect];

Handspeed.frame = CGRectMake(0, 170, 45, 25);



[Handspeed setTitle:@"1x" forState:UIControlStateNormal];

  
[Handspeed setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
   
Handspeed.backgroundColor = [UIColor blackColor];

[Handspeed addTarget:self action:@selector(handPressed) forControlEvents:UIControlEventTouchUpInside];

[[self view] addSubview:Handspeed];


UILabel *hand = [[UILabel alloc] initWithFrame:CGRectMake(0, 150, 60, 25)];
hand.text = @"hand";
[[self view] addSubview:hand];

}

else

{

%orig();

}
}


%new - (void)handPressed
{
if ([Handspeed.currentTitle isEqualToString:@"1x"])

{

[Handspeed setTitle:@"2x" forState:UIControlStateNormal];
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN4Item15getDestroySpeedEP12ItemInstanceP4Tile")),(void*)twospeed,NULL);
}


else if ([Handspeed.currentTitle isEqualToString:@"2x"])

{

[Handspeed setTitle:@"4x" forState:UIControlStateNormal];

MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN4Item15getDestroySpeedEP12ItemInstanceP4Tile")),(void*)fourspeed,NULL);

}



else if ([Handspeed.currentTitle isEqualToString:@"4x"])

{

[Handspeed setTitle:@"8x" forState:UIControlStateNormal];

MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN4Item15getDestroySpeedEP12ItemInstanceP4Tile")),(void*)eightspeed,NULL);

}


else if ([Handspeed.currentTitle isEqualToString:@"8x"])

{

[Handspeed setTitle:@"1x" forState:UIControlStateNormal];
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN4Item15getDestroySpeedEP12ItemInstanceP4Tile")),(void*)onespeed,NULL);

}


else

{

}
}

%new -(void)modePressed
{
}

%new -(void)myButtonPressed
{

if ([Sneaking.currentTitle isEqualToString:@"1x"])

{

[Sneaking setTitle:@"2x" forState:UIControlStateNormal];
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player23getWalkingSpeedModifierEv")),(void*)twospeed,NULL);
}


else if ([Sneaking.currentTitle isEqualToString:@"2x"])

{

[Sneaking setTitle:@"3x" forState:UIControlStateNormal];

MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player23getWalkingSpeedModifierEv")),(void*)threespeed,NULL);

}


else if ([Sneaking.currentTitle isEqualToString:@"3x"])

{

[Sneaking setTitle:@"1x" forState:UIControlStateNormal];
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN6Player23getWalkingSpeedModifierEv")),(void*)onespeed,NULL);

}


else

{

}


}


%end