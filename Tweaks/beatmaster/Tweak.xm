#define PLIST_PATH @"/var/mobile/Library/Preferences/HenryQuan.BeatMaster.plist"
#import <substrate.h>
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

inline bool GetBool(NSString *key) 
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

%hook MusicInfoOC

-(int)unlockLevel
{
if (GetBool(@"song"))
{
return 1;
}
else
{
return %orig();
}
}

%end