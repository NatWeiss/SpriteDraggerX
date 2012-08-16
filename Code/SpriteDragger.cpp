
#include "SpriteDragger.h"

bool SpriteDragger::applicationDidFinishLaunching()
{
	// create a generic scene
	CCScene* scene = CCScene::create();
	
	// add the layer
	Layer* layer = new Layer;
	scene->addChild(layer, 1);
	layer->release(); // addChild() retained so we release
	
	// run the first scene
	CCDirector::sharedDirector()->runWithScene(scene);
	
	return true;
}
