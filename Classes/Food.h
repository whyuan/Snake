/*
 * Food.h
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#ifndef FOOD_H_
#define FOOD_H_
#include "AppMacros.h"
class Food: public cocos2d::CCNode
{
public:
	Food();
	~Food();
	cocos2d::CCPoint getFoodPosition();
	void putFood();
	virtual bool init();
	CREATE_FUNC(Food);
protected:
	cocos2d::CCSprite* _theFood;
};

#endif /* FOOD_H_ */
