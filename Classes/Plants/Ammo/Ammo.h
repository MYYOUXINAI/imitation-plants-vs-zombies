#pragma once
#include "cocos2d.h"
#include "iostream"

using namespace std;
using namespace cocos2d;

//这里为植物发射弹药的基类，包括阳光、豌豆等等
enum AmmoType
{
	_AmmoTypeNone=-1,
	_AmmoTypeSun,//阳光
	_AmmoTypePea//豌豆
};

class Ammo:public Sprite
{
public:
	Ammo();
	~Ammo();

	virtual void RunAmmoBreakAnimate();//播放弹药破碎动画
	virtual void RunAmmoCreateAnimate();//播放弹药产生的动画
	virtual void RunAmmoDisappearAnimate();//播放弹药消失的动画
	virtual void RunAmmoCreateFromSkyAnimate();//播放弹药从天空中产生的动画

	virtual void initPicAnimate();//初始化弹药贴图
	virtual void initPicDisappearAnimate();//初始化弹药消失贴图
	virtual void AmmoSetPosition(Vec2 _ve);//用于设置位置
	virtual void setAmmoRowCol(int _row);//用于设置弹药所处的行


	Sprite* _AmmoPicSprite;//用于显示弹药的贴图
	Sprite* _AmmoPicDisappearSprite;//用于显示弹药消失的图片
	
	Animate* _AnimateOfPic;//弹药发射动画
	Animate* _AnimateOfPicDisappear;//弹药消失动画

	AmmoType _MyAmmoType;//弹药的类型


	double _AmmoDisappearSpeed;//弹药消失的时间间隔
	double _AmmoMDisappearTime;//用于计时

	double _AmmoSpeed;//弹药的发射速度
	Vec2 _AmmoPosition;//弹药的位置
	int _AmmoRow;//弹药所处的行

	bool _AmmoDie;//用于判断弹药是否已经破碎
};

