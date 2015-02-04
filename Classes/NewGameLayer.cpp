#include "NewGameLayer.hpp"

USING_NS_CC;

bool NewGameLayer::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("art/env/Base pack/bg.png");

	backgroundSprite->setPosition(MIDDLE_X, MIDDLE_Y);
	backgroundSprite->setScale(BACKGROUND_SCALE);
}