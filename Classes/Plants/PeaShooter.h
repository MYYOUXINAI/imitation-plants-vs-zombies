#pragma once
#include "Plants/Plants.h"
class PeaShooter :
	public Plants
{
public:
	PeaShooter();//���ڴ���ֲ�����
	~PeaShooter();


	virtual void MyInit();//���ڳ�ʼ��ֲ��ĸ�������

	virtual void initAnimateOfWait();//��ʼ��ֲ��Ĵ�������

	virtual void update(float delta);//���º���

	static bool addTheWaitAnimateFlag;//�����ж�ֲ��Ĵ��������Ƿ��Ѿ�����ӵ���֡���浱��
};

