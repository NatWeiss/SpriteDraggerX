
#import "App.h"
#import "SpriteDragger.h"
#import "EAGLView.h"

@implementation App

	#pragma mark -
	#pragma mark App start

	// the main application instance
	static SpriteDragger s_sharedApplication;

	-(BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
	{
		// setup Cocos2d-X graphics
		[self setupGraphics];

		// run the CCApplication (which runs our static sharedApplication's applicationDidFinishLaunching)
		cocos2d::CCApplication::sharedApplication().run();
		
		return YES;
	}

	#pragma mark -
	#pragma mark Setup
	
	-(void) setupGraphics
	{
		// add the view controller's view to the window and display.
		window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
		EAGLView* __glView = [EAGLView viewWithFrame:[window bounds]
			pixelFormat: kEAGLColorFormatRGBA8
			depthFormat: GL_DEPTH_COMPONENT16
			preserveBackbuffer: NO
			sharegroup: nil
			multiSampling: NO
			numberOfSamples:0];

		// enable multi-touch on ios (android is automatic)
		[__glView setMultipleTouchEnabled:YES];

		// use RootViewController manage EAGLView
		viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
		viewController.wantsFullScreenLayout = YES;
		viewController.view = __glView;

		// set RootViewController to window
		[window addSubview:__glView];
		[window makeKeyAndVisible];

		// hide the status bar
		[[UIApplication sharedApplication] setStatusBarHidden: YES];

		// setup our shared open gl view
		CCDirector* director = CCDirector::sharedDirector();
		director->setOpenGLView(&CCEGLView::sharedOpenGLView());
		
		// set the frame rate
		director->setAnimationInterval(1.0 / 60.0f);
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
		cocos2d::CCDirector::sharedDirector()->pause();
	}

	-(void) applicationDidBecomeActive:(UIApplication*)application
	{
		cocos2d::CCDirector::sharedDirector()->resume();
	}

	-(void) applicationDidEnterBackground:(UIApplication*)application
	{
		cocos2d::CCApplication::sharedApplication().applicationDidEnterBackground();
	}

	-(void) applicationWillEnterForeground:(UIApplication*)application
	{
		cocos2d::CCApplication::sharedApplication().applicationWillEnterForeground();
	}

	-(void) applicationWillTerminate:(UIApplication*)application
	{
	}

	-(void) applicationDidReceiveMemoryWarning:(UIApplication*)application
	{
		 cocos2d::CCDirector::sharedDirector()->purgeCachedData();
	}

@end


@implementation RootViewController

	-(BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
	{
		return UIInterfaceOrientationIsPortrait( interfaceOrientation );
	}

@end
