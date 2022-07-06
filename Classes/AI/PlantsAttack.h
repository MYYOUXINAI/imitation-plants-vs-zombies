#pragma once
#include "Data/Data.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace ui;
using namespace std;

//为了方便，这里也用于控制僵尸攻击植物
class PlantsAttack :public Node
{
public:
	PlantsAttack();
	~PlantsAttack();


	virtual bool init();//用于初始化
	virtual void setParentScene(Scene *_scene);//用于绑定场景，addChild

	Zombies* getTheFirstInRow(int _row);//获取在第row行的第一个僵尸
	Zombies* getTheFirstInRow(int _row,float _x);//获取在第row行，位于_x右边的第一个僵尸
	virtual void update(float delta);
	void shootPea(Plants* _myPlant);//豌豆射手发射一个豌豆

	Plants* getTheFirstPlantsInRow(int _row, float _x);//获取在第row行，位于_x左边的第一个植物

	virtual void CreateAZombies(Vec2 _ZombiesPosition,int _row);//在某个位置创建一个僵尸

	virtual void CreateAPlants(int _row, int _col, PlantsType _type);//再某行某列创建一个某种类型的植物

	virtual bool JudgeRowColCanGrowPlants(int _row, int _col);//用于判断在row行col列是否可以种植植物

	virtual bool ChangePositionToVec2(Vec2 _myPosition,int &_row,int &_col);//将位置转换为地图的行列坐标
	//如果转换成功，那么返回true，否则返回false

	virtual void AiCreateZombies();//这里实现随机生成关卡中的僵尸

	virtual void CreateSun();//每隔一段时间从天空中生成阳光

	double firstTime;//分别用于记录第n波僵尸的出现时间
	double SecondTime;
	double ThirdTime;
	double ForthTime;
	double FithTime;
	double SixTime;
	double SeventhTime;
	double EigthTime;
	bool TimeFlag1;
	bool TimeFlag2;
	bool TimeFlag3;
	bool TimeFlag4;
	bool TimeFlag5;
	bool TimeFlag6;
	bool TimeFlag7;
	bool TimeFlag8;

	double MyTime;//用于计时，到达指定时间，生成对应波次的僵尸

	double MyTimeOfCreateSun;//用于计时，达到指定时间，生成一个阳光
	double CreateSunTime;//生成阳光的时间间隔

	bool judgeTheGameIsOver;//判断游戏是否结束
	bool judgeTheGameIsSuccess;//判断游戏是否获得胜利

	Scene* _ParentScene;//场景节点
};

