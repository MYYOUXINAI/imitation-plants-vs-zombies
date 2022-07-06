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

bool Zombies::RunEatAnimate()//���Ž�ʬ�Ŀ�ʳ����
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

bool Zombies::RunDieAnimate()//���Ž�ʬ����������
{
	this->initHeadDownAnimate();
	this->initDeadWalkAnimate();
	this->initFellAnimate();
	if (_zombiesSprite == nullptr || _zombiesAnimateOfHeadDown == nullptr)
	{
		return false;
	}
	//���Ȱ󶨽�ʬͷ���䶯������ʬ��ͷ������,Ȼ�󲥷�ͷ���䶯������������ʧ
	auto myVec = _zombiesSprite->getPosition();
	Vec2 offset = Vec2(70, -10);
	_zombiesHeadSprite->setPosition(myVec + offset);
	auto _remove = RemoveSelf::create();
	_zombiesHeadSprite->stopAllActions();
	_zombiesHeadSprite->runAction(Repeat::create(_zombiesAnimateOfHeadDown, 1));
	auto seq1 = Sequence::createWithTwoActions(DelayTime::create(2.0f), _remove);
	_zombiesHeadSprite->runAction(seq1);
	//Ȼ�󲥷Ž�ʬ���彩ֱ������Ȼ�󵹵�
	Sequence* seq2;
	if (/*isWalk*/true)//����һ����ͷ��·������Ȼ�󵹵�
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
	if (/*isEat*/false)//����һ����ͷ��ʳ������Ȼ�󵹵�
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

bool Zombies::RunWalkAnimate()//���Ž�ʬ�����߶���
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
	if (isDead == true)	return false;//��ʬ�Ѿ�����������false

	_zombiesMyState = _ZombiesStateWait;
	isWalk = false;
	isEat = false;
	isDead = false;
	isWait = true;

	//�ý�ʬ���ŵȴ�����
	this->RunDieAnimate();
	return true;
}

bool Zombies::ChangeStateToWalk()
{
	if (isDead == true)	return false;//��ʬ�Ѿ�����������false

	_zombiesMyState = _ZombiesStateWalk;
	isWalk = true;
	isEat = false;
	isDead = false;
	isWait = false;

	//�ý�ʬ�������߶���
	this->RunWalkAnimate();
	return true;
}

bool Zombies::ChangeStateToEat()
{
	if (isDead == true)	return false;//��ʬ�Ѿ�����������false

	_zombiesMyState = _ZombiesStateEat;
	isWalk = false;
	isEat = true;
	isDead = false;
	isWait = false;

	//�ý�ʬ���Ź�������
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

	//�ý�ʬ������������
	this->RunDieAnimate();
	
	return true;
}

void Zombies::CallItWhenHurt(int _hurtValue)
{
	_zombiescurrentBlood -= _hurtValue;
	if(_zombiescurrentBlood>0)	RunShineAnimate();//�ܻ���˸һ��
	if (_zombiescurrentBlood <= 0)//˵����ʬ�Ѿ�����
	{
		this->ChangeStateToDie();
	}
}

void Zombies::setRowCol(int _row, int _col)
{
	_zombiesRow = _row;
	_zombiesCol = _col;
}
