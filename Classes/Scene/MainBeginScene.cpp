#include "MainBeginScene.h"


cocos2d::Scene * MainBeginScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainBeginScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainBeginScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/BeginScene.mp3");
	auto lab2_UI = GUIReader::getInstance()->widgetFromJsonFile("MainBeginScene_1/MainBeginScene_1.json");
	this->addChild(lab2_UI);
	auto imageView = (ImageView *)lab2_UI->getChildByTag(22);
	auto btn = (Button *)imageView->getChildByTag(23);
	btn->addTouchEventListener(CC_CALLBACK_2(MainBeginScene::onClick, this));
	auto btn_exit = (Button *)imageView->getChildByTag(25);
	btn_exit->addTouchEventListener(CC_CALLBACK_2(MainBeginScene::onClick_exit, this));
	return true;
}

void MainBeginScene::onClick(Ref * pSender, Widget::TouchEventType type)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void MainBeginScene::onClick_exit(Ref * pSender, Widget::TouchEventType type)
{
	exit(-1);
}
