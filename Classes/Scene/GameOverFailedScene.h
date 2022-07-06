#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;
using namespace std;


class GameOverFailedScene:public Scene
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameOverFailedScene);

	void onClick(Ref *pSender, Widget::TouchEventType type);
	void onClick_exit(Ref *pSender, Widget::TouchEventType type);
};

