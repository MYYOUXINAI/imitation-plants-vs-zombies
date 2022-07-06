#pragma once
#include "Zombies/Zombies.h"

class NormalZombies:public Zombies
{
public:
	NormalZombies();
	~NormalZombies();


	virtual void myInit();//��ʼ����ʬ�ĸ�������
	virtual void update(float delta);//���º���

	virtual void initEatAnimate();//��ʼ����ʬ�Ŀ�ʳ����
	virtual void initWalkAnimate();//��ʼ����ʬ���߶���	
	virtual void initHeadDownAnimate();//��ʼ����ʬͷ�����䶯��
	virtual void initDeadWalkAnimate();//��ʼ����ʬ�����߹����������Ķ���
	virtual void initDeadEatAnimate();//��ʼ����ʬ�ڿ�ʳ�����������Ķ���
	virtual void initFellAnimate();//��ʼ����ʬ�ĵ��ض���
	virtual void initWaitAnimate();//��ʼ����ʬ�Ĵ�������


	static bool addTheWaitAnimateFlag;//�����жϽ�ʬ���������Ƿ���ӵ�֡���浱��
	static bool addTheWalkAnimateFlag;//�����ж���·�����Ƿ���ӵ���֡���浱��
	static bool addTheEatAnimateFlag;//�����жϽ�ʬ�Ŀ�ʳ�����Ƿ���ӵ���֡���浱��
	static bool addTheHeadDownAnimateFlag;//�����жϽ�ʬͷ�����䶯���Ƿ���ӵ���֡���浱��
	static bool addTheDeadWalkAnimateFlag;//�����ж��������������Ƿ���ӵ�֡���浱��
	static bool addTheDeadEatAnimateFlag;//�����жϽ�ʬ�ڹ���ʱ�����������Ƿ���ӵ�֡���浱��
	static bool addTheFellAnimateFlag;//�����жϽ�ʬ���ض����Ƿ���ӵ�֡���浱��
};


