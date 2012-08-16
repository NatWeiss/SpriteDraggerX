
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

// we need a root view controller to specify our interface orientations programmatically
@interface RootViewController : UIViewController
@end

// we need a UI application delegate to respond to application messages from iOS
@interface App : NSObject <UIApplicationDelegate>
	{
		UIWindow* window;
		RootViewController* viewController;
	}
	
	// sets up cocos2d
	-(void) setupGraphics;	
@end
