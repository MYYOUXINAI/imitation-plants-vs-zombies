#pragma once

#include "cocos2d.h"
#include "iostream"
#include "Data/BaseData.h"

using namespace std;
using namespace cocos2d;

/*植物的类型*/
enum  PlantsType
{
	_PlantsTypeNone = -1,
	_PlantsTypePeaShooter,//单发豌豆射手
	_PlantsTypeSunFlower//向日葵
};


class Plants :public Sprite
{
public:
	Plants();
	~Plants();

	virtual bool plantsIsLive();//返回植物是否存活

	virtual void setPlantsRowCol(int _row, int _col);//用于设置植物的行列

	virtual void initAnimateOfWait();//初始化植物的待机动画

	virtual void CallItWhenHurt(int _value);//当植物受到攻击时，调用该函数接口


	virtual void CallItWhenDie();//当植物死亡时，调用该函数接口

	virtual void RunShineAnimate();//播放植物受击闪烁动画


	/*植物的属性*/
	int _plantsMaxBlood;//植物的最大血量
	int _plantsCurrentBlood;//植物的当前血量
	PlantsType _plantsType;//植物的类型
	int _plantsTag;//植物的编号
	int _plantsDamage;//植物的攻击力
	int _plantsSunCost;//种植该植物所需要花费的阳光


	double _baseAttackTime;//定义植物的攻击间隔
	double _mAttackTime;//定义一个计时器，用于判断当前植物是否可以进行下一次攻击
	double _plantsRecoverTime;//植物卡牌冷却时间

	Animate* _plantsAnimateOfWait;//植物的待机动画


	Sprite* _plantsSprite;//植物精灵
	Vec2 _plantsPosition;//植物的位置
	int _plantsRow;//植物处于第几行
	int _plantsCol;//植物处于第几列
	
	bool _PlantsIsDead;//用于判断植物是否已经死亡

};

