#include "PeaShooter.h"

bool PeaShooter::addTheWaitAnimateFlag = false;//��ʼ��Ϊ��

PeaShooter::PeaShooter()
{
	this->MyInit();

	_plantsSprite = Sprite::create();

	this->initAnimateOfWait();

	_plantsSprite->runAction(RepeatForever::create(_plantsAnimateOfWait));//��ʼ��ʱ����ֲ���ظ����Ŵ�������


	this->scheduleUpdate();
}

PeaShooter::~PeaShooter()
{
}



void PeaShooter::MyInit()
{
	_plantsType = _PlantsTypePeaShooter;

	_baseAttackTime = 1.4;//����ֲ��Ĺ������
	_mAttackTime = 1.4;//��ʼ����ʱ��Ϊ0

	_plantsMaxBlood = 300;
	_plantsCurrentBlood = _plantsMaxBlood;


	_plantsSunCost = 100;

	_plantsDamage = 20;

	_plantsRecoverTime = 7.5;

}

void PeaShooter::initAnimateOfWait()
{
	if (PeaShooter::addTheWaitAnimateFlag == false)//��ֲ��Ĵ���������ӵ�֡���浱��
	{
		PeaShooter::addTheWaitAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/Peashooter.plist");
	}
	int num = 13;
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= 13; i++)
	{
		char name[40];
		sprintf(name, "Peashooter-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_plantsAnimateOfWait = Animate::create(animation);
}

void PeaShooter::update(float delta)
{
	_mAttackTime += delta;//��ʱ
}


