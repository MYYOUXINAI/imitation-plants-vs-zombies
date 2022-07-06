#include "PeaShooter.h"

bool PeaShooter::addTheWaitAnimateFlag = false;//初始化为否

PeaShooter::PeaShooter()
{
	this->MyInit();

	_plantsSprite = Sprite::create();

	this->initAnimateOfWait();

	_plantsSprite->runAction(RepeatForever::create(_plantsAnimateOfWait));//初始化时，让植物重复播放待机动画


	this->scheduleUpdate();
}

PeaShooter::~PeaShooter()
{
}



void PeaShooter::MyInit()
{
	_plantsType = _PlantsTypePeaShooter;

	_baseAttackTime = 1.4;//定义植物的攻击间隔
	_mAttackTime = 1.4;//初始化计时器为0

	_plantsMaxBlood = 300;
	_plantsCurrentBlood = _plantsMaxBlood;


	_plantsSunCost = 100;

	_plantsDamage = 20;

	_plantsRecoverTime = 7.5;

}

void PeaShooter::initAnimateOfWait()
{
	if (PeaShooter::addTheWaitAnimateFlag == false)//将植物的待机动画添加到帧缓存当中
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
	_mAttackTime += delta;//计时
}


