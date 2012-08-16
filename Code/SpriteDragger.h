
#pragma once

// include cocos2d and start using it's namespace so, for example, we can reference
// a CCScene instead of having to always write cocos2d::CCScene
#include "cocos2d.h"
using namespace cocos2d;

// now include our Layer class
#include "Layer.h"

///
/// The main SpriteDragger application class
///
class SpriteDragger : private CCApplication
{
	public:
		virtual bool applicationDidFinishLaunching();
		virtual void applicationDidEnterBackground() {}
		virtual void applicationWillEnterForeground() {}
};
