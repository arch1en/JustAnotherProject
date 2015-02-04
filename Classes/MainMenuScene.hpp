#pragma once

#include <string>
#include "cocos2d.h"
#include "Definitions.hpp"
#include "ui/CocosGUI.h"
#include "GameScene.hpp"

class MainMenuScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene * createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* sender);
private:
	cocos2d::Layer * mNewGameLayer;
	cocos2d::Layer * mOptionsLayer;

	CREATE_FUNC(MainMenuScene);
};