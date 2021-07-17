#import "example.h"
#import <React/RCTBridge+Private.h>
#import <React/RCTUtils.h>
#import "ImageColors.h"

@implementation ImageColors

RCT_EXPORT_MODULE()

+ (BOOL) requiresMainQueueSetup {
  return YES;
}

- (void) setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    
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
