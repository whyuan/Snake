#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AppMacros.h"

class Snake;
class World;
class Food;

class HelloWorldScene : public cocos2d::CCScene
{
public:
	HelloWorldScene();
	~HelloWorldScene();
	virtual bool init();
	CREATE_FUNC(HelloWorldScene);
	cocos2d::CCLayer *_gamelayer;
	cocos2d::CCLayer *_controllerlayer;
};

class HelloWorld : public cocos2d::CCLayerColor
{
public:
//	HelloWorld():_snake(NULL),_food(NULL),_world(NULL){}
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback

    void updateGame(float);
    void gameLogic(float);
    // implement the "static node()" method manually
    static Snake *_snake;
    static Food *_food;
    static World *_world;
    CREATE_FUNC(HelloWorld);

protected:

};

#endif // __HELLOWORLD_SCENE_H__
