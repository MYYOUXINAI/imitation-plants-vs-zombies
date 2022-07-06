#include "SunFlowerCard.h"

SunFlowerCard::SunFlowerCard()
{
	this->MyInit();

	//开启调度器
	this->scheduleUpdate();
}

SunFlowerCard::~SunFlowerCard()
{
}

void SunFlowerCard::update(float delta)
{
	_cardMyCdTime += delta;
	if (_cardMyCdTime >= _cardCd /*&& _cardIsAvaliable == false*/ && _GroupSun >= _cardSunCost)//如果冷却完成并且现有阳光足够，那么就将卡片设置为可以选择
	{
		_cardIsAvaliable = true;
	}
	else
	{
		_cardIsAvaliable = false;
	}
	
	if (_cardIsAvaliable == true && _cardCurrentstate==false)
	{
		_cardCurrentstate = true;
		_cardSprite->setVisible(true);
		_cardSunCostLabel->setVisible(true);
		_cardSpriteUnavaliable->setVisible(false);
		_cardSunCostLabel1->setVisible(false);
	}
	else if(_cardIsAvaliable == false && _cardCurrentstate == true)
	{
		_cardCurrentstate = false;
		_cardSprite->setVisible(false);
		_cardSunCostLabel->setVisible(false);
		_cardSpriteUnavaliable->setVisible(true);
		_cardSunCostLabel1->setVisible(true);
	}
	else
	{

	}
}

void SunFlowerCard::MyInit()
{

	_cardIsSelected = false;

	//这里初始化精灵
	_cardSprite = Sprite::create("Card/SunFlower.png");
	_cardSpriteUnavaliable = Sprite::create("Card/SunFlower1.png");
	_cardSunCostLabel = Label::createWithBMFont("fonts/futura-48.fnt", "50");
	_cardSunCostLabel1 = Label::createWithBMFont("fonts/futura-48.fnt", "50");
	_cardSunCostLabel->setScale(0.4);
	_cardSunCostLabel1->setScale(0.4);
	_cardSprite->addChild(_cardSunCostLabel);
	_cardSpriteUnavaliable->addChild(_cardSunCostLabel1);
	_cardSunCostLabel->setPosition(Vec2(75, 10));
	_cardSunCostLabel1->setPosition(Vec2(75, 10));

	_cardCurrentstate = true;
	_cardSprite->setVisible(true);
	_cardSunCostLabel->setVisible(true);
	_cardSpriteUnavaliable->setVisible(false);
	_cardSunCostLabel1->setVisible(false);


	_cardCd = 7.5;
	_cardMyCdTime = 7.5;

	_cardSunCost = 50;

	_cardIsAvaliable = true;
	_cardCurrentstate = true;

	_cardMyCardType = BaseCardTypeSunFlower;
}
