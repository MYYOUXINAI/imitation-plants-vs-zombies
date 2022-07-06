#pragma once

#include "cocos2d.h"
#include "iostream"
#include "Data/BaseData.h"

using namespace std;
using namespace cocos2d;


//���Ƶ�����
enum BaseCardType
{
	BaseCardTypeNone=-1,
	BaseCardTypePeaShoooter,//�㶹���ֿ���
	BaseCardTypeSunFlower//���տ�����
};


class BaseCard:public Sprite
{
public:
	BaseCard();
	~BaseCard();

	virtual void update(float delta);//���º���

	virtual void MyInit();//���ڳ�ʼ����������

	virtual void setCardEnable(bool _flag);//����ǰ��������Ϊ���úͲ�����

	virtual void setCardPosition(Vec2 _position);//���ÿ���λ��

	virtual void setCardIsSelected();//���ÿ����Ѿ���ѡ��

	virtual void setCardIsReleased();//���ÿ��ƴ�ѡ�б��ͷ�

	virtual void RunSelectedAnimate();//�����Ʊ�ѡ��ʱ�����ſ�����˸����

	virtual void StopSelectedAnimate();//�����Ʊ��ͷ�ʱ��ֹͣ������˸����

	double _cardCd;//���Ƶ���ȴcd
	double _cardMyCdTime;//�����жϵ�ǰ�����Ƿ��Ѿ�������ȴ�¼�

	BaseCardType _cardMyCardType;//���Ƶ�����

	Sprite* _cardSprite;//���ڹ��ؿ���ͼƬ�ľ���
	Sprite* _cardSpriteUnavaliable;//���ڹ��ص�ǰ���Ʋ���ѡͼƬ�ľ���
	Label* _cardSunCostLabel;//���ڹ��������ǩ
	Label* _cardSunCostLabel1;//���ڹ��������ǩ

	bool _cardIsAvaliable;//�����жϵ�ǰ�����Ƿ����ʹ��
	int _cardSunCost;//��������Ҫ���ĵ�����

	bool _cardCurrentstate;//�����жϵ�ǰ��״̬

	bool _cardIsSelected;//�жϿ�Ƭ�Ƿ�ѡ��
};

