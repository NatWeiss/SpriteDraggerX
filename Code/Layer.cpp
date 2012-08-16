
#include "SpriteDragger.h"

Layer::Layer()
{
	// enable touches so we can drag
	// note that if you call CCLayer's init() it will unset touch enabled!
	this->setTouchEnabled(true);

	// create white background
	this->colorLayer = new CCLayerColor;
	this->colorLayer->initWithColor( ccc4(255, 255, 255, 255) );
	this->addChild(this->colorLayer, 1);

	// create sprite
	CCSize iSize = CCDirector::sharedDirector()->getWinSize();
	this->sprite = new CCSprite;
	this->sprite->initWithFile("Sprite.png");
	this->sprite->setPosition(ccp(iSize.width / 2.0f, iSize.height / 2.0f));
	this->sprite->setAnchorPoint(ccp(0.5f, 0.55f)); // nudge the anchor point upward because of the shadow
	this->addChild(this->sprite, 2);
}

Layer::~Layer()
{
	// unset this so we unregister with the touch dispatcher
	this->setTouchEnabled(false);
	
	// release our sprite and layer so that it gets dealloced
	CC_SAFE_RELEASE_NULL(this->sprite);
	CC_SAFE_RELEASE_NULL(this->colorLayer);
}

CCPoint Layer::touchToPoint(CCTouch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::sharedDirector()->convertToGL(touch->locationInView());
}

bool Layer::isTouchingSprite(CCTouch* touch)
{
	// here's one way, but includes the rectangular white space around our sprite
	//return CGRectContainsPoint(this->sprite->boundingBox(), this->touchToPoint(touch));
	
	// this way is more intuitive for the user because it ignores the white space.
	// it works by calculating the distance between the sprite's center and the touch point,
	// and seeing if that distance is less than the sprite's radius
	return (ccpDistance(this->sprite->getPosition(), this->touchToPoint(touch)) < 100.0f);
}

void Layer::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);

		// if this touch is within our sprite's boundary
		if( touch && this->isTouchingSprite(touch) )
		{
			// calculate offset from sprite to touch point
			this->touchOffset = ccpSub(this->sprite->getPosition(), this->touchToPoint(touch));
		}
	}
}

void Layer::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);

		// set the new sprite position
		if( touch )
			this->sprite->setPosition(ccpAdd(this->touchToPoint(touch), this->touchOffset));
	}
}

void Layer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	for( auto it = touches->begin(); it != touches->end(); it++) 
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(*it);
		if( touch )
		{
			// set the new sprite position
			this->sprite->setPosition(ccpAdd(this->touchToPoint(touch), this->touchOffset));

			// animate letting go of the sprite
			this->sprite->runAction(CCSequence::create(
				CCScaleBy::create(0.125f, 1.111f),
				CCScaleBy::create(0.125f, 0.9f),
				nullptr
				));
		}
	}
}
