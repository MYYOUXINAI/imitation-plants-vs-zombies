#pragma once
#include "Plants/Ammo/Ammo.h"

class AmmoPea:public Ammo
{
public:

	AmmoPea();
	~AmmoPea();


	virtual void RunAmmoBreakAnimate();//播放弹药破碎动画

	virtual void update(float delta);//更新函数，用于让豌豆向右移动

	virtual void initPicAnimate();//初始化弹药飞行动画
	virtual void initPicDisappearAnimate();//初始化弹药消失动画

	static bool addThePicFlag;//用于判断弹药贴图是否被添加到帧缓存当中
	static bool addThePicDisppearFlag;//用于判断弹药消失贴图是否被添加到帧缓存当中
};

