#include "Zombies.h"

Zombies::Zombies()
{
	isDead = false;
}

Zombies::~Zombies()
{
}

void Zombies::myInit()
{
}

void Zombies::initWalkAnimate()
{
}


bool Zombies::judgeIsWalk()
{
	return this->isWalk;
}

bool Zombies::judgeIsEat()
{
	return isEat;
}

void Zombies::initEatAnimate()
{
}

void Zombies::initHeadDownAnimate()
{
}

void Zombies::initDeadWalkAnimate()
{
}

void Zombies::initDeadEatAnimate()
{
}

void Zombies::initFellAnimate()
{
}

void Zombies::initWaitAnimate()
{
}

bool Zombies::RunEatAnimate()//播放僵尸的啃食动画
{
	this->initEatAnimate();
	/*if (_zombiesSprite == nullptr ||  _zombiesAnimateOfEat == nullptr)
	{
		return false;
	}*/
	_zombiesSprite->stopAllActions();
	_zombiesSprite->runAction(RepeatForever::create(_zombiesAnimateOfEat));
	return true;
}

bool Zombies::RunDieAnimate()//播放僵尸的死亡动画
{
	this->initHeadDownAnimate();
	this->initDeadWalkAnimate();
	this->initFellAnimate();
	if (_zombiesSprite == nullptr || _zombiesAnimateOfHeadDown == nullptr)
	{
		return false;
	}
	//首先绑定僵尸头掉落动画到僵尸的头部精灵,然后播放头掉落动画，掉落完消失
	auto myVec = _zombiesSprite->getPosition();
	Vec2 offset = Vec2(70, -10);
	_zombiesHeadSprite->setPosition(myVec + offset);
	auto _remove = RemoveSelf::create();
	_zombiesHeadSprite->stopAllActions();
	_zombiesHeadSprite->runAction(Repeat::create(_zombiesAnimateOfHeadDown, 1));
	auto seq1 = Sequence::createWithTwoActions(DelayTime::create(2.0f), _remove);
	_zombiesHeadSprite->runAction(seq1);
	//然后播放僵尸身体僵直动画，然后倒地
	Sequence* seq2;
	if (/*isWalk*/true)//播放一次无头走路动画，然后倒地
	{
		if (_zombiesAnimateOfDeadWalk == nullptr || _zombiesAnimateOfFell == nullptr)
		{
			return false;
		}
		_zombiesSprite->stopAllActions();
		seq2 = Sequence::createWithTwoActions(_zombiesAnimateOfDeadWalk, _zombiesAnimateOfFell);
		auto seq4 = Sequence::createWithTwoActions(DelayTime::create(2.8f), _remove);
		_zombiesSprite->runAction(seq4);
	}
	if (/*isEat*/false)//播放一次无头啃食动画，然后倒地
	{
		if (_zombiesAnimateOfDeadEat == nullptr || _zombiesAnimateOfFell == nullptr)
		{
			return false;
		}
		seq2 = Sequence::createWithTwoActions(_zombiesAnimateOfDeadEat, _zombiesAnimateOfFell);
		auto seq4 = Sequence::createWithTwoActions(DelayTime::create(2.1f), _remove);
		_zombiesSprite->runAction(seq4);
	}
	_zombiesSprite->runAction(seq2);
	isDead = true;
	return true;
}

bool Zombies::RunWalkAnimate()//播放僵尸的行走动画
{
	this->initWalkAnimate();
	if (_zombiesSprite == nullptr || _zombiesAnimateOfWalk == nullptr)
	{
		return false;
	}
	_zombiesSprite->stopAllActions();
	_zombiesSprite->runAction(RepeatForever::create(_zombiesAnimateOfWalk));
	return true;
}

bool Zombies::RunShineAnimate()
{
	auto _tempBlink = Blink::create(0.01f, 1);
	this->_zombiesSprite->runAction(_tempBlink);
	return true;
}

bool Zombies::RunWaitAnimate()
{
	if (_zombiesSprite == nullptr || _zombiesAnimateOfWait == nullptr)
	{
		return false;
	}
	_zombiesSprite->stopAllActions();
	_zombiesSprite->runAction(RepeatForever::create(_zombiesAnimateOfWait));
	return true;
}

bool Zombies::ChangeStateToWait()
{
	if (isDead == true)	return false;//僵尸已经死亡，返回false

	_zombiesMyState = _ZombiesStateWait;
	isWalk = false;
	isEat = false;
	isDead = false;
	isWait = true;

	//让僵尸播放等待动画
	this->RunDieAnimate();
	return true;
}

bool Zombies::ChangeStateToWalk()
{
	if (isDead == true)	return false;//僵尸已经死亡，返回false

	_zombiesMyState = _ZombiesStateWalk;
	isWalk = true;
	isEat = false;
	isDead = false;
	isWait = false;

	//让僵尸播放行走动画
	this->RunWalkAnimate();
	return true;
}

bool Zombies::ChangeStateToEat()
{
	if (isDead == true)	return false;//僵尸已经死亡，返回false

	_zombiesMyState = _ZombiesStateEat;
	isWalk = false;
	isEat = true;
	isDead = false;
	isWait = false;

	//让僵尸播放攻击动画
	this->RunEatAnimate();
	return true;
}

bool Zombies::ChangeStateToDie()
{
	_zombiesMyState = _ZombiesStateDie;
	isWalk = false;
	isEat = false;
	isDead = true;
	isWait = false;

	//让僵尸播放死亡动画
	this->RunDieAnimate();
	
	return true;
}

void Zombies::CallItWhenHurt(int _hurtValue)
{
	_zombiescurrentBlood -= _hurtValue;
	if(_zombiescurrentBlood>0)	RunShineAnimate();//受击闪烁一次
	if (_zombiescurrentBlood <= 0)//说明僵尸已经死亡
	{
		this->ChangeStateToDie();
	}
}

void Zombies::setRowCol(int _row, int _col)
{
	_zombiesRow = _row;
	_zombiesCol = _col;
}
