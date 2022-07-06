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

extern vector<Zombies*> ZombiesGroup;//用于保存已经创建的僵尸

extern vector<Plants*> PlantsGroup;//用于保存已经创建的植物对象

extern vector<Ammo*> AmmoGroup;//用于保存已经创建的子弹对象

extern vector<BaseCard*> CardGroup;//用于保存已经创建的卡片对象
