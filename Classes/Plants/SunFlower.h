#pragma once
#include "Plants/Plants.h"


class SunFlower:public Plants
{
public:

	SunFlower();
	~SunFlower();

	virtual void MyInit();//���ڳ�ʼ�����տ��ĸ��ֻ�������

	virtual void initAnimateOfWait();//���ڳ�ʼ�����տ��Ĵ�������

	virtual void update(float delta);//���º���

	static bool addTheWaitAnimateFlag;//�����ж����տ��Ĵ��������Ƿ��Ѿ�����ӵ�֡���浱��
};

