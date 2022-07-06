#include "AmmoPea.h"

bool AmmoPea::addThePicFlag = false;
bool AmmoPea::addThePicDisppearFlag = false;


AmmoPea::AmmoPea()
{
	this->initPicAnimate();
	this->initPicDisappearAnimate();

	_AmmoPicSprite = Sprite::create();
	_AmmoPicDisappearSprite = Sprite::create("Plants/PeaBulletHit-1.png");
	_AmmoPicDisappearSprite->setVisible(false);

	_AmmoPicSprite->runAction(RepeatForever::create(_AnimateOfPic));

	_MyAmmoType = _AmmoTypePea;//����Ϊ�㶹
	this->scheduleUpdate();//����������
}

AmmoPea::~AmmoPea()
{
}

void AmmoPea::RunAmmoBreakAnimate()
{
	this->AmmoSetPosition(this->_AmmoPicSprite->getPosition());
	this->_AmmoDie = true;
	_AmmoPicSprite->stopAllActions();
	//_AmmoPicSprite->runAction(Repeat::create(_AnimateOfPicDisappear,1));
	auto _remove = RemoveSelf::create();
	_AmmoPicSprite->runAction(_remove);
	//_AmmoPicDisappearSprite->runAction(RepeatForever::create(_AnimateOfPicDisappear));
	_AmmoPicDisappearSprite->setVisible(true);
	auto seq = Sequence::createWithTwoActions(DelayTime::create(0.15f), _remove);
	_AmmoPicDisappearSprite->runAction(seq);

	//�رյ�����
	this->unscheduleUpdate();
}

void AmmoPea::update(float delta)
{
	if (_AmmoDie == false)//����ҩû�������ʱ���õ�ҩ����һ���ٶ�ǰ��
	{
		auto MyVec = this->_AmmoPicSprite->getPosition();
		auto DeltaVec = Vec2(5, 0);
		this->_AmmoPicSprite->setPosition(MyVec + DeltaVec);
	}
}

void AmmoPea::initPicAnimate()
{
	if (addThePicFlag == false)//��֡���浱�в����ڸö���
	{
		addThePicFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/Pea.plist");
	}
	int num = 1;//֡��
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "Pea-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_AnimateOfPic = Animate::create(animation);
}

void AmmoPea::initPicDisappearAnimate()
{
	if (addThePicDisppearFlag == false)//��֡���浱�в����ڸö���
	{
		addThePicDisppearFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/PeaBulletHit.plist");
	}
	int num = 1;//֡��
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "PeaBulletHit-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_AnimateOfPicDisappear = Animate::create(animation);
}

