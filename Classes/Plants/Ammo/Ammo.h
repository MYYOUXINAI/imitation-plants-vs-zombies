#pragma once
#include "cocos2d.h"
#include "iostream"

using namespace std;
using namespace cocos2d;

//����Ϊֲ�﷢�䵯ҩ�Ļ��࣬�������⡢�㶹�ȵ�
enum AmmoType
{
	_AmmoTypeNone=-1,
	_AmmoTypeSun,//����
	_AmmoTypePea//�㶹
};

class Ammo:public Sprite
{
public:
	Ammo();
	~Ammo();

	virtual void RunAmmoBreakAnimate();//���ŵ�ҩ���鶯��
	virtual void RunAmmoCreateAnimate();//���ŵ�ҩ�����Ķ���
	virtual void RunAmmoDisappearAnimate();//���ŵ�ҩ��ʧ�Ķ���
	virtual void RunAmmoCreateFromSkyAnimate();//���ŵ�ҩ������в����Ķ���

	virtual void initPicAnimate();//��ʼ����ҩ��ͼ
	virtual void initPicDisappearAnimate();//��ʼ����ҩ��ʧ��ͼ
	virtual void AmmoSetPosition(Vec2 _ve);//��������λ��
	virtual void setAmmoRowCol(int _row);//�������õ�ҩ��������


	Sprite* _AmmoPicSprite;//������ʾ��ҩ����ͼ
	Sprite* _AmmoPicDisappearSprite;//������ʾ��ҩ��ʧ��ͼƬ
	
	Animate* _AnimateOfPic;//��ҩ���䶯��
	Animate* _AnimateOfPicDisappear;//��ҩ��ʧ����

	AmmoType _MyAmmoType;//��ҩ������


	double _AmmoDisappearSpeed;//��ҩ��ʧ��ʱ����
	double _AmmoMDisappearTime;//���ڼ�ʱ

	double _AmmoSpeed;//��ҩ�ķ����ٶ�
	Vec2 _AmmoPosition;//��ҩ��λ��
	int _AmmoRow;//��ҩ��������

	bool _AmmoDie;//�����жϵ�ҩ�Ƿ��Ѿ�����
};

