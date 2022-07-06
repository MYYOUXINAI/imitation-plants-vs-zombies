#pragma once
#include "Card/BaseCard.h"

class PeaShooterCard:public BaseCard
{
public:
	PeaShooterCard();
	~PeaShooterCard();

	virtual void update(float delta);//更新函数
	
	virtual void MyInit();//初始化


};

