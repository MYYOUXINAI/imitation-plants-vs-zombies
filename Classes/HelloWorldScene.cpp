#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}


static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	this->MyInit();

	////添加植物
	//for (int i = 1; i <= 5; i++)
	//{
	//	//SunFlower* tempPlants = new SunFlower;
	//	//PlantsGroup.push_back(tempPlants);
	//	//tempPlants->_plantsSprite->setPosition(positionOfPlants[i-1][0]);
	//	//ArrOfPlantsVisits[i - 1][0] = true;//该坑位已经被占据
	//	//tempPlants->_plantsSprite->setScale(1.2);
	//	//tempPlants->setPlantsRowCol(i-1, 0);
	//	//this->addChild(tempPlants->_plantsSprite, PlantsZ);
	//	//this->addChild(tempPlants, PlantsZ);
	//	tempAI->CreateAPlants(i - 1, 0, _PlantsTypeSunFlower);
	//}


	//for (int i = 1; i <= 5; i++)
	//{
	//	//PeaShooter* tempPlants = new PeaShooter;
	//	//PlantsGroup.push_back(tempPlants);
	//	//tempPlants->_plantsSprite->setPosition(positionOfPlants[i - 1][1]);
	//	//ArrOfPlantsVisits[i - 1][1] = true;//该坑位已经被占据
	//	//tempPlants->_plantsSprite->setScale(1.2);
	//	//tempPlants->setPlantsRowCol(i-1, 1);
	//	//this->addChild(tempPlants->_plantsSprite, PlantsZ);
	//	//this->addChild(tempPlants, PlantsZ);
	//	tempAI->CreateAPlants(i - 1, 1, _PlantsTypePeaShooter);
	//}



	////添加僵尸
	//for (int i = 1; i <= 5; i++)
	//{
	//	Vec2 delta = Vec2(100, 30);
	//	NormalZombies* tempZombies = new NormalZombies;
	//	/*ZombiesGroup.push_back(tempZombies);
	//	tempZombies->_zombiesSprite->setPosition(positionOfPlants[i - 1][2]+delta);
	//	tempZombies->_zombiesSprite->setScale(1.1);
	//	tempZombies->setRowCol(i-1, 8);
	//	this->addChild(tempZombies, ZombiesZ);
	//	this->addChild(tempZombies->_zombiesSprite, ZombiesZ);
	//	this->addChild(tempZombies->_zombiesHeadSprite, ZombiesZ);*/
	//	tempAI->CreateAZombies(positionOfPlants[i - 1][0] + delta, i - 1);
	//}

	this->scheduleUpdate();
    return true;
}

void HelloWorld::MyInit()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Grasswalk.mp3");
	_delayTime = 0.0;

	GameOverFlag = false;

	MousePlantsSprite = nullptr;
	copyMousePlantsSprite = nullptr;
	SelectedCard = nullptr;

	/*MousePlantsSprite->setTag(MousePlantsSpriteTag);
	this->addChild(MousePlantsSprite, PlantsZ);*/

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//首先是初始化全局变量数据
	_GroupSun = 150;
	_GroupCurrentSun = _GroupSun;

	ZombiesGroup.clear();
	PlantsGroup.clear();
	AmmoGroup.clear();
	CardGroup.clear();


	positionOfPlants.resize(5, vector<Vec2>(9));
	//最左上的坐标为（47，664）；最右上的坐标为（964，662）；最左下的坐标为（43，54）；最右下的坐标为（973，46）
	//用于初始化位置矩阵
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			positionOfPlants[i][j] = Vec2(100 + 103 * j, 100 + 125 * i);
		}
	}


	//这里初始化各个坑位都是没有被种植的
	ArrOfPlantsVisits.resize(5, vector<bool>(9, false));


	//这里初始化关卡背景图
	auto sprite = Sprite::create("Scene/background1.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
	this->addChild(sprite, BackGroundZ);
	sprite->setScale(1.275);


	//这里初始化显示已经的阳光的图片
	auto SunItem = Sprite::create("Plants/SunBack.png");
	SunItem->setTag(SunLabelTag);
	this->addChild(SunItem, SunNumPicZ);
	SunItem->setPosition(Vec2(100, 750));
	string str = to_string(_GroupSun);
	auto MySunNumItem = Label::createWithBMFont("fonts/futura-48.fnt", str.c_str());
	MySunNumItem->setScale(0.5);
	MySunNumItem->setPosition(Vec2(70, 15));
	MySunNumItem->setTag(SunNumItemTag);
	SunItem->addChild(MySunNumItem);


	//添加一个鼠标回应事件，这里用于实现点击阳光，实现关卡阳光数增加的效果
	//实现鼠标点击植物卡片，拖动植物卡片到空白的可种植位置，实现植物种植的效果
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved= CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//这里添加一个植物、僵尸的攻击AI
	tempAI = new PlantsAttack;
	tempAI->setParentScene(this);
	this->addChild(tempAI);


	//这里添加向日葵、豌豆射手的卡片
	auto tempCard = new SunFlowerCard;
	tempCard->setCardPosition(Vec2(250, 740));
	this->addChild(tempCard, CardZ);
	this->addChild(tempCard->_cardSprite, CardZ);
	this->addChild(tempCard->_cardSpriteUnavaliable, CardZ);
	CardGroup.push_back(tempCard);

	auto tempCard2 = new PeaShooterCard;
	tempCard2->setCardPosition(Vec2(400, 740));
	this->addChild(tempCard2, CardZ);
	this->addChild(tempCard2->_cardSprite, CardZ);
	this->addChild(tempCard2->_cardSpriteUnavaliable, CardZ);
	CardGroup.push_back(tempCard2);

	//tempCard->RunSelectedAnimate();

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

bool HelloWorld::onTouchBegan(Touch * touch, Event * unused_event)
{
	auto _TouchPosition = touch->getLocation();
	for (auto &x : AmmoGroup)//这里查看鼠标点击位置是否有阳光
	{
		if (x->_AmmoDie == true)	continue;
		double _width = x->_AmmoPicSprite->getContentSize().width / 2;
		double _height = x->_AmmoPicSprite->getContentSize().height / 2;
		Vec2 _SunPosition = x->_AmmoPicSprite->getPosition();
		auto _offset = _SunPosition - _TouchPosition;
		if ((fabs(_offset.x) <= _width) && (fabs(_offset.y) <= _height))//说明鼠标点击位置是阳光所在位置
		{
			_GroupSun += 50;
			x->RunAmmoDisappearAnimate();
			return true;
		}
	}

	//这里查看鼠标点击的位置是不是植物卡片的位置
	for (auto &x : CardGroup)
	{
		if (x->_cardIsAvaliable == false)	continue;//如果卡片cd没好，直接跳过
		double _width = x->_cardSprite->getContentSize().width / 2;
		double _height = x->_cardSprite->getContentSize().height / 2;
		Vec2 _cardPosition = x->_cardSprite->getPosition();
		auto _offset = _cardPosition - _TouchPosition;
		if ((fabs(_offset.x) <= _width) && (fabs(_offset.y) <= _height))//说明鼠标所点击的位置就是卡片所在的位置
		{
			x->setCardIsSelected();
			switch (x->_cardMyCardType)
			{
			case BaseCardTypePeaShoooter:
			{
				MousePlantsSprite = Sprite::create("Plants/VirtualPeashooter.png");
				copyMousePlantsSprite = Sprite::create("Plants/VirtualPeashooter.png");
				MousePlantsSprite->setOpacity(150);
				MousePlantsSprite->setTag(MousePlantsSpriteTag);
				copyMousePlantsSprite->setTag(MousePlantsSpriteTag + 1);
				//this->removeChildByTag(MousePlantsSpriteTag);
				this->addChild(MousePlantsSprite, PlantsZ); 
				this->addChild(copyMousePlantsSprite, PlantsZ + 1);
				copyMousePlantsSprite->setPosition(_TouchPosition);
				SelectedCard = x;
				SelectedPlantsType = _PlantsTypePeaShooter;
				break;
			}
			case BaseCardTypeSunFlower:
			{
				MousePlantsSprite = Sprite::create("Plants/VirtualSunFlower.png");
				copyMousePlantsSprite = Sprite::create("Plants/VirtualSunFlower.png");
				MousePlantsSprite->setOpacity(150);
				MousePlantsSprite->setTag(MousePlantsSpriteTag);
				copyMousePlantsSprite->setTag(MousePlantsSpriteTag + 1);
				//this->removeChildByTag(MousePlantsSpriteTag);
				this->addChild(MousePlantsSprite, PlantsZ);
				this->addChild(copyMousePlantsSprite, PlantsZ + 1);
				copyMousePlantsSprite->setPosition(_TouchPosition);
				SelectedCard = x;
				SelectedPlantsType = _PlantsTypeSunFlower;
				break;
			}
			default:
			{
				break;
			}
			}
			return true;
		}
	}

	return true;
}

void HelloWorld::onTouchMoved(Touch * touch, Event * unused_event)
{
	if (MousePlantsSprite != nullptr && SelectedCard != nullptr && copyMousePlantsSprite!=nullptr)
	{
		int _row, _col;
		copyMousePlantsSprite->setPosition(touch->getLocation());
		if (tempAI->ChangePositionToVec2(touch->getLocation(), _row, _col))//鼠标位置在坑中
		{
			if(ArrOfPlantsVisits[_row][_col]==false)	MousePlantsSprite->setPosition(positionOfPlants[_row][_col]);
			else
			{
				MousePlantsSprite->setPosition(touch->getLocation());
			}
		}
		else
		{
			MousePlantsSprite->setPosition(touch->getLocation());
		}
	}
}

void HelloWorld::onTouchEnded(Touch * touch, Event * unused_event)
{
	if (MousePlantsSprite != nullptr && SelectedCard != nullptr)
	{
		int _row, _col;
		if (tempAI->ChangePositionToVec2(touch->getLocation(), _row, _col))//鼠标位置在坑中
		{
			if (tempAI->JudgeRowColCanGrowPlants(_row,_col)==false)//当前位置可以种植
			{
				GrowAPlantInRowCol(_row, _col, SelectedPlantsType);
			}
		}


		this->removeChildByTag(MousePlantsSpriteTag);
		this->removeChildByTag(MousePlantsSpriteTag + 1);
		MousePlantsSprite->release();
		copyMousePlantsSprite->release();
		MousePlantsSprite = nullptr;
		copyMousePlantsSprite = nullptr;
		SelectedCard->setCardIsReleased();
		SelectedCard = nullptr;
	}
}

void HelloWorld::update(float delta)
{
	if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Grasswalk.mp3");
	}
	//--_GroupSun;
	if (GameOverFlag == true)
	{
		_delayTime += delta;
		if (_delayTime >= 3.2)
		{
			//这里更换场景
			if (tempAI->judgeTheGameIsSuccess == true)
			{
				Director::getInstance()->replaceScene(GameOverSuccessScene::createScene());//这里是成功通关的界面
			}
			else
			{
				Director::getInstance()->replaceScene(GameOverFailedScene::createScene());//这里是失败界面
			}
		}
	}

	if (_GroupCurrentSun != _GroupSun)//如果阳光值发生了变化，更新显示的阳光值
	{
		_GroupCurrentSun = _GroupSun;
		string str = to_string(_GroupCurrentSun);
		auto SunItem = this->getChildByTag(SunLabelTag);
		SunItem->removeChildByTag(SunNumItemTag);
		auto MySunNumItem = Label::createWithBMFont("fonts/futura-48.fnt", str.c_str());
		MySunNumItem->setScale(0.5);
		MySunNumItem->setPosition(Vec2(70, 15));
		MySunNumItem->setTag(SunNumItemTag);
		SunItem->addChild(MySunNumItem);
	}

	//判断游戏是否结束
	if (tempAI->judgeTheGameIsOver == true && GameOverFlag == false)
	{
		GameOverFlag = true;
		if (tempAI->judgeTheGameIsSuccess == true)
		{
			log("success");
		}
		else
		{
			auto GamefailSprite = Sprite::create("ZombiesWon.png");
			GamefailSprite->setPosition(Director::getInstance()->getVisibleSize()/2);
			this->addChild(GamefailSprite, 111);
			GamefailSprite->runAction(ScaleTo::create(3.0, 1.5));
		}
	}
}

bool HelloWorld::GrowAPlantInRowCol(int _row, int _col, PlantsType _type)
{

	if (ArrOfPlantsVisits[_row][_col] == true)	return false;//说明该位置已经有植物了，不能种植，返回false

	//这里判断这种类型的植物卡片是否过了冷却时间
	BaseCard* _tempcard;
	switch (_type)
	{
	case _PlantsTypeNone:
	{
		break;
	}
	case _PlantsTypePeaShooter:
	{
		for (auto &x : CardGroup)
		{
			if (x->_cardMyCardType == BaseCardTypePeaShoooter)
			{
				_tempcard = x;
				break;
			}
		}
		break;
	}
	case _PlantsTypeSunFlower:
	{
		for (auto &x : CardGroup)
		{
			if (x->_cardMyCardType == BaseCardTypeSunFlower)
			{
				_tempcard = x;
				break;
			}
		}
		break;
	}
	default:
	{
		break;
	}
	}
	if (_tempcard->_cardIsAvaliable == true)//说明已经过了冷却时间
	{
		//判断当前的阳光是否足够种植该植物
		if (_GroupSun >= _tempcard->_cardSunCost)//阳光足够
		{
			//调用种植植物的相关函数
			_tempcard->setCardEnable(false);
			_GroupSun -= _tempcard->_cardSunCost;
			tempAI->CreateAPlants(_row, _col, _type);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
