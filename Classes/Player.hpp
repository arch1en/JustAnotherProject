#pragma once

#include <memory>

#include "Entity.hpp"
#include "DrawableComposite.hpp"
#include "cocos2d.h"

USING_NS_CC;

class Player : public Entity
{
public:
	Player();
private:
	Size visibleSize;
	Vec2 origin;
};