#pragma once
#include <iostream>
#include <vector>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;


//������ʾ������ֵ��label��tag
#define SunLabelTag 19
//������ʾ������ֵ�ı���tag
#define SunNumItemTag 20

//������������ͼƬ��z
#define SunNumPicZ 20

//���忨Ƭ��z
#define CardZ 20

//���屳��ͼƬ��z
#define BackGroundZ 10

//����ֲ���Z
#define PlantsZ 11

//����ֲ�ﵯҩ��Z
#define AmmoZ 22

//���彩ʬ��Z
#define ZombiesZ 15

//����ֲ����Ӱ��tag
#define MousePlantsSpriteTag 111

extern int _GroupSun;//���ڼ�¼�ؿ��е�����ֵ

extern int _GroupCurrentSun;//���ڼ�¼�ؿ��еĵ�ǰ����ֵ

extern vector<vector<Vec2>>positionOfPlants;//���ڼ�¼������ά���굱�У�ֲ���λ�ã�5*9

extern vector<vector<bool>>ArrOfPlantsVisits;//���ڼ�¼�������굱�У��Ƿ����ֲ��

