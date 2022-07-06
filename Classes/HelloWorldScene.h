/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "Scene/GameOverFailedScene.h"
#include "cocos2d.h"
#include "Data/Data.h"
#include "Zombies/NormalZombies.h"
#include "Plants/PeaShooter.h"
#include "Plants/Ammo/AmmoPea.h"
#include "AI/PlantsAttack.h"
#include "Plants/SunFlower.h"
#include "Scene/GameOverSuccessScene.h"

#include "SimpleAudioEngine.h"


class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	void MyInit();//��ʼ��һЩ����

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    

	bool onTouchBegan(Touch *touch, Event *unused_event);//����һ������Ӧ�¼�
	void onTouchMoved(Touch *touch, Event *unused_event);//����һ������Ӧ�¼�
	void onTouchEnded(Touch *touch, Event *unused_event);//����һ������Ӧ�¼�

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update(float delta);

	virtual bool GrowAPlantInRowCol(int _row, int _col, PlantsType _type);//��_row,_col��ֲĳ�����͵�ֲ��
	//���������ֲ����ô�͵�����Ӧ�ĺ���������ֲ������Ȼ�󷵻�true�����򷵻�false

	PlantsAttack* tempAI;//AIָ��
	Sprite* MousePlantsSprite;//���ѡ��ʱ��ֲ����Ӱ����
	Sprite* copyMousePlantsSprite;
	BaseCard* SelectedCard;//ѡ�еĿ�Ƭ
	PlantsType SelectedPlantsType;//ѡ�еĿ�Ƭ��ֲ�������

	bool GameOverFlag;

	double _delayTime;//����Ϸ����֮�����ڼ�ʱ�����ﵽһ����ʱ��֮�󣬸�������
};

#endif // __HELLOWORLD_SCENE_H__
