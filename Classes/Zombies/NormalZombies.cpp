#include "NormalZombies.h"


bool NormalZombies::addTheEatAnimateFlag = false;
bool NormalZombies::addTheWalkAnimateFlag = false;
bool NormalZombies::addTheHeadDownAnimateFlag = false;
bool NormalZombies::addTheDeadWalkAnimateFlag = false;
bool NormalZombies::addTheDeadEatAnimateFlag = false;
bool NormalZombies::addTheFellAnimateFlag = false;
bool NormalZombies::addTheWaitAnimateFlag = false;

NormalZombies::NormalZombies()
{
	//创建精灵
	_zombiesSprite = Sprite::create();
	_zombiesHeadSprite = Sprite::create();

	//初始化僵尸的各种动画
	this->initWalkAnimate();
	this->initEatAnimate();
	this->initHeadDownAnimate();
	this->initDeadWalkAnimate();
	this->initDeadEatAnimate();
	this->initFellAnimate();
	this->initWaitAnimate();

	//初始化僵尸的基础属性以及状态
	this->myInit();

	//在刚被创建的阶段，将重复播放僵尸的待机动画
	_zombiesSprite->runAction(RepeatForever::create(_zombiesAnimateOfWait));

	//开启调度器
	this->scheduleUpdate();
}

NormalZombies::~NormalZombies()
{
}



void NormalZombies::myInit()
{
	_zombiesmaxBlood = 270;
	_zombiescurrentBlood = _zombiesmaxBlood;

	_zombiesType = _ZombiesTypeZombies;
	_zombiesCurrentSpeed = -0.3;//默认是向左走，每一帧都是移动0.3的距离

	_zombiesDamage = 35;

	isWalk = false;
	isEat = false;
	isDead = false;
	isWait = true;//默认将其设置为等待状态

	_baseAttackTime = 0.4;//定义僵尸的攻击间隔
	_mAttackTime = _baseAttackTime;

	_zombiesMyState = _ZombiesStateWait;
}

void NormalZombies::update(float delta)
{
	_mAttackTime += delta;
	switch (_zombiesMyState)
	{
	case _ZombiesStateWait:
	{
		break;
	}
	case _ZombiesStateWalk:
	{
		//这里控制僵尸向左走
		auto dirc = this->_zombiesSprite->getPosition();
		Vec2 tempdelta = Vec2(this->_zombiesCurrentSpeed, 0);
		this->_zombiesSprite->setPosition(dirc + tempdelta);
		break;
	}
	case _ZombiesStateEat:
	{
		break;
	}
	case _ZombiesStateDie:
	{
		//当僵尸死亡后，停用调度器
		this->unscheduleUpdate();
		break;
	}
	default:
	{
		break;
	}
	}
}

void NormalZombies::initEatAnimate()//用于创建僵尸攻击动画
{
	if (addTheEatAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheEatAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/zombiesAttack.plist");
	}
	int num = 21;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieAttack-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfEat = Animate::create(animation);
}

void NormalZombies::initWalkAnimate()//初始化僵尸行走动画
{
	if (NormalZombies::addTheWalkAnimateFlag == false)//在缓存当中不存在行走动画
	{
		NormalZombies::addTheWalkAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/Zombies.plist");
	}
	int num = 22;
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "Zombie-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfWalk = Animate::create(animation);
}

void NormalZombies::initHeadDownAnimate()//初始化僵尸头部掉落动画
{
	if (addTheHeadDownAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheHeadDownAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombiesHead.plist");
	}
	int num = 12;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieHead-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfHeadDown = Animate::create(animation);
}

void NormalZombies::initDeadWalkAnimate()//初始化在行走过程中死亡的动画
{
	if (addTheDeadWalkAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheDeadWalkAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombiesDeadWalk.plist");
	}
	int num = 18;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieLostHead-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfDeadWalk = Animate::create(animation);
}

void NormalZombies::initDeadEatAnimate()//初始化僵尸攻击时的死亡动画
{
	if (addTheDeadEatAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheDeadEatAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieLostHeadAttack.plist");
	}
	int num = 11;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieLostHeadAttack-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfDeadEat = Animate::create(animation);
}

void NormalZombies::initFellAnimate()
{
	if (addTheFellAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheFellAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieDie.plist");
	}
	int num = 10;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieDie-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfFell = Animate::create(animation);
}

void NormalZombies::initWaitAnimate()
{
	if (addTheWaitAnimateFlag == false)//当帧缓存当中不存在该动画
	{
		addTheWaitAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieWait.plist");
	}
	int num = 22;//帧数
	auto animation = Animation::create();
	auto spritecache = SpriteFrameCache::getInstance();
	for (int i = 1; i <= num; i++)
	{
		char name[40];
		sprintf(name, "ZombieWait-%d.png", i);
		auto newspriteFrame = spritecache->getSpriteFrameByName(name);
		animation->addSpriteFrame(newspriteFrame);
	}
	animation->setDelayPerUnit(0.1f);
	_zombiesAnimateOfWait = Animate::create(animation);
}
