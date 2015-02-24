#include "Player.hpp"

Player::Player()
	: visibleSize{ Director::getInstance()->getVisibleSize() }
	, origin{ Director::getInstance()->getVisibleOrigin() }
{
	getComposite()->addComponent(new DrawableComposite());
	
}