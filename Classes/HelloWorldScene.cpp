#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Snake.h"
#include "World.h"
#include "Food.h"
#include "AppMacros.h"


using namespace cocos2d;
using namespace CocosDenshion;
Snake* HelloWorld::_snake = NULL;
Food* HelloWorld::_food = NULL;
World* HelloWorld::_world = NULL;

bool HelloWorldScene::init() {
	if( CCScene::init() )
	{
		this->_gamelayer = HelloWorld::create();
		this->_gamelayer->retain();
		this->addChild(_gamelayer);
		this->_controllerlayer = Controller::create();
		this->_controllerlayer->retain();
		this->addChild(_controllerlayer);
		return true;
	}
	else
	{
		return false;
	}
}
HelloWorldScene::HelloWorldScene(){}
HelloWorldScene::~HelloWorldScene() {
	if (_gamelayer)
	{
		_gamelayer->release();
		_gamelayer = NULL;
	}
	if (_controllerlayer)
	{
		_controllerlayer->release();
		_controllerlayer = NULL;
	}
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	bool bRet = false;
	do {
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor( ccc4(255, 255, 255, 255)) )
    {
        return false;
    }


    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//	// create and initialize a label
//	CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);
//
//	// ask director the window size
//	CCSize size = CCDirector::sharedDirector()->getWinSize();
//
//    // position the label on the center of the screen
//    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
//
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    pSprite->setPosition( ccp(size.width/2, size.height/2) );
//
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);

    CCNode *pSnake = (CCNode*)Snake::create();
    CCNode *pFood = (CCNode*)Food::create();
    CCNode *pWorld = (CCNode*)World::create();
	this->schedule( schedule_selector(HelloWorld::gameLogic), 0.1 );
	this->schedule( schedule_selector(HelloWorld::updateGame) );
//    CCSprite* pSprite = CCSprite::create("")
    this->addChild(pSnake);
	this->addChild(pFood);
	this->addChild(pWorld);
	bRet = true;
	} while(0);
    
    return bRet;
}

void HelloWorld::gameLogic(float dt)
{
	_snake->move(_snake->dir);
	return;
}

void HelloWorld::updateGame(float dt)
{
	if ( _snake->getLength() > 50 ) {
		GameOverScene *gameOverScene = GameOverScene::create();
		gameOverScene->getLayer()->getLabel()->setString("You Win!");
		CCDirector::sharedDirector()->replaceScene(gameOverScene);
	}
	return;
}



