
#pragma once

#include "SpriteDragger.h"

class MyLayer : public Layer
{
	private:
		typedef MyLayer self;
		typedef Layer super;
		
		/// Our sprite
		Sprite* sprite;
		
		/// The background color layer
		LayerColor* colorLayer;
		
		/// The offset of a touch
		Point touchOffset;

	public:
		MyLayer();
		~MyLayer();
		
		/// Returns the Cocos2d position of the touch
		Point touchToPoint(Touch* touch);
		
		/// Returns true if the touch is within the boundary of our sprite
		bool isTouchingSprite(Touch* touch);

		// we are multi-touch enabled, so we must use the ccTouches functions
		// vs the ccTouch functions
		void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
		void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
		void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
};
