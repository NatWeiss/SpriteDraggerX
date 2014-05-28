SpriteDraggerX
==============

A clean, minimal Cocos2D-X iOS example project showing you how to drag a sprite around the screen.


Setup
-----

SpriteDraggerX uses [RapidGame](http://wizardfu.com/rapidgame)'s prebuilt Cocos2D-X libraries. Make sure you have [Node](http://nodejs.org/download/) and [Git](http://git-scm.com/downloads), then:

	sudo npm install rapidgame -g
	rapidgame prebuild
	cd SpriteDraggerX
	rm lib
	rapidgame init .

This will symlink a `lib` folder to RapidGame's prebuilt headers and libraries. You'll then be able to compile and run SpriteDraggerX.


Cocos2D-X
---------

With Cocos2d-X you can write your game in C++ and publish it to multiple platforms, including iOS, Android, Windows and Mac. This project shows you how to setup a simple iOS project. If you'd like to learn more about creating a complete game with project files for all the above mentioned platforms, then check out the Paralaxer project:

http://paralaxer.com

Topics covered in the SpriteDraggerX source code:

 * Creating a minimal App delegate class to handle creating the window, the GL view and initializing Cocos2D-X
 * Receiving ccTouches events from Cocos2D-X and translating them into dragging a CCSprite around the screen
 * Animating the sprite via runAction
 * CCDirector, CCScene, CCSprite, CCColorLayer, CCSequence, CCScaleBy

Notes:

 * Includes an example Xcode project.
 * Uses Cocos2d-X version 2.0.1
 * Objective C is required to initialize iOS (App.h & App.mm)
 * All other code is pure C++


License
-------

SpriteDraggerX is licensed under the MIT license.