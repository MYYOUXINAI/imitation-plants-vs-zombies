#pragma once
#include "Plants/Ammo/Ammo.h"


class AmmoSun:public Ammo
{
public:
	AmmoSun();
	~AmmoSun();

	virtual void RunAmmoCreateAnimate();//������������Ķ���
	virtual void RunAmmoDisappearAnimate();//���ŵ�ҩ��ʧ�Ķ���
	virtual void RunAmmoBreakAnimate();//���ŵ�ҩ���鶯��


	virtual void update(float delta);//���º���
	
	virtual void initPicAnimate();//��ʼ�������������

	static bool addThePicFlag;//�����ж�����Ĵ��������Ƿ���ӵ�֡���浱��
};

