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
    
	void MyInit();//初始化一些参数

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    

	bool onTouchBegan(Touch *touch, Event *unused_event);//建立一个鼠标回应事件
	void onTouchMoved(Touch *touch, Event *unused_event);//建立一个鼠标回应事件
	void onTouchEnded(Touch *touch, Event *unused_event);//建立一个鼠标回应事件

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update(float delta);

	virtual bool GrowAPlantInRowCol(int _row, int _col, PlantsType _type);//在_row,_col种植某种类型的植物
	//如果可以种植，那么就调用相应的函数进行种植操作，然后返回true，否则返回false

	PlantsAttack* tempAI;//AI指针
	Sprite* MousePlantsSprite;//鼠标选卡时的植物虚影精灵
	Sprite* copyMousePlantsSprite;
	BaseCard* SelectedCard;//选中的卡片
	PlantsType SelectedPlantsType;//选中的卡片的植物的类型

	bool GameOverFlag;

	double _delayTime;//在游戏结束之后，用于计时，当达到一定的时间之后，更换场景
};

#endif // __HELLOWORLD_SCENE_H__
