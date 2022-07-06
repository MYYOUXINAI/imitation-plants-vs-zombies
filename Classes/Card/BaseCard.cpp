#include "BaseCard.h"

BaseCard::BaseCard()
{
}

BaseCard::~BaseCard()
{
}

void BaseCard::update(float delta)
{
}

void BaseCard::MyInit()
{
}

void BaseCard::setCardEnable(bool _flag)
{
	_cardIsAvaliable = _flag;
	if (_flag == false)
	{
		this->_cardMyCdTime = 0.0;
	}
}

void BaseCard::setCardPosition(Vec2 _position)
{
	_cardSprite->setPosition(_position);
	_cardSpriteUnavaliable->setPosition(_position);
}

void BaseCard::setCardIsSelected()
{
	_cardIsSelected = true;
	this->RunSelectedAnimate();//播放闪烁动画
}

void BaseCard::setCardIsReleased()
{
	_cardIsSelected = false;
	this->StopSelectedAnimate();
}

void BaseCard::RunSelectedAnimate()
{
	Blink *bl = Blink::create(10.0f, 15);
	this->_cardSprite->runAction(RepeatForever::create(bl));
}

void BaseCard::StopSelectedAnimate()
{
	this->_cardSprite->stopAllActions();
	this->_cardSprite->runAction(Repeat::create(Blink::create(1.0f, 2), 1));//这里让卡片再闪烁一次，
	//防止因为之前的停止动画，导致卡片处于闪烁的消失状态中
}
