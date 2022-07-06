#include "GameOverSuccessScene.h"

cocos2d::Scene * GameOverSuccessScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverSuccessScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameOverSuccessScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Zen Garden.mp3");
	auto lab2_UI = GUIReader::getInstance()->widgetFromJsonFile("GameOverSceneFail/GameOverScene_1.json");
	this->addChild(lab2_UI);
	auto imageView = (ImageView *)lab2_UI->getChildByTag(22);
	auto btn = (Button *)imageView->getChildByTag(23);
	btn->addTouchEventListener(CC_CALLBACK_2(GameOverSuccessScene::onClick, this));
	/*auto btn_exit = (Button *)imageView->getChildByTag(14);
	btn_exit->addTouchEventListener(CC_CALLBACK_2(GameOverFailedScene::onClick_exit, this));*/
	return true;
}

void GameOverSuccessScene::onClick(Ref * pSender, Widget::TouchEventType type)
{
	exit(-1);
}

void GameOverSuccessScene::onClick_exit(Ref * pSender, Widget::TouchEventType type)
{
}
