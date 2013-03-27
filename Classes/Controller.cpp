/*
 * Controller.cpp
 *
 *  Created on: 18 Mar, 2013
 *      Author: a_why
 */
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Snake.h"
#include "World.h"
#include "Food.h"
#include "AppMacros.h"


using namespace cocos2d;
using namespace CocosDenshion;

bool Controller::init() {
	if ( CCLayer::init() )
	{




//	    CCMenuItemImage *pUpItem = CCMenuItemImage::create("up.PNG", "upSelected.PNG", this, menu_selector(HelloWorld::menuCallbackMove));
//	    pUpItem->setPosition( ccp(120, 160));
//	    CCMenuItemImage *pDownItem = CCMenuItemImage::create("down.PNG", "downSelected.PNG", this, menu_selector(HelloWorld::menuCallbackMove));
//	    pDownItem->setPosition( ccp(120, 0));
//	    CCMenuItemImage *pLeftItem = CCMenuItemImage::create("left.PNG", "leftSelected.PNG", this, menu_selector(HelloWorld::menuCallbackMove));
//	    pLeftItem->setPosition( ccp(0, 0));
//	    CCMenuItemImage *pRightItem = CCMenuItemImage::create("right.PNG", "rightSelected.PNG", this, menu_selector(HelloWorld::menuCallbackMove));
//	    pRightItem->setPosition( ccp(360, 0));

	    CCMenuItemImage *pUpItem = CCMenuItemImage::create("transparent240x160.png", "transparent240x160_selected.png", this, menu_selector(Controller::menuCallbackMove));
	    pUpItem->setPosition( ccp(240, 240));
	    CCMenuItemImage *pDownItem = CCMenuItemImage::create("transparent240x160.png", "transparent240x160_selected.png", this, menu_selector(Controller::menuCallbackMove));
	    pDownItem->setPosition( ccp(240, 80));
	    CCMenuItemImage *pLeftItem = CCMenuItemImage::create("transparent120x320.png", "transparent120x320_selected.png", this, menu_selector(Controller::menuCallbackMove));
	    pLeftItem->setPosition( ccp(60, 160));
	    CCMenuItemImage *pRightItem = CCMenuItemImage::create("transparent120x320.png", "transparent120x320_selected.png", this, menu_selector(Controller::menuCallbackMove));
	    pRightItem->setPosition( ccp(420, 160));


	    CCMenu* pMenu = CCMenu::create(pUpItem, pDownItem, pLeftItem, pRightItem, NULL);
	    pMenu->setPosition( CCPointZero );
	    this->addChild(pMenu, 1);
	    pUpItem->setTag(kUp);
	    pDownItem->setTag(kDown);
	    pLeftItem->setTag(kLeft);
	    pRightItem->setTag(kRight);

	    /////////////////////////////
	    // 2. add a menu item with "X" image, which is clicked to quit the program
	    //    you may modify it.

	    // add a "close" icon to exit the progress. it's an autorelease object
	    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
	                                        "CloseNormal.png",
	                                        "CloseSelected.png",
	                                        this,
	                                        menu_selector(Controller::menuCloseCallback) );
	    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getVisibleSize().width - 20, 20) );
	    // create menu, it's an autorelease object
	    pMenu = CCMenu::create(pCloseItem, NULL);
	    pMenu->setPosition( CCPointZero );
	    this->addChild(pMenu, 2);

		return true;
	}
	else
	{
		return false;
	}
}

void Controller::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void Controller::menuCallbackMove(CCObject* pSender)
{
	CCNode *node = (CCNode*) pSender;
	int targetDirection = node->getTag();
	HelloWorld::_snake->turn((direction) targetDirection);


}

