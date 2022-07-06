#pragma once

#include "cocos2d.h"
#include "iostream"
#include "Data/BaseData.h"

using namespace std;
using namespace cocos2d;


//卡牌的类型
enum BaseCardType
{
	BaseCardTypeNone=-1,
	BaseCardTypePeaShoooter,//豌豆射手卡牌
	BaseCardTypeSunFlower//向日葵卡牌
};


class BaseCard:public Sprite
{
public:
	BaseCard();
	~BaseCard();

	virtual void update(float delta);//更新函数

	virtual void MyInit();//用于初始化基本属性

	virtual void setCardEnable(bool _flag);//将当前卡牌设置为可用和不可用

	virtual void setCardPosition(Vec2 _position);//设置卡牌位置

	virtual void setCardIsSelected();//设置卡牌已经被选中

	virtual void setCardIsReleased();//设置卡牌从选中被释放

	virtual void RunSelectedAnimate();//当卡牌被选中时，播放卡牌闪烁动画

	virtual void StopSelectedAnimate();//当卡牌被释放时，停止卡牌闪烁动画

	double _cardCd;//卡牌的冷却cd
	double _cardMyCdTime;//用于判断当前卡牌是否已经过了冷却事件

	BaseCardType _cardMyCardType;//卡牌的类型

	Sprite* _cardSprite;//用于挂载卡牌图片的精灵
	Sprite* _cardSpriteUnavaliable;//用于挂载当前卡牌不可选图片的精灵
	Label* _cardSunCostLabel;//用于挂载阳光标签
	Label* _cardSunCostLabel1;//用于挂载阳光标签

	bool _cardIsAvaliable;//用于判断当前卡牌是否可以使用
	int _cardSunCost;//卡牌所需要消耗的阳光

	bool _cardCurrentstate;//用于判断当前的状态

	bool _cardIsSelected;//判断卡片是否被选中
};

