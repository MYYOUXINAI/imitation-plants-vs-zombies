#pragma once
#include "Card/BaseCard.h"

class PeaShooterCard:public BaseCard
{
public:
	PeaShooterCard();
	~PeaShooterCard();

	virtual void update(float delta);//���º���
	
	virtual void MyInit();//��ʼ��


};

