#define PLIST_PATH @"/var/mobile/Library/Preferences/PadHack.plist"
#import <substrate.h>
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

inline bool GetBool(NSString *key) 
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

inline int GetInt(NSString *key) 
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] intValue];
}

void noDamage()
{
 //nothing happens so no damage.
}

bool canOpenSkill()
{
return true;
 //Can open at anytime.
}

int attackPow()
{
return GetInt(@"value");
}

%ctor
{
if (GetBool(@"damage"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN7sPLAYER6damageEif")),(void*)noDamage,NULL);
}
if (GetBool(@"skill"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN9cGAMEMAIN13_canOpenSkillEP5sCARD")),(void*)canOpenSkill,NULL);
}
if (GetBool(@"attack"))
{
MSHookFunction(((void*)MSFindSymbol(NULL, "__ZN9cGAMEMAIN14_caclAttackPowEiiP8sMONSTERbPii")),(void*)attackPow,NULL);
}
}
