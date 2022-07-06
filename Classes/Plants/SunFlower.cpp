#include "SunFlower.h"

bool SunFlower::addTheWaitAnimateFlag = false;//初始化为false

SunFlower::SunFlower()
{
	this->MyInit();
	this->initAnimateOfWait();

	_plantsSprite = Sprite::create();

	_plantsSprite->runAction(RepeatForever::create(_plantsAnimateOfWait));

	this->scheduleUpdate();
}

SunFlower::~SunFlower()
{
}

void SunFlower::MyInit()
{
	_plantsMaxBlood = 300;
	_plantsCurrentBlood = _plantsMaxBlood;
	_plantsType = _PlantsTypeSunFlower;
	_plantsDamage = 0;
	_plantsSunCost = 25;


	_baseAttackTime = 20.5;
	_mAttackTime = 0.0;
	_PlantsIsDead = false;

	_plantsRecoverTime = 7.5;
}

void SunFlower::initAnimateOfWait()
{
	if (addTheWaitAnimateFlag == false)//将植物的待机动画添加到帧缓存当中
	{
		addTheWaitAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Plants/SunFlower.plist");
	}
	int num = 18;
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "SunFlower-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_plantsAnimateOfWait = Animate::create(animation);
}

void SunFlower::update(float delta)
{
	_mAttackTime += delta;//计时
}
