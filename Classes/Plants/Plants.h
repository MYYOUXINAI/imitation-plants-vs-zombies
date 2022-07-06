#pragma once

#include "cocos2d.h"
#include "iostream"
#include "Data/BaseData.h"

using namespace std;
using namespace cocos2d;

/*ֲ�������*/
enum  PlantsType
{
	_PlantsTypeNone = -1,
	_PlantsTypePeaShooter,//�����㶹����
	_PlantsTypeSunFlower//���տ�
};


class Plants :public Sprite
{
public:
	Plants();
	~Plants();

	virtual bool plantsIsLive();//����ֲ���Ƿ���

	virtual void setPlantsRowCol(int _row, int _col);//��������ֲ�������

	virtual void initAnimateOfWait();//��ʼ��ֲ��Ĵ�������

	virtual void CallItWhenHurt(int _value);//��ֲ���ܵ�����ʱ�����øú����ӿ�


	virtual void CallItWhenDie();//��ֲ������ʱ�����øú����ӿ�

	virtual void RunShineAnimate();//����ֲ���ܻ���˸����


	/*ֲ�������*/
	int _plantsMaxBlood;//ֲ������Ѫ��
	int _plantsCurrentBlood;//ֲ��ĵ�ǰѪ��
	PlantsType _plantsType;//ֲ�������
	int _plantsTag;//ֲ��ı��
	int _plantsDamage;//ֲ��Ĺ�����
	int _plantsSunCost;//��ֲ��ֲ������Ҫ���ѵ�����


	double _baseAttackTime;//����ֲ��Ĺ������
	double _mAttackTime;//����һ����ʱ���������жϵ�ǰֲ���Ƿ���Խ�����һ�ι���
	double _plantsRecoverTime;//ֲ�￨����ȴʱ��

	Animate* _plantsAnimateOfWait;//ֲ��Ĵ�������


	Sprite* _plantsSprite;//ֲ�ﾫ��
	Vec2 _plantsPosition;//ֲ���λ��
	int _plantsRow;//ֲ�ﴦ�ڵڼ���
	int _plantsCol;//ֲ�ﴦ�ڵڼ���
	
	bool _PlantsIsDead;//�����ж�ֲ���Ƿ��Ѿ�����

};

