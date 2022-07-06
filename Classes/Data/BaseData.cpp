#include "BaseData.h"


int _GroupSun;
int _GroupCurrentSun;

vector<vector<Vec2>>positionOfPlants(5, vector<Vec2>(9));//用于记录各个二维坐标当中，植物的位置，5*9

vector<vector<bool>>ArrOfPlantsVisits;//用于记录各个坐标当中，是否存在植物