#pragma once
#include "Card/BaseCard.h"

class SunFlowerCard:public BaseCard
{
public:
	SunFlowerCard();
	~SunFlowerCard();

	virtual void update(float delta);//更新函数

	virtual void MyInit();//初始化
};

