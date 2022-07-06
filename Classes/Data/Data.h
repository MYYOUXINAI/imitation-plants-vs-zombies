#pragma once
#include "Zombies/Zombies.h"
#include "Zombies/NormalZombies.h"

#include "Plants/Plants.h"
#include "Plants/SunFlower.h"
#include "Plants/PeaShooter.h"


#include "Plants/Ammo/Ammo.h"
#include "Plants/Ammo/AmmoPea.h"
#include "Plants/Ammo/AmmoSun.h"

#include "Data/BaseData.h"

#include "Card/BaseCard.h"
#include "Card/PeaShooterCard.h"
#include "Card/SunFlowerCard.h"

#include <vector>

extern vector<Zombies*> ZombiesGroup;//���ڱ����Ѿ������Ľ�ʬ

extern vector<Plants*> PlantsGroup;//���ڱ����Ѿ�������ֲ�����

extern vector<Ammo*> AmmoGroup;//���ڱ����Ѿ��������ӵ�����

extern vector<BaseCard*> CardGroup;//���ڱ����Ѿ������Ŀ�Ƭ����
