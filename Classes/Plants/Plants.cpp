#include "Plants.h"

Plants::Plants()
{
	_PlantsIsDead = false;
}

Plants::~Plants()
{
}

bool Plants::plantsIsLive()
{
	return this->_plantsCurrentBlood > 0;
}

void Plants::setPlantsRowCol(int _row, int _col)
{
	_plantsRow = _row;
	_plantsCol = _col;
}




void Plants::initAnimateOfWait()
{
}

void Plants::CallItWhenHurt(int _value)
{
	_plantsCurrentBlood -= _value;
	//log("the blood: %d", _plantsCurrentBlood);
	if (_plantsCurrentBlood > 0)	RunShineAnimate();//�ܻ���˸һ��
	if (_plantsCurrentBlood <= 0)
	{
		this->CallItWhenDie();
		//�����ͷ�ֲ����ռ�ݵĿ�λ
		ArrOfPlantsVisits[this->_plantsRow][this->_plantsCol] = false;
	}
}

void Plants::CallItWhenDie()
{
	this->_PlantsIsDead = true;
	auto _remove = RemoveSelf::create();
	_plantsSprite->runAction(_remove);
	//ͣ�õ�����
	this->unscheduleUpdate();
}

void Plants::RunShineAnimate()
{
	auto _tempBlink = Blink::create(0.01f, 1);
	this->_plantsSprite->runAction(_tempBlink);
}
