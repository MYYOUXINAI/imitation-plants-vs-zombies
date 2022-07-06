#include "PlantsAttack.h"

PlantsAttack::PlantsAttack()
{
	this->init();
}

PlantsAttack::~PlantsAttack()
{
}

bool PlantsAttack::init()
{
	MyTimeOfCreateSun = 0.0;
	CreateSunTime = 10.5;

	firstTime = 13.0;
	SecondTime=38.0;
	ThirdTime=56.0;
	ForthTime=76.0;
	FithTime=90.0;
	SixTime=120.0;
	SeventhTime=150.0;
	EigthTime=180.0;

	TimeFlag1 = false;
	TimeFlag2 = false;
	TimeFlag3 = false;
	TimeFlag4 = false;
	TimeFlag5 = false;
	TimeFlag6 = false;
	TimeFlag7 = false;
	TimeFlag8 = false;

	MyTime = 0.0;

	judgeTheGameIsOver = false;
	judgeTheGameIsSuccess = true;

	this->scheduleUpdate();
	return true;
}

void PlantsAttack::setParentScene(Scene *_scene)
{
	_ParentScene = _scene;
}

Zombies* PlantsAttack::getTheFirstInRow(int _row)//返回在第row行的第一个僵尸
{
	double cmin = -1.0;
	Zombies* ret = nullptr;
	for (auto &x : ZombiesGroup)
	{
		if (x->_zombiesRow == _row)
		{
			if (cmin == -1.0 || cmin >= x->_zombiesSprite->getPositionX())
			{
				cmin = x->_zombiesSprite->getPositionX();
				ret = x;
			}
		}
	}

	return ret;
}

Zombies * PlantsAttack::getTheFirstInRow(int _row, float _x)
{
	_x -= 15;
	double cmin = -1.0;
	Zombies* ret = nullptr;
	for (auto &x : ZombiesGroup)
	{
		if (x->isDead == true)	continue;
		if (x->_zombiesRow == _row)
		{
			if ((x->_zombiesSprite->getPositionX() >= _x) && (cmin == -1.0 || cmin >= x->_zombiesSprite->getPositionX()))
			{
				cmin = x->_zombiesSprite->getPositionX();
				ret = x;
			}
		}
	}

	return ret;
}

void PlantsAttack::update(float delta)
{
	MyTime += delta;
	MyTimeOfCreateSun += delta;

	Vec2 _zombiesAppearPosition = Vec2(100, 30);
	if (MyTime >= firstTime && MyTime < SecondTime && TimeFlag1 == false)
	{
		TimeFlag1 = true;
		for (int i = 0; i < 2; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}
	}
	else if (MyTime >= SecondTime && MyTime < ThirdTime && TimeFlag2 == false)
	{
		TimeFlag2 = true;
		for (int i = 0; i < 2; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}
	}
	else if (MyTime >= ThirdTime && MyTime < ForthTime && TimeFlag3 == false)
	{
		TimeFlag3 = true;
		for (int i = 0; i < 4; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}

	}
	else if (MyTime >= ForthTime && MyTime < FithTime && TimeFlag4 == false)
	{
		TimeFlag4 = true;
		for (int i = 0; i < 6; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}

	}
	else if (MyTime >= FithTime && MyTime < SixTime && TimeFlag5 == false)
	{
		TimeFlag5 = true;
		for (int i = 0; i < 6; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}

	}
	else if (MyTime >= SixTime && MyTime < SeventhTime && TimeFlag6 == false)
	{
		TimeFlag6 = true;
		for (int i = 0; i < 8; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}

	}
	else if (MyTime >= SeventhTime && MyTime < EigthTime && TimeFlag7 == false)
	{
		TimeFlag7 = true;
		for (int i = 0; i < 8; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}

	}
	else if (MyTime >= EigthTime && TimeFlag8 == false)
	{
		TimeFlag8 = true;
		for (int i = 0; i < 10; i++)
		{
			int _row = rand() % 5;
			this->CreateAZombies(positionOfPlants[_row][8] + _zombiesAppearPosition, _row);
		}
		auto _tempSprite = Sprite::create("FinalWave.png");
		_tempSprite->setPosition(Director::getInstance()->getVisibleSize() / 2);
		_ParentScene->addChild(_tempSprite,999);
		auto seq = Sequence::createWithTwoActions(DelayTime::create(1.5), RemoveSelf::create());
		_tempSprite->runAction(seq);
	}
	else
	{

	}

	for (auto &x : PlantsGroup)//遍历植物，执行植物的相应动作
	{
		if (x->_PlantsIsDead == true)	continue;
		if (x->_plantsType == _PlantsTypePeaShooter)//如果是豌豆射手
		{
			Zombies* _tempZombies = getTheFirstInRow(x->_plantsRow, x->_plantsSprite->getPositionX());//获取攻击目标
			if (_tempZombies != nullptr)//如果有攻击目标
			{
				if (x->_mAttackTime >= x->_baseAttackTime)//说明植物的休息时间大于攻击间隔
				{
					x->_mAttackTime = 0.0;
					//这里调用豌豆射手的攻击函数
					//shootPea
					shootPea(x);
				}
			}
		}
		else if (x->_plantsType == _PlantsTypeSunFlower)//如果是向日葵
		{
			if (x->_mAttackTime >= x->_baseAttackTime)//可以产生阳光
			{
				x->_mAttackTime = 0.0;
				auto tempSun = new AmmoSun;
				_ParentScene->addChild(tempSun, AmmoZ);
				_ParentScene->addChild(tempSun->_AmmoPicSprite, AmmoZ);
				_ParentScene->addChild(tempSun->_AmmoPicDisappearSprite, AmmoZ);
				AmmoGroup.push_back(tempSun);
				tempSun->_AmmoPicSprite->setPosition(x->_plantsSprite->getPosition());
				tempSun->RunAmmoCreateAnimate();
			}
		}
		else
		{

		}
	}

	//遍历豌豆，让豌豆在距离僵尸一定范围时，爆炸
	for (auto &x : AmmoGroup)
	{
		if (x->_AmmoDie == true)	continue;
		if (x->_MyAmmoType == _AmmoTypePea)//如果为豌豆
		{
			Zombies* _tempZombies = getTheFirstInRow(x->_AmmoRow, x->_AmmoPicSprite->getPositionX());
			if (_tempZombies != nullptr)
			{
				float zombiesX = _tempZombies->_zombiesSprite->getPositionX();
				float peaX = x->_AmmoPicSprite->getPositionX();
				if (fabs(peaX - zombiesX) <= 15)
				{
					x->RunAmmoBreakAnimate();//豌豆破碎，并且将豌豆设置为死亡
					_tempZombies->CallItWhenHurt(20);//攻击力为20
				}
			}
		}
		else if (x->_MyAmmoType == _AmmoTypeSun)//如果为阳光
		{
			if (x->_AmmoMDisappearTime >= x->_AmmoDisappearSpeed)//此时，需要让阳光消失
			{
				x->RunAmmoBreakAnimate();
			}
		}
	}

	//遍历僵尸，当僵尸位于植物跟前时，让僵尸执行攻击动作
	for (auto &x : ZombiesGroup)
	{
		if (x->isDead == true)	continue;//对于已经死亡的僵尸，直接忽略
		if (x->_zombiesType == _ZombiesTypeZombies)//如果是普通僵尸
		{
			Plants* _tempPlants = getTheFirstPlantsInRow(x->_zombiesRow, x->_zombiesSprite->getPositionX());
			if (_tempPlants != nullptr)//如果有攻击目标
			{
				if (x->_mAttackTime >= x->_baseAttackTime
					&& fabs(x->_zombiesSprite->getPositionX() - _tempPlants->_plantsSprite->getPositionX()) <= 15)
					//如果僵尸此时可以进行攻击，并且植物处于攻击范围中
				{
					if (x->_zombiesMyState != _ZombiesStateEat)
					{
						x->ChangeStateToEat();
					}
					//此处调用植物受击函数
					_tempPlants->CallItWhenHurt(x->_zombiesDamage);
					x->_mAttackTime = 0.0;
				}
				if (fabs(x->_zombiesSprite->getPositionX() - _tempPlants->_plantsSprite->getPositionX()) >= 15)
				{
					if (x->_zombiesMyState == _ZombiesStateEat)
					{
						x->ChangeStateToWalk();
					}
				}
			}
			else
			{
				if (x->_zombiesMyState == _ZombiesStateEat)
				{
					x->ChangeStateToWalk();
				}
			}
		}
	}


	//这里用于判断游戏是否结束
	int _tempCnt = 0;
	for (auto &x : ZombiesGroup)
	{
		if (x->isDead == true)	continue;
		++_tempCnt;//计算活着的僵尸
		//这里判断是否有僵尸进入了屋子里
		auto _tempPosition = x->_zombiesSprite->getPosition();
		if (_tempPosition.x <= 0)//说明僵尸已经越过了植物的防线
		{
			judgeTheGameIsOver = true;
			judgeTheGameIsSuccess = false;
			break;
		}
	}
	if (_tempCnt == 0 && MyTime > EigthTime)//场地中已经没有僵尸存在
	{
		judgeTheGameIsOver = true;
		judgeTheGameIsSuccess = true;
	}

	//这里用于生成阳光
	if (MyTimeOfCreateSun >= CreateSunTime)
	{
		MyTimeOfCreateSun = 0.0;//置零
		this->CreateSun();
	}
}

void PlantsAttack::shootPea(Plants * _myPlant)
{
	auto OffSet = Vec2(20,23);//位置偏移，让豌豆从豌豆射手口中射出
	auto _tempVec = _myPlant->_plantsSprite->getPosition();
	auto *tempAmmo = new AmmoPea;
	tempAmmo->setAmmoRowCol(_myPlant->_plantsRow);//设置弹药的行
	AmmoGroup.push_back(tempAmmo);
	tempAmmo->AmmoSetPosition(_tempVec + OffSet);
	_ParentScene->addChild(tempAmmo, AmmoZ);
	_ParentScene->addChild(tempAmmo->_AmmoPicSprite, AmmoZ);
	_ParentScene->addChild(tempAmmo->_AmmoPicDisappearSprite, AmmoZ);
	//tempAmmo->RunAmmoBreakAnimate();
}

Plants * PlantsAttack::getTheFirstPlantsInRow(int _row, float _x)
{
	_x += 15;
	double cmin = -1.0;
	Plants* ret = nullptr;
	for (auto &x : PlantsGroup)
	{
		if (x->_PlantsIsDead == true)	continue;//已经死亡的植物，直接跳过
		if (x->_plantsRow == _row)
		{
			if ((x->_plantsSprite->getPositionX() <= _x) && (cmin == -1.0 || cmin <= x->_plantsSprite->getPositionX()))
			{
				cmin = x->_plantsSprite->getPositionX();
				ret = x;
			}
		}
	}

	return ret;
}

void PlantsAttack::CreateAZombies(Vec2 _ZombiesPosition,int _row)
{
	auto _tempZombies = new NormalZombies;
	ZombiesGroup.push_back(_tempZombies);
	_tempZombies->_zombiesSprite->setScale(1.1);
	_tempZombies->_zombiesSprite->setPosition(_ZombiesPosition);
	_tempZombies->setRowCol(_row);
	_ParentScene->addChild(_tempZombies,ZombiesZ);
	_ParentScene->addChild(_tempZombies->_zombiesSprite, ZombiesZ);
	_ParentScene->addChild(_tempZombies->_zombiesHeadSprite, ZombiesZ);
	_tempZombies->ChangeStateToWalk();
}

void PlantsAttack::CreateAPlants(int _row, int _col, PlantsType _type)
{
	//首先将该位置设置为已经有植物种植
	ArrOfPlantsVisits[_row][_col] = true;
	Plants* _tempPlants;
	switch (_type)
	{
	case _PlantsTypeNone:
	{
		break;
	}
	case _PlantsTypePeaShooter://种植豌豆射手
	{
		_tempPlants = new PeaShooter;
		break;
	}
	case _PlantsTypeSunFlower://种植向日葵
	{
		_tempPlants = new SunFlower;
		break;
	}
	default:
	{
		break;
	}
	}

	PlantsGroup.push_back(_tempPlants);
	_tempPlants->_plantsSprite->setPosition(positionOfPlants[_row][_col]);
	_tempPlants->_plantsSprite->setScale(1.2);
	_tempPlants->setPlantsRowCol(_row, _col);
	_ParentScene->addChild(_tempPlants, PlantsZ);
	_ParentScene->addChild(_tempPlants->_plantsSprite, PlantsZ);
	//CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/plant.mp3");
}

bool PlantsAttack::JudgeRowColCanGrowPlants(int _row, int _col)
{
	return ArrOfPlantsVisits[_row][_col];
}

bool PlantsAttack::ChangePositionToVec2(Vec2 _myPosition, int & _row, int & _col)
{
	if((_myPosition.x<47) ||(_myPosition.x>964) ||(_myPosition.y<54)||(_myPosition.y>662))	return false;
	int _width = 125/2;
	int _height = 103/2;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Vec2 _offset = _myPosition - positionOfPlants[i][j];
			if ((fabs(_offset.x) <= _width) && (fabs(_offset.y) <= _height))
			{
				_row = i;
				_col = j;
				return true;
			}
		}
	}
	return false;
}

void PlantsAttack::AiCreateZombies()
{
}

void PlantsAttack::CreateSun()
{
	auto _tempSun = new AmmoSun;
	_ParentScene->addChild(_tempSun, AmmoZ);
	_ParentScene->addChild(_tempSun->_AmmoPicSprite, AmmoZ);
	_ParentScene->addChild(_tempSun->_AmmoPicDisappearSprite, AmmoZ);
	AmmoGroup.push_back(_tempSun);
	int _randX = rand() % 1000 + 200;
	_tempSun->_AmmoPicSprite->setPosition(Vec2(_randX, 900));
	_tempSun->RunAmmoCreateFromSkyAnimate();
}
