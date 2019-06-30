#define PLIST_PATH @"/var/mobile/Library/Preferences/Retry.plist"
#import "writeData.h"
#import <substrate.h>
#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

inline bool GetBool(NSString *key) 
{
return [[[NSDictionary dictionaryWithContentsOfFile:PLIST_PATH] valueForKey:key] boolValue];
}

%ctor
{
if (GetBool(@"4x"))
{
writeData (0x8CE04,0x010180E0);
}
}
