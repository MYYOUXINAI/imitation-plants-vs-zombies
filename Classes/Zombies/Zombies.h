#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace std;
using namespace cocos2d;

//作为所有僵尸的基类，所有类型的僵尸都在这个基础上进行派生

/*僵尸的类型*/
enum ZombiesType
{
	_ZombiesTypeNone = -1,
	_ZombiesTypeZombies//普通僵尸
};

/*僵尸的状态*/
enum ZombiesState
{
	_ZombiesStateNone = -1 ,
	_ZombiesStateWait,//等待
	_ZombiesStateWalk,//行走
	_ZombiesStateEat,//进食
	_ZombiesStateDie//死亡
};


class Zombies :public Sprite
{
public:
	Zombies();
	~Zombies();

	virtual void myInit();//初始化僵尸的各种属性
	virtual void initWalkAnimate();//初始化行走动画
	virtual void initEatAnimate();//初始化僵尸的啃食动画
	virtual void initHeadDownAnimate();//初始化僵尸头部掉落动画
	virtual void initDeadWalkAnimate();//初始化僵尸在行走过程中死亡的动画
	virtual void initDeadEatAnimate();//初始化僵尸在啃食过程中死亡的动画
	virtual void initFellAnimate();//初始化僵尸的倒地动画
	virtual void initWaitAnimate();//初始化僵尸的待机动画



	virtual bool judgeIsWalk();//返回僵尸是否处于行走状态
	virtual bool judgeIsEat();//返回僵尸是否处于攻击状态

	virtual bool RunEatAnimate();//播放僵尸的啃食动画
	virtual bool RunDieAnimate();//播放僵尸的死亡动画
	virtual bool RunWalkAnimate();//播放僵尸的行走动画
	virtual bool RunShineAnimate();//播放僵尸的闪烁动画
	virtual bool RunWaitAnimate();//播放僵尸的等待动画


	virtual bool ChangeStateToWait();//将僵尸的状态更改为等待
	virtual bool ChangeStateToWalk();//将僵尸的状态更改为行走
	virtual bool ChangeStateToEat();//将僵尸的状态更改为进食
	virtual bool ChangeStateToDie();//将僵尸的状态更改为死亡



	virtual void CallItWhenHurt(int _hurtValue);//当僵尸受到攻击时，调用该接口函数

	virtual void setRowCol(int _row, int _col=-1);//用于设置僵尸的行和列


	/*僵尸的属性*/
	int _zombiesmaxBlood;//僵尸的最大血量
	int _zombiescurrentBlood;//僵尸的当前血量
	ZombiesType _zombiesType;//僵尸的类型
	int _zombiesTag;//僵尸的编号
	float _zombiesCurrentSpeed;//僵尸当前的速度
	float _zombiesDamage;//僵尸的攻击力


	double _baseAttackTime;//定义僵尸的攻击间隔
	double _mAttackTime;//定义一个计时器，用于判断僵尸是否可以进行下一次攻击

	Animate* _zombiesAnimateOfWait;//僵尸的待机动画
	Animate* _zombiesAnimateOfWalk;//僵尸的行走动画
	Animate* _zombiesAnimateOfEat;//僵尸啃食动画
	Animate* _zombiesAnimateOfHeadDown;//僵尸头部掉落的动画，这个动画被绑定在指向僵尸头部的精灵当中
	Animate* _zombiesAnimateOfDeadWalk;//僵尸在行走过程中死亡
	Animate* _zombiesAnimateOfDeadEat;//僵尸在攻击过程中死亡
	Animate* _zombiesAnimateOfFell;//僵尸倒地动画

	Sprite* _zombiesSprite;//精灵
	Sprite* _zombiesHeadSprite;//指向僵尸头部的精灵,用于死亡动画当中的僵尸头部掉落动画实现

	int _zombiesRow;//僵尸处于第几行
	int _zombiesCol;//僵尸处于第几列

	bool isWalk;//僵尸是否处于行走状态
	bool isEat;//僵尸是否处于攻击状态
	bool isDead;//僵尸是否已经死亡
	bool isWait;//僵尸是否处于等待进攻状态

	ZombiesState _zombiesMyState;//用于记录僵尸当前的状态
};

