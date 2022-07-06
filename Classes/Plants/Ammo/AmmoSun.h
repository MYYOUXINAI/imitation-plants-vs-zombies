#pragma once
#include "Plants/Ammo/Ammo.h"


class AmmoSun:public Ammo
{
public:
	AmmoSun();
	~AmmoSun();

	virtual void RunAmmoCreateAnimate();//播放阳光产生的动画
	virtual void RunAmmoDisappearAnimate();//播放弹药消失的动画
	virtual void RunAmmoBreakAnimate();//播放弹药破碎动画


	virtual void update(float delta);//更新函数
	
	virtual void initPicAnimate();//初始化阳光待机动画

	static bool addThePicFlag;//用于判断阳光的待机动画是否被添加到帧缓存当中
};

