%hook ipLimitView

-(id) initWithFrame:(CGRect) errString:(id)arg
{
return 0;
}
%end

%hook kugouAppDelegate

-(void) setChinaUser
{

}

%end

%hook KGConfigure

-(int) chinaUserFlag
{
return 1;
}

-(void) MakeChinaUserFlag
{

}

-(void) setChinaUserFlag:(int) arg
{
%orig(1);
}

%end

%hook ASIHTTPRequest

-(BOOL) CheckChinaIp
{
return TRUE;
}

%end

%hook KGCommonTools

+(BOOL) checkChinaUnicom
{
return TRUE;
}

+(int) isChinaUser
{
return 1;
}

+(int) isChinaUserHttpRequest:(id)arg
{
return 1;
}

+(BOOL) isChinaFromMobile
{
return TRUE;
}

%end

%hook ConfigProtocol
+(int) getChinaIp
{
return 1;
}

+(void) saveChinaIp:(int) arg
{
%orig(1);
}

%end