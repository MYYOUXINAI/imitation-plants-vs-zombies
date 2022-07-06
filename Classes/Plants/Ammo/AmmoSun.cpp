#include "AmmoSun.h"

bool AmmoSun::addThePicFlag = false;//��ʼ��Ϊfalse

AmmoSun::AmmoSun()
{
	this->initPicAnimate();

	_AmmoPicSprite = Sprite::create();
	_AmmoPicDisappearSprite = Sprite::create();

	_AmmoPicSprite->runAction(RepeatForever::create(_AnimateOfPic));

	_MyAmmoType = _AmmoTypePea;//����Ϊ�㶹

	_AmmoMDisappearTime = 0.0;
	_AmmoDisappearSpeed = 23.5;

	_AmmoDie = false;
	this->scheduleUpdate();//����������
}

AmmoSun::~AmmoSun()
{
}

void AmmoSun::RunAmmoCreateAnimate()
{
	auto seq = Sequence::createWithTwoActions(MoveBy::create(0.3, Vec2(0, 50)), MoveBy::create(0.5, Vec2(-60/2, -120/2)));
	this->_AmmoPicSprite->runAction(seq);
}

void AmmoSun::RunAmmoDisappearAnimate()
{
	this->_AmmoPicSprite->runAction(MoveTo::create(2.0, Vec2(80, 750)));
	auto seq = Sequence::createWithTwoActions(DelayTime::create(2.2f), RemoveSelf::create());
	this->_AmmoPicSprite->runAction(seq);
	_AmmoDie = true;
	//�رյ�����
	this->unscheduleUpdate();
}

void AmmoSun::RunAmmoBreakAnimate()
{
	auto seq = Sequence::createWithTwoActions(Blink::create(2.0, 5), RemoveSelf::create());
	this->_AmmoDie = true;
	//�رյ�����
	this->unscheduleUpdate();
}

void AmmoSun::update(float delta)
{
	_AmmoMDisappearTime += delta;
}

void AmmoSun::initPicAnimate()
{
	if (addThePicFlag == false)//��֡���浱�в����ڸö���
	{
		addThePicFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/Sun.plist");
	}
	int num = 22;//֡��
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "Sun-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_AnimateOfPic = Animate::create(animation);
}
