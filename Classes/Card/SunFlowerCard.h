#pragma once
#include "Card/BaseCard.h"

class SunFlowerCard:public BaseCard
{
public:
	SunFlowerCard();
	~SunFlowerCard();

	virtual void update(float delta);//���º���

	virtual void MyInit();//��ʼ��
};

