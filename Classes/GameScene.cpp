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
	// EXTRACTING STUFF FROM TMX MAP
	// load map
	auto map = TMXTiledMap::create("levels/level1.tmx");
	// point to the concrete, named group
	auto group = map->getObjectGroup("Entities");
	// get reference of all its objects 
	auto& entities = group->getObjects();
	// or get single reference of an object, by typing its name
	auto& player = group->getObject("Player");

	// create its value
	Value entitiesVal = Value(entities);
	Value playerVal = Value(player.at("name"));

	// play with it !
	CCLOG(entitiesVal.getDescription().c_str());

	this->addChild(map);

	return true;
}
