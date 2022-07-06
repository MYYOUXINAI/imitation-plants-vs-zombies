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
	this->RunSelectedAnimate();//������˸����
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
	this->_cardSprite->runAction(Repeat::create(Blink::create(1.0f, 2), 1));//�����ÿ�Ƭ����˸һ�Σ�
	//��ֹ��Ϊ֮ǰ��ֹͣ���������¿�Ƭ������˸����ʧ״̬��
}
