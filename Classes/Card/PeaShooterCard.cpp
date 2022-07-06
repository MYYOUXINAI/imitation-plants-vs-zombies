#include "PeaShooterCard.h"

PeaShooterCard::PeaShooterCard()
{
	this->MyInit();

	//����������
	this->scheduleUpdate();
}

PeaShooterCard::~PeaShooterCard()
{
}

void PeaShooterCard::update(float delta)
{
	_cardMyCdTime += delta;
	if (_cardMyCdTime >= _cardCd /*&& _cardIsAvaliable == false*/ && _GroupSun >= _cardSunCost)//�����ȴ��ɲ������������㹻����ô�ͽ���Ƭ����Ϊ����ѡ��
	{
		_cardIsAvaliable = true;
	}
	else
	{
		_cardIsAvaliable = false;
	}
	if (_cardIsAvaliable == true && _cardCurrentstate == false)
	{
		_cardCurrentstate = true;
		_cardSprite->setVisible(true);
		_cardSunCostLabel->setVisible(true);
		_cardSpriteUnavaliable->setVisible(false);
		_cardSunCostLabel1->setVisible(false);
	}
	else if (_cardIsAvaliable == false && _cardCurrentstate == true)
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

void PeaShooterCard::MyInit()
{
	_cardIsSelected = false;

	//�����ʼ������
	_cardSprite = Sprite::create("Card/PeaShooter.png");
	_cardSpriteUnavaliable = Sprite::create("Card/Peashooter1.png");
	_cardSunCostLabel= Label::createWithBMFont("fonts/futura-48.fnt", "100");
	_cardSunCostLabel1 = Label::createWithBMFont("fonts/futura-48.fnt", "100");
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

	_cardSunCost = 100;

	_cardIsAvaliable = true;

	_cardMyCardType = BaseCardTypePeaShoooter;
}
