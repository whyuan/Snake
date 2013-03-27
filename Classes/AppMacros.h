/*
 * AppMacros.h
 *
 *  Created on: 17 Mar, 2013
 *      Author: a_why
 */

#ifndef APPMACROS_H_
#define APPMACROS_H_
typedef enum {
	kUp = 0,
	kDown = 1,
	kLeft = 2,
	kRight = 3,
	kNormal,
} direction;
typedef enum {
	kfree = 0,
	kfood = 1,
	ksnake = 2
} objectType;
#define mapWidth (48)
#define mapHeight (32)
#define gridWidth (10)
#define gridHeight (10)
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include "Controller.h"
#include "Food.h"
#include "World.h"
#include "Snake.h"

#endif /* APPMACROS_H_ */
