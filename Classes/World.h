/*
 * World.h
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#ifndef WORLD_H_
#define WORLD_H_
#include "AppMacros.h"
class World: public cocos2d::CCNode
{
public:
	World();
	~World();
	char* getMap();
	void putObject(float, float, objectType);
	objectType getObject(float, float);
	virtual bool init();
	CREATE_FUNC(World);
protected:
	objectType map[mapWidth][mapHeight];
};

#endif /* WORLD_H_ */
