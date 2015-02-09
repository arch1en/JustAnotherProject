#include "GameScene.hpp"

USING_NS_CC;

Scene * GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();

#ifdef _DEBUG
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
#endif
	
	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);



	auto sprite = Sprite::create("CloseNormal.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));

	spriteBody->setCollisionBitmask(1);
	spriteBody->setContactTestBitmask(true);
	spriteBody->setDynamic(false);
	sprite->setPhysicsBody(spriteBody);

	auto sprite2 = Sprite::create("CloseNormal.png");
	sprite2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200.f));
	auto spriteBody2 = PhysicsBody::createBox(sprite2->getContentSize(), PhysicsMaterial(0, 1, 0));
	spriteBody2->setCollisionBitmask(2);
	spriteBody2->setContactTestBitmask(true);
	
	spriteBody2->setVelocity(Vec2(100, 247));

	sprite2->setPhysicsBody(spriteBody2);

	this->addChild(sprite);
	this->addChild(sprite2);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	return true;
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact & contact)
{
	PhysicsBody * a = contact.getShapeA()->getBody();
	PhysicsBody * b = contact.getShapeB()->getBody();

	if ((1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask()) ||
		(2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask()))
	{
		CCLOG("COLLISION HAS OCCURED !");
	}
	return true;
}