SpriteDraggerX
==============

A minimal cocos2d-x iPhone / iPad project illustrating how to drag a sprite around the screen.


Setup
-----

SpriteDraggerX uses [RapidGame](https://github.com/NatWeiss/RapidGame)'s prebuilt Cocos2D-X libraries. Make sure you have [Node](http://nodejs.org/download/) and [Git](http://git-scm.com/downloads), then:

	sudo npm install rapidgame -g
	rapidgame prebuild
	cd SpriteDraggerX
	rm lib
	rapidgame init .

This will symlink a `lib` folder to RapidGame's prebuilt headers and libraries. You'll then be able to compile and run SpriteDraggerX.


Topics
------

If you'd like to learn more about creating a complete game, then check out the [free Cocos2D-X book](http://wizardfu.com/book/cocos2d-x/) at WizardFu.com.

Topics covered in the SpriteDraggerX source code:

 * Writing a minimal app delegate class to handle creating the window and GL view
 * Receiving touch events from Cocos2D-X and translating them into dragging a sprite around the screen
 * Animating the sprite via `runAction`
 * `Director`, `Scene`, `Sprite`, `ColorLayer`, `Sequence`, `ScaleBy`

Notes:

 * Includes an Xcode project
 * Objective C is required to initialize iOS (App.h & App.mm)
 * All other code is pure C++


License
-------

SpriteDraggerX is licensed under the MIT license.