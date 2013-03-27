/*
 * Snake.h
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include "AppMacros.h"


class Snake: public cocos2d::CCNode
{
public:
	Snake();
	~Snake();
	void move(direction d);
	direction dir;
	bool turn(direction d);
	bool isLive();
	int getLength();
	virtual bool init();
	CREATE_FUNC(Snake);
protected:
	void eat(int, int);
	cocos2d::CCArray * _body;
	bool canMove(float, float);
};

#endif /* SNAKE_H_ */
