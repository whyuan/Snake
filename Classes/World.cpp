/*
 * World.cpp
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#include "World.h"
#include "math.h"
using namespace cocos2d;
World::World(){

}

World::~World(){

}

bool World::init() {
	bool bRet = false;
	do {
//		if ( !CCNode::init() ) {
//			return false;
//		}
		int i, j;
		for (i = 0; i < mapWidth; i++) {
			for (j = 0; j < mapHeight; j++) {
				map[i][j] = kfree;
			}
		}
		HelloWorld::_world = this;
		bRet = true;
	} while (0);
	return bRet;
}

void World::putObject(float x, float y, objectType object) {
	int mapX = (int)floor(x / gridWidth);
	int mapY = (int)floor(y / gridHeight);
	map[mapX][mapY] = object;
}

objectType World::getObject(float x, float y) {
	int mapX = (int)floor(x / gridWidth);
	int mapY = (int)floor(y / gridHeight);
	return map[mapX][mapY];
}
char* getMap(){}
