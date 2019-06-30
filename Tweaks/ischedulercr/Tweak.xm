#import <substrate.h>

BOOL isSerial()
{
return 0;
}

%ctor
{
MSHookFunction(((void*)MSFindSymbol(NULL, "_checkSerial")), (void*)isSerial, NULL);
}