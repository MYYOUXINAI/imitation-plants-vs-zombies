#pragma once
#include "Plants/Plants.h"
class PeaShooter :
	public Plants
{
public:
	PeaShooter();//用于创建植物对象
	~PeaShooter();


	virtual void MyInit();//用于初始化植物的各种属性

	virtual void initAnimateOfWait();//初始化植物的待机动画

	virtual void update(float delta);//更新函数

	static bool addTheWaitAnimateFlag;//用于判断植物的待机动画是否已经被添加到了帧缓存当中
};

