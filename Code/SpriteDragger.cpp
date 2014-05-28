
#include "SpriteDragger.h"

bool SpriteDragger::applicationDidFinishLaunching()
{
	// create a generic scene
	auto scene = Scene::create();
	
	// add the layer
	auto layer = new MyLayer;
	scene->addChild(layer, 1);
	layer->release(); // addChild() retained so we release
	
	// run the first scene
	Director::getInstance()->runWithScene(scene);
	
	return true;
}
