
#pragma once

#include "SpriteDragger.h"

class Layer : public CCLayer
{
	private:
		/// Our sprite
		CCSprite* sprite;
		
		/// The background color layer
		CCLayerColor* colorLayer;
		
		/// The offset of a touch
		CCPoint touchOffset;

	public:
		Layer();
		~Layer();
		
		/// Returns the Cocos2d position of the touch
		CCPoint touchToPoint(CCTouch* touch);
		
		/// Returns true if the touch is within the boundary of our sprite
		bool isTouchingSprite(CCTouch* touch);

		// we are multi-touch enabled, so we must use the ccTouches functions
		// vs the ccTouch functions
		void ccTouchesBegan(CCSet* touches, CCEvent* event);
		void ccTouchesMoved(CCSet* touches, CCEvent* event);
		void ccTouchesEnded(CCSet* touches, CCEvent* event);
};
