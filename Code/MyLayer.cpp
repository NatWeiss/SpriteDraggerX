
#include "SpriteDragger.h"

MyLayer::MyLayer()
{
	Size iSize = Director::getInstance()->getWinSize();

	// create white background
	this->colorLayer = new LayerColor;
	this->colorLayer->initWithColor( Color4B(255, 255, 255, 255) );
	this->colorLayer->setScale(2.0f);
	this->addChild(this->colorLayer, 1);

	// create sprite
	this->sprite = new Sprite;
	this->sprite->initWithFile("Sprite.png");
	this->sprite->setPosition(Point(iSize.width / 2.0f, iSize.height / 2.0f));
	this->sprite->setAnchorPoint(Point(0.5f, 0.55f)); // nudge the anchor point upward because of the shadow
	this->addChild(this->sprite, 2);

	// listen for touch events
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(self::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(self::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(self::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(self::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

MyLayer::~MyLayer()
{
	// release our sprite and layer so that it gets dealloced
	CC_SAFE_RELEASE_NULL(this->sprite);
	CC_SAFE_RELEASE_NULL(this->colorLayer);
}

Point MyLayer::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

bool MyLayer::isTouchingSprite(Touch* touch)
{
	// here's one way, but includes the rectangular white space around our sprite
	//return CGRectContainsPoint(this->sprite->boundingBox(), this->touchToPoint(touch));
	
	// this way is more intuitive for the user because it ignores the white space.
	// it works by calculating the distance between the sprite's center and the touch point,
	// and seeing if that distance is less than the sprite's radius
	return (this->sprite->getPosition().getDistance(this->touchToPoint(touch)) < 100.0f);
}

void MyLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	// reset touch offset
	this->touchOffset = Point::ZERO;
	
	for( auto touch : touches )
	{
		// if this touch is within our sprite's boundary
		if( touch && this->isTouchingSprite(touch) )
		{
			// calculate offset from sprite to touch point
			this->touchOffset = this->sprite->getPosition() - this->touchToPoint(touch);
		}
	}
}

void MyLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
	for( auto touch : touches )
	{
		// set the new sprite position
		if( touch && touchOffset.x && touchOffset.y )
			this->sprite->setPosition(this->touchToPoint(touch) + this->touchOffset);
	}
}

void MyLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
	for( auto touch : touches )
	{
		if( touch && touchOffset.x && touchOffset.y  )
		{
			// set the new sprite position
			this->sprite->setPosition(this->touchToPoint(touch) + this->touchOffset);

			// stop any existing actions and reset the scale
			this->sprite->stopAllActions();
			this->sprite->setScale(1.0f);

			// animate letting go of the sprite
			this->sprite->runAction(Sequence::create(
				ScaleBy::create(0.125f, 1.111f),
				ScaleBy::create(0.125f, 0.9f),
				nullptr
				));
		}
	}
}
