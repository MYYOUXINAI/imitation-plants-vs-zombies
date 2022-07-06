#pragma once
#include "Zombies/Zombies.h"

class NormalZombies:public Zombies
{
public:
	NormalZombies();
	~NormalZombies();


	virtual void myInit();//初始化僵尸的各种属性
	virtual void update(float delta);//更新函数

	virtual void initEatAnimate();//初始化僵尸的啃食动画
	virtual void initWalkAnimate();//初始化僵尸行走动画	
	virtual void initHeadDownAnimate();//初始化僵尸头部掉落动画
	virtual void initDeadWalkAnimate();//初始化僵尸在行走过程中死亡的动画
	virtual void initDeadEatAnimate();//初始化僵尸在啃食过程中死亡的动画
	virtual void initFellAnimate();//初始化僵尸的倒地动画
	virtual void initWaitAnimate();//初始化僵尸的待机动画


	static bool addTheWaitAnimateFlag;//用于判断僵尸待机动画是否被添加到帧缓存当中
	static bool addTheWalkAnimateFlag;//用于判断走路动画是否被添加到了帧缓存当中
	static bool addTheEatAnimateFlag;//用于判断僵尸的啃食动画是否被添加到了帧缓存当中
	static bool addTheHeadDownAnimateFlag;//用于判断僵尸头部掉落动画是否被添加到了帧缓存当中
	static bool addTheDeadWalkAnimateFlag;//用于判断行走死亡动画是否被添加到帧缓存当中
	static bool addTheDeadEatAnimateFlag;//用于判断僵尸在攻击时的死亡动画是否被添加到帧缓存当中
	static bool addTheFellAnimateFlag;//用于判断僵尸倒地动画是否被添加到帧缓存当中
};


