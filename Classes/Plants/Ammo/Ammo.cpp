#include "Ammo.h"

Ammo::Ammo()
{
	_AmmoDie = false;
}

Ammo::~Ammo()//
{
}

void Ammo::RunAmmoBreakAnimate()
{
}

void Ammo::RunAmmoCreateAnimate()
{
}

void Ammo::RunAmmoDisappearAnimate()
{
}

void Ammo::RunAmmoCreateFromSkyAnimate()
{
	this->_AmmoPicSprite->runAction(MoveTo::create(3.0, Vec2(rand() % 900 + 50, rand() % 600 + 50)));
}



void Ammo::initPicAnimate()
{
}

void Ammo::initPicDisappearAnimate()
{
}

void Ammo::AmmoSetPosition(Vec2  _ve)
{
	this->_AmmoPicSprite->setPosition(_ve);
	this->_AmmoPicDisappearSprite->setPosition(_ve);
	this->_AmmoPosition = _ve;
}

void Ammo::setAmmoRowCol(int _row)
{
	_AmmoRow = _row;
}


