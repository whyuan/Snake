/*
 * Food.cpp
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */
#include "Food.h"
#include "math.h"
using namespace cocos2d;
Food::Food(){

}

Food::~Food(){

}

bool Food::init(){
	bool bRet = false;
	do {
//		if ( !CCNode::init() ) {
//			return false;
//		}
		float x, y;
		CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
		CCSprite *pSprite = CCSprite::create("food.PNG", CCRectMake(0, 0, 10, 10));
		x = (gridWidth * (rand() % 48) - (float)gridWidth / 2);
		y = gridHeight * (rand() % 32) - (float)gridHeight / 2;
		pSprite->setPosition( ccp(x, y));
		//HelloWorld::_world->putObject( x, y, kfood);
		this->addChild(pSprite, 1);
		_theFood = pSprite;

		HelloWorld::_food = this;
		bRet = true;
	} while (0);
	return bRet;
}

CCPoint Food::getFoodPosition() {
	return _theFood->getPosition();
}
void Food::putFood(){
	float x, y;
	do {
		x = (gridWidth * (rand() % 48) + (float)gridWidth / 2);
		y = gridHeight * (rand() % 32) + (float)gridHeight / 2;
		if (HelloWorld::_world->getObject(x, y) == kfree) {
			_theFood->setPosition( ccp(x, y) );
			break;
		}
	} while(1);
}
