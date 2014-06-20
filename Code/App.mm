
#import "App.h"
#import "CCEAGLView.h"

#include "cocos2d.h"
using namespace cocos2d;

@implementation App

	#pragma mark -
	#pragma mark App start

	-(BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
	{
		// setup Cocos2d-X graphics
		[self setupGraphics];

		// run the CCApplication (which runs our static sharedApplication's applicationDidFinishLaunching)
		Application::getInstance()->run();
		
		return YES;
	}

	#pragma mark -
	#pragma mark Setup
	
	-(void) setupGraphics
	{
		// add the view controller's view to the window and display.
		window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
		CCEAGLView* eaglView = [CCEAGLView viewWithFrame:[window bounds]
			pixelFormat: kEAGLColorFormatRGBA8
			depthFormat: GL_DEPTH24_STENCIL8_OES // was GL_DEPTH_COMPONENT16
			preserveBackbuffer: NO
			sharegroup: nil
			multiSampling: NO
			numberOfSamples:0];

		// enable multi-touch on ios (android is automatic)
		[eaglView setMultipleTouchEnabled:YES];

		// use RootViewController manage EAGLView
		viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
		viewController.wantsFullScreenLayout = YES;
		viewController.view = eaglView;

		// set RootViewController to window
		if( [[UIDevice currentDevice].systemVersion floatValue] < 6.0 )
			[window addSubview: viewController.view];
		else
			[window setRootViewController: viewController];
		[window makeKeyAndVisible];

		// hide the status bar
		[[UIApplication sharedApplication] setStatusBarHidden: YES];

		// setting the GLView should be done after creating the RootViewController
		GLView *glview = GLView::createWithEAGLView(eaglView);
		Director::getInstance()->setOpenGLView(glview);

		// set the frame rate
		Director::getInstance()->setAnimationInterval(1.0 / 60.0f);
	}

	-(void) dealloc
	{
		// release our window
		[window release];
		[viewController release];
		
		// remember to [super dealloc]
		[super dealloc];
	}

	#pragma mark -
	#pragma mark Messaging

	-(void) applicationWillResignActive:(UIApplication*)application
	{
		Director::getInstance()->pause();
	}

	-(void) applicationDidBecomeActive:(UIApplication*)application
	{
		Director::getInstance()->resume();
	}

	-(void) applicationDidEnterBackground:(UIApplication*)application
	{
		Application::getInstance()->applicationDidEnterBackground();
	}

	-(void) applicationWillEnterForeground:(UIApplication*)application
	{
		Application::getInstance()->applicationWillEnterForeground();
	}

	-(void) applicationWillTerminate:(UIApplication*)application
	{
	}

	-(void) applicationDidReceiveMemoryWarning:(UIApplication*)application
	{
		Director::getInstance()->purgeCachedData();
	}

@end


@implementation RootViewController

	// iOS 5 and older uses this method
	-(BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
	{
		return UIInterfaceOrientationIsPortrait( interfaceOrientation );
	}

	// iOS 6 and newer uses supportedInterfaceOrientations & shouldAutorotate
	-(NSUInteger) supportedInterfaceOrientations
	{
		#ifdef __IPHONE_6_0
			return UIInterfaceOrientationMaskPortrait;
		#endif
	}

	-(BOOL) shouldAutorotate
	{
		return YES;
	}

	-(UIInterfaceOrientation) preferredInterfaceOrientationForPresentation
	{
		return self.interfaceOrientation;
	}

	-(BOOL) prefersStatusBarHidden
	{
		return YES;
	}

@end
