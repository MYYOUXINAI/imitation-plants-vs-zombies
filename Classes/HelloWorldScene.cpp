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

	////���ֲ��
	//for (int i = 1; i <= 5; i++)
	//{
	//	//SunFlower* tempPlants = new SunFlower;
	//	//PlantsGroup.push_back(tempPlants);
	//	//tempPlants->_plantsSprite->setPosition(positionOfPlants[i-1][0]);
	//	//ArrOfPlantsVisits[i - 1][0] = true;//�ÿ�λ�Ѿ���ռ��
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
	//	//ArrOfPlantsVisits[i - 1][1] = true;//�ÿ�λ�Ѿ���ռ��
	//	//tempPlants->_plantsSprite->setScale(1.2);
	//	//tempPlants->setPlantsRowCol(i-1, 1);
	//	//this->addChild(tempPlants->_plantsSprite, PlantsZ);
	//	//this->addChild(tempPlants, PlantsZ);
	//	tempAI->CreateAPlants(i - 1, 1, _PlantsTypePeaShooter);
	//}



	////��ӽ�ʬ
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

	//�����ǳ�ʼ��ȫ�ֱ�������
	_GroupSun = 150;
	_GroupCurrentSun = _GroupSun;

	ZombiesGroup.clear();
	PlantsGroup.clear();
	AmmoGroup.clear();
	CardGroup.clear();


	positionOfPlants.resize(5, vector<Vec2>(9));
	//�����ϵ�����Ϊ��47��664���������ϵ�����Ϊ��964��662���������µ�����Ϊ��43��54���������µ�����Ϊ��973��46��
	//���ڳ�ʼ��λ�þ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			positionOfPlants[i][j] = Vec2(100 + 103 * j, 100 + 125 * i);
		}
	}


	//�����ʼ��������λ����û�б���ֲ��
	ArrOfPlantsVisits.resize(5, vector<bool>(9, false));


	//�����ʼ���ؿ�����ͼ
	auto sprite = Sprite::create("Scene/background1.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2));
	this->addChild(sprite, BackGroundZ);
	sprite->setScale(1.275);


	//�����ʼ����ʾ�Ѿ��������ͼƬ
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


	//���һ������Ӧ�¼�����������ʵ�ֵ�����⣬ʵ�ֹؿ����������ӵ�Ч��
	//ʵ�������ֲ�￨Ƭ���϶�ֲ�￨Ƭ���հ׵Ŀ���ֲλ�ã�ʵ��ֲ����ֲ��Ч��
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved= CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//�������һ��ֲ���ʬ�Ĺ���AI
	tempAI = new PlantsAttack;
	tempAI->setParentScene(this);
	this->addChild(tempAI);


	//����������տ����㶹���ֵĿ�Ƭ
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
	for (auto &x : AmmoGroup)//����鿴�����λ���Ƿ�������
	{
		if (x->_AmmoDie == true)	continue;
		double _width = x->_AmmoPicSprite->getContentSize().width / 2;
		double _height = x->_AmmoPicSprite->getContentSize().height / 2;
		Vec2 _SunPosition = x->_AmmoPicSprite->getPosition();
		auto _offset = _SunPosition - _TouchPosition;
		if ((fabs(_offset.x) <= _width) && (fabs(_offset.y) <= _height))//˵�������λ������������λ��
		{
			_GroupSun += 50;
			x->RunAmmoDisappearAnimate();
			return true;
		}
	}

	//����鿴�������λ���ǲ���ֲ�￨Ƭ��λ��
	for (auto &x : CardGroup)
	{
		if (x->_cardIsAvaliable == false)	continue;//�����Ƭcdû�ã�ֱ������
		double _width = x->_cardSprite->getContentSize().width / 2;
		double _height = x->_cardSprite->getContentSize().height / 2;
		Vec2 _cardPosition = x->_cardSprite->getPosition();
		auto _offset = _cardPosition - _TouchPosition;
		if ((fabs(_offset.x) <= _width) && (fabs(_offset.y) <= _height))//˵������������λ�þ��ǿ�Ƭ���ڵ�λ��
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
		if (tempAI->ChangePositionToVec2(touch->getLocation(), _row, _col))//���λ���ڿ���
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
		if (tempAI->ChangePositionToVec2(touch->getLocation(), _row, _col))//���λ���ڿ���
		{
			if (tempAI->JudgeRowColCanGrowPlants(_row,_col)==false)//��ǰλ�ÿ�����ֲ
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
			//�����������
			if (tempAI->judgeTheGameIsSuccess == true)
			{
				Director::getInstance()->replaceScene(GameOverSuccessScene::createScene());//�����ǳɹ�ͨ�صĽ���
			}
			else
			{
				Director::getInstance()->replaceScene(GameOverFailedScene::createScene());//������ʧ�ܽ���
			}
		}
	}

	if (_GroupCurrentSun != _GroupSun)//�������ֵ�����˱仯��������ʾ������ֵ
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

	//�ж���Ϸ�Ƿ����
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

	if (ArrOfPlantsVisits[_row][_col] == true)	return false;//˵����λ���Ѿ���ֲ���ˣ�������ֲ������false

	//�����ж��������͵�ֲ�￨Ƭ�Ƿ������ȴʱ��
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
	if (_tempcard->_cardIsAvaliable == true)//˵���Ѿ�������ȴʱ��
	{
		//�жϵ�ǰ�������Ƿ��㹻��ֲ��ֲ��
		if (_GroupSun >= _tempcard->_cardSunCost)//�����㹻
		{
			//������ֲֲ�����غ���
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
