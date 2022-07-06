#pragma once

#include "cocos2d.h"
#include <iostream>

using namespace std;
using namespace cocos2d;

//��Ϊ���н�ʬ�Ļ��࣬�������͵Ľ�ʬ������������Ͻ�������

/*��ʬ������*/
enum ZombiesType
{
	_ZombiesTypeNone = -1,
	_ZombiesTypeZombies//��ͨ��ʬ
};

/*��ʬ��״̬*/
enum ZombiesState
{
	_ZombiesStateNone = -1 ,
	_ZombiesStateWait,//�ȴ�
	_ZombiesStateWalk,//����
	_ZombiesStateEat,//��ʳ
	_ZombiesStateDie//����
};


class Zombies :public Sprite
{
public:
	Zombies();
	~Zombies();

	virtual void myInit();//��ʼ����ʬ�ĸ�������
	virtual void initWalkAnimate();//��ʼ�����߶���
	virtual void initEatAnimate();//��ʼ����ʬ�Ŀ�ʳ����
	virtual void initHeadDownAnimate();//��ʼ����ʬͷ�����䶯��
	virtual void initDeadWalkAnimate();//��ʼ����ʬ�����߹����������Ķ���
	virtual void initDeadEatAnimate();//��ʼ����ʬ�ڿ�ʳ�����������Ķ���
	virtual void initFellAnimate();//��ʼ����ʬ�ĵ��ض���
	virtual void initWaitAnimate();//��ʼ����ʬ�Ĵ�������



	virtual bool judgeIsWalk();//���ؽ�ʬ�Ƿ�������״̬
	virtual bool judgeIsEat();//���ؽ�ʬ�Ƿ��ڹ���״̬

	virtual bool RunEatAnimate();//���Ž�ʬ�Ŀ�ʳ����
	virtual bool RunDieAnimate();//���Ž�ʬ����������
	virtual bool RunWalkAnimate();//���Ž�ʬ�����߶���
	virtual bool RunShineAnimate();//���Ž�ʬ����˸����
	virtual bool RunWaitAnimate();//���Ž�ʬ�ĵȴ�����


	virtual bool ChangeStateToWait();//����ʬ��״̬����Ϊ�ȴ�
	virtual bool ChangeStateToWalk();//����ʬ��״̬����Ϊ����
	virtual bool ChangeStateToEat();//����ʬ��״̬����Ϊ��ʳ
	virtual bool ChangeStateToDie();//����ʬ��״̬����Ϊ����



	virtual void CallItWhenHurt(int _hurtValue);//����ʬ�ܵ�����ʱ�����øýӿں���

	virtual void setRowCol(int _row, int _col=-1);//�������ý�ʬ���к���


	/*��ʬ������*/
	int _zombiesmaxBlood;//��ʬ�����Ѫ��
	int _zombiescurrentBlood;//��ʬ�ĵ�ǰѪ��
	ZombiesType _zombiesType;//��ʬ������
	int _zombiesTag;//��ʬ�ı��
	float _zombiesCurrentSpeed;//��ʬ��ǰ���ٶ�
	float _zombiesDamage;//��ʬ�Ĺ�����


	double _baseAttackTime;//���彩ʬ�Ĺ������
	double _mAttackTime;//����һ����ʱ���������жϽ�ʬ�Ƿ���Խ�����һ�ι���

	Animate* _zombiesAnimateOfWait;//��ʬ�Ĵ�������
	Animate* _zombiesAnimateOfWalk;//��ʬ�����߶���
	Animate* _zombiesAnimateOfEat;//��ʬ��ʳ����
	Animate* _zombiesAnimateOfHeadDown;//��ʬͷ������Ķ������������������ָ��ʬͷ���ľ��鵱��
	Animate* _zombiesAnimateOfDeadWalk;//��ʬ�����߹���������
	Animate* _zombiesAnimateOfDeadEat;//��ʬ�ڹ�������������
	Animate* _zombiesAnimateOfFell;//��ʬ���ض���

	Sprite* _zombiesSprite;//����
	Sprite* _zombiesHeadSprite;//ָ��ʬͷ���ľ���,���������������еĽ�ʬͷ�����䶯��ʵ��

	int _zombiesRow;//��ʬ���ڵڼ���
	int _zombiesCol;//��ʬ���ڵڼ���

	bool isWalk;//��ʬ�Ƿ�������״̬
	bool isEat;//��ʬ�Ƿ��ڹ���״̬
	bool isDead;//��ʬ�Ƿ��Ѿ�����
	bool isWait;//��ʬ�Ƿ��ڵȴ�����״̬

	ZombiesState _zombiesMyState;//���ڼ�¼��ʬ��ǰ��״̬
};

