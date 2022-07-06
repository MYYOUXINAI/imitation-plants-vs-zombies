#pragma once
#include <iostream>
#include <vector>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;


//定义显示阳光数值的label的tag
#define SunLabelTag 19
//定义显示阳光数值文本的tag
#define SunNumItemTag 20

//定义阳光数量图片的z
#define SunNumPicZ 20

//定义卡片的z
#define CardZ 20

//定义背景图片的z
#define BackGroundZ 10

//定义植物的Z
#define PlantsZ 11

//定义植物弹药的Z
#define AmmoZ 22

//定义僵尸的Z
#define ZombiesZ 15

//设置植物虚影的tag
#define MousePlantsSpriteTag 111

extern int _GroupSun;//用于记录关卡中的阳光值

extern int _GroupCurrentSun;//用于记录关卡中的当前阳光值

extern vector<vector<Vec2>>positionOfPlants;//用于记录各个二维坐标当中，植物的位置，5*9

extern vector<vector<bool>>ArrOfPlantsVisits;//用于记录各个坐标当中，是否存在植物

