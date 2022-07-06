#pragma once
#include "Data/Data.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace ui;
using namespace std;

//Ϊ�˷��㣬����Ҳ���ڿ��ƽ�ʬ����ֲ��
class PlantsAttack :public Node
{
public:
	PlantsAttack();
	~PlantsAttack();


	virtual bool init();//���ڳ�ʼ��
	virtual void setParentScene(Scene *_scene);//���ڰ󶨳�����addChild

	Zombies* getTheFirstInRow(int _row);//��ȡ�ڵ�row�еĵ�һ����ʬ
	Zombies* getTheFirstInRow(int _row,float _x);//��ȡ�ڵ�row�У�λ��_x�ұߵĵ�һ����ʬ
	virtual void update(float delta);
	void shootPea(Plants* _myPlant);//�㶹���ַ���һ���㶹

	Plants* getTheFirstPlantsInRow(int _row, float _x);//��ȡ�ڵ�row�У�λ��_x��ߵĵ�һ��ֲ��

	virtual void CreateAZombies(Vec2 _ZombiesPosition,int _row);//��ĳ��λ�ô���һ����ʬ

	virtual void CreateAPlants(int _row, int _col, PlantsType _type);//��ĳ��ĳ�д���һ��ĳ�����͵�ֲ��

	virtual bool JudgeRowColCanGrowPlants(int _row, int _col);//�����ж���row��col���Ƿ������ֲֲ��

	virtual bool ChangePositionToVec2(Vec2 _myPosition,int &_row,int &_col);//��λ��ת��Ϊ��ͼ����������
	//���ת���ɹ�����ô����true�����򷵻�false

	virtual void AiCreateZombies();//����ʵ��������ɹؿ��еĽ�ʬ

	virtual void CreateSun();//ÿ��һ��ʱ����������������

	double firstTime;//�ֱ����ڼ�¼��n����ʬ�ĳ���ʱ��
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

	double MyTime;//���ڼ�ʱ������ָ��ʱ�䣬���ɶ�Ӧ���εĽ�ʬ

	double MyTimeOfCreateSun;//���ڼ�ʱ���ﵽָ��ʱ�䣬����һ������
	double CreateSunTime;//���������ʱ����

	bool judgeTheGameIsOver;//�ж���Ϸ�Ƿ����
	bool judgeTheGameIsSuccess;//�ж���Ϸ�Ƿ���ʤ��

	Scene* _ParentScene;//�����ڵ�
};

