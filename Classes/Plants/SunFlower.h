#pragma once
#include "Plants/Plants.h"


class SunFlower:public Plants
{
public:

	SunFlower();
	~SunFlower();

	virtual void MyInit();//用于初始化向日葵的各种基本属性

	virtual void initAnimateOfWait();//用于初始化向日葵的待机动画

	virtual void update(float delta);//更新函数

	static bool addTheWaitAnimateFlag;//用于判断向日葵的待机动画是否已经被添加到帧缓存当中
};

