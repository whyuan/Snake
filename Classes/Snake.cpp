/*
 * Snake.cpp
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#include "Snake.h"
#include "AppMacros.h"
#include "math.h"
using namespace cocos2d;
class HelloWorld;
Snake::Snake(){
}

Snake::~Snake(){

}

bool Snake::init(){
	bool bRet = false;
	do {
//		if ( !CCNode::init() ) {
//			return false;
//		}
		_body = new CCArray;
		CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
		CCSprite *pSprite = CCSprite::create("snake.PNG", CCRectMake(0, 0, 10, 10));
		pSprite->setPosition( ccp(pSprite->getContentSize().width * 2.5, winSize.height - pSprite->getContentSize().height / 2));
		this->addChild(pSprite, 3);
		_body->addObject(pSprite);
		//HelloWorld::_world->putObject(pSprite->getPosition().x, pSprite->getPosition().y, ksnake);

		pSprite = CCSprite::create("snake.PNG");
		pSprite->setPosition( ccp(pSprite->getContentSize().width * 1.5, winSize.height - pSprite->getContentSize().height / 2));
		this->addChild(pSprite, 3);
		_body->addObject(pSprite);
		//HelloWorld::_world->putObject(pSprite->getPosition().x, pSprite->getPosition().y, ksnake);

		pSprite = CCSprite::create("snake.PNG");
		pSprite->setPosition( ccp(pSprite->getContentSize().width / 2, winSize.height - pSprite->getContentSize().height / 2));
		this->addChild(pSprite, 3);
		_body->addObject(pSprite);
		//HelloWorld::_world->putObject(pSprite->getPosition().x, pSprite->getPosition().y, ksnake);

		dir = kRight;
		HelloWorld::_snake = this;
		bRet = true;
	} while (0);
	return bRet;
}

void Snake::move(direction d){

	CCSprite* head = (CCSprite*)_body->objectAtIndex(0);
//	CCSprite *body = dynamic_cast<CCSprite*>(it);

	CCObject *it = NULL;
//	CCARRAY_FOREACH(_body, it) {
//
//	}
	float hx = head->getPosition().x;
	float hy = head->getPosition().y;
	float nextx;
	float nexty;
	if(d == kUp) {
		nextx = hx;
		nexty = hy + head->getContentSize().height;
	}
	else if(d == kDown) {
		nextx = hx;
		nexty = hy - head->getContentSize().height;
	}
	else if(d == kLeft) {
		nextx = hx - head->getContentSize().width;
		nexty = hy;
	}
	else if(d == kRight) {
		nextx = hx + head->getContentSize().width;
		nexty = hy;
	}

	float prex = 0;
	float prey = 0;

	if (canMove(nextx, nexty)) {
//		for (it = _body->begin(); it != _body->end(); it++){
	    CCARRAY_FOREACH(_body, it) {
			CCSprite *body = dynamic_cast<CCSprite*>(it);
			prex = body->getPosition().x;
			prey = body->getPosition().y;
			body->setPosition( ccp(nextx, nexty) );
			HelloWorld::_world->putObject( nextx, nexty, ksnake);
			HelloWorld::_world->putObject( prex, prey, kfree);
			nextx = prex;
			nexty = prey;
		}
	    if (abs(HelloWorld::_food->getFoodPosition().x - hx) < 0.1 && abs(HelloWorld::_food->getFoodPosition().y - hy) < 0.1){
			CCSprite *pSprite = CCSprite::create("snake.PNG");
			pSprite->setPosition( ccp(nextx, nexty));
			HelloWorld::_world->putObject( nextx, nexty, ksnake);
			this->addChild(pSprite, 3);
			_body->addObject(pSprite);
			HelloWorld::_food->putFood();
	    }
	}
	else {
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Lose :[");
		CCDirector::sharedDirector()->replaceScene(gameOverScene);
	}
}

bool Snake::canMove(float x, float y){
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	CCObject * it = NULL;
	if (x >= 0 && x <= winSize.width && y >= 0 && y <= winSize.height){
		CCARRAY_FOREACH(_body, it) {
			CCSprite *body = dynamic_cast<CCSprite*>(it);
			float bodyx = (float)body->getPosition().x;
			float bodyy = (float)body->getPosition().y;
			if ((abs(x - bodyx) < 0.1 && abs(y - bodyy) < 0.1)) {
				return false;
			}
		}
		return true;
	}
	else return false;
}

bool Snake::turn(direction d) {
	if (d == kUp && dir == kDown) return false;
	if (d == kDown && dir == kUp) return false;
	if (d == kRight && dir == kLeft) return false;
	if (d == kLeft && dir == kRight) return false;
	dir = d;
	return true;
}

int Snake::getLength() {
	return _body->count();
}
bool Snake::isLive(){}

void eat(int x, int y){

}

