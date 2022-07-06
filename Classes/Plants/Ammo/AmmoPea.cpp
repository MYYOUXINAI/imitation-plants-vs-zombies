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

	_MyAmmoType = _AmmoTypePea;//类型为豌豆
	this->scheduleUpdate();//开启调度器
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

	//关闭调度器
	this->unscheduleUpdate();
}

void AmmoPea::update(float delta)
{
	if (_AmmoDie == false)//当弹药没有破碎的时候，让弹药按照一定速度前进
	{
		auto MyVec = this->_AmmoPicSprite->getPosition();
		auto DeltaVec = Vec2(5, 0);
		this->_AmmoPicSprite->setPosition(MyVec + DeltaVec);
	}
}

void AmmoPea::initPicAnimate()
{
	if (addThePicFlag == false)//当帧缓存当中不存在该动画
	{
		addThePicFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/Pea.plist");
	}
	int num = 1;//帧数
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
	if (addThePicDisppearFlag == false)//当帧缓存当中不存在该动画
	{
		addThePicDisppearFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/PeaBulletHit.plist");
	}
	int num = 1;//帧数
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

