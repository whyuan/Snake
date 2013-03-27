/*
 * Controller.h
 *
 *  Created on: 18 Mar, 2013
 *      Author: a_why
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "cocos2d.h"
#include "AppMacros.h"

class Snake;
class World;
class Food;

class Controller : public cocos2d::CCLayer
{
public:
    void menuCloseCallback(CCObject* pSender);
    void menuCallbackMove(CCObject* pSender);
	virtual bool init();
	CREATE_FUNC(Controller);
};

#endif /* CONTROLLER_H_ */
