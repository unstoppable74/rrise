#include "default_streaming_mgr.h"  
#include <AkFilePackageLowLevelIODeferred.h>  
  
static CAkFilePackageLowLevelIODeferred g_lowLevelIO;  
  
AKRESULT InitDefaultStreamMgr(const AkDeviceSettings& deviceSettings, const AkOSChar* basePath)  
{  
    AKRESULT r = g_lowLevelIO.Init(deviceSettings);  
    if (r == AK_Success) {  
        g_lowLevelIO.SetBasePath(basePath);  
    }  
    return r;  // 注意：原代码有 bug，Init 被调用了两次，这里也一并修正  
}  
  
void TermDefaultStreamMgr()  
{  
    g_lowLevelIO.Term();  
    if (AK::IAkStreamMgr::Get())  
    {  
        AK::IAkStreamMgr::Get()->Destroy();  
    }  
}