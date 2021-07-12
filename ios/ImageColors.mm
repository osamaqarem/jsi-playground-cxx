#import "example.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import "ImageColors.h"

@implementation ImageColors

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

+ (BOOL) requiresMainQueueSetup {
  return YES;
}

- (void) setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    _setBridgeOnMainQueue = RCTIsMainQueue();
    
    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
    if (!cxxBridge.runtime) {
      return;
    }
    
    installImageColors(*(facebook::jsi::Runtime *)cxxBridge.runtime);
}

- (void) invalidate {
    cleanUpImageColors();
}

@end
