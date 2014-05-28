
#pragma once

// include cocos2d and start using it's namespace so, for example, we can reference
// a CCScene instead of having to always write cocos2d::CCScene
#include "cocos2d.h"
using namespace cocos2d;
using cocos2d::Point;

// now include our MyLayer class
#include "MyLayer.h"

///
/// The main SpriteDragger application class
///
class SpriteDragger : private Application
{
	public:
		virtual bool applicationDidFinishLaunching();
		virtual void applicationDidEnterBackground() {}
		virtual void applicationWillEnterForeground() {}
};
