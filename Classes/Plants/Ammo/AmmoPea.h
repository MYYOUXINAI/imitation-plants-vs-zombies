#pragma once
#include "Plants/Ammo/Ammo.h"

class AmmoPea:public Ammo
{
public:

	AmmoPea();
	~AmmoPea();


	virtual void RunAmmoBreakAnimate();//���ŵ�ҩ���鶯��

	virtual void update(float delta);//���º������������㶹�����ƶ�

	virtual void initPicAnimate();//��ʼ����ҩ���ж���
	virtual void initPicDisappearAnimate();//��ʼ����ҩ��ʧ����

	static bool addThePicFlag;//�����жϵ�ҩ��ͼ�Ƿ���ӵ�֡���浱��
	static bool addThePicDisppearFlag;//�����жϵ�ҩ��ʧ��ͼ�Ƿ���ӵ�֡���浱��
};

