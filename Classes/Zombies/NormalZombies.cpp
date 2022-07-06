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
	//��������
	_zombiesSprite = Sprite::create();
	_zombiesHeadSprite = Sprite::create();

	//��ʼ����ʬ�ĸ��ֶ���
	this->initWalkAnimate();
	this->initEatAnimate();
	this->initHeadDownAnimate();
	this->initDeadWalkAnimate();
	this->initDeadEatAnimate();
	this->initFellAnimate();
	this->initWaitAnimate();

	//��ʼ����ʬ�Ļ��������Լ�״̬
	this->myInit();

	//�ڸձ������Ľ׶Σ����ظ����Ž�ʬ�Ĵ�������
	_zombiesSprite->runAction(RepeatForever::create(_zombiesAnimateOfWait));

	//����������
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
	_zombiesCurrentSpeed = -0.3;//Ĭ���������ߣ�ÿһ֡�����ƶ�0.3�ľ���

	_zombiesDamage = 35;

	isWalk = false;
	isEat = false;
	isDead = false;
	isWait = true;//Ĭ�Ͻ�������Ϊ�ȴ�״̬

	_baseAttackTime = 0.4;//���彩ʬ�Ĺ������
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
		//������ƽ�ʬ������
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
		//����ʬ������ͣ�õ�����
		this->unscheduleUpdate();
		break;
	}
	default:
	{
		break;
	}
	}
}

void NormalZombies::initEatAnimate()//���ڴ�����ʬ��������
{
	if (addTheEatAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheEatAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/zombiesAttack.plist");
	}
	int num = 21;//֡��
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

void NormalZombies::initWalkAnimate()//��ʼ����ʬ���߶���
{
	if (NormalZombies::addTheWalkAnimateFlag == false)//�ڻ��浱�в��������߶���
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

void NormalZombies::initHeadDownAnimate()//��ʼ����ʬͷ�����䶯��
{
	if (addTheHeadDownAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheHeadDownAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombiesHead.plist");
	}
	int num = 12;//֡��
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

void NormalZombies::initDeadWalkAnimate()//��ʼ�������߹����������Ķ���
{
	if (addTheDeadWalkAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheDeadWalkAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombiesDeadWalk.plist");
	}
	int num = 18;//֡��
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

void NormalZombies::initDeadEatAnimate()//��ʼ����ʬ����ʱ����������
{
	if (addTheDeadEatAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheDeadEatAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieLostHeadAttack.plist");
	}
	int num = 11;//֡��
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
	if (addTheFellAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheFellAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieDie.plist");
	}
	int num = 10;//֡��
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
	if (addTheWaitAnimateFlag == false)//��֡���浱�в����ڸö���
	{
		addTheWaitAnimateFlag = true;
		auto spritecache = SpriteFrameCache::getInstance();
		spritecache->addSpriteFramesWithFile("Zombies/ZombieWait.plist");
	}
	int num = 22;//֡��
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
