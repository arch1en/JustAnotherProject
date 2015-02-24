#include "MainMenuScene.hpp"

USING_NS_CC;
using namespace ui;
cocos2d::Scene * MainMenuScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenuScene::create();

	scene->addChild(layer);
	return scene;
}

bool MainMenuScene::init()
{
	if (!Layer::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	mNewGameLayer = Layer::create();
	mOptionsLayer = Layer::create();

	// Load sprite sheet to cache
	auto cache = SpriteFrameCache::getInstance();

	cache->addSpriteFramesWithFile("art/ui/blue_ui.plist");

	// BACKGROUND 

	auto backgroundSprite = Sprite::create("art/env/Base pack/bg.png");

	backgroundSprite->setPosition(MIDDLE_X, MIDDLE_Y);
	backgroundSprite->setScale(BACKGROUND_SCALE);

	// TITLE SPRITE

	auto titleSprite = Sprite::createWithSpriteFrameName("blue_button03.png");
	titleSprite->setScale(2.f);
	titleSprite->setPosition(MIDDLE_X, visibleSize.height / 2 + origin.y + titleSprite->getContentSize().height * 5);
	
	// MAIN MENU

	// NEW GAME BUTTON

	auto newGameButton = Button::create("art/ui/blue_button02.png","art/ui/blue_button03.png");
	newGameButton->setTitleFontName("fonts/kenvector_future.ttf");
	newGameButton->setTitleFontSize(DEFAULT_FONT_SIZE);
	newGameButton->setTitleText("New Game");
	newGameButton->setPosition(Vec2(MIDDLE_X, MIDDLE_Y));
	newGameButton->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type){
		
		if (type == Widget::TouchEventType::ENDED)
		{
			auto scene = GameScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}

	});

	// OPTIONS BUTTON
	auto optionsButton = Button::create("art/ui/blue_button02.png", "art/ui/blue_button03.png");
	optionsButton->setTitleFontName("fonts/kenvector_future.ttf");
	optionsButton->setTitleFontSize(DEFAULT_FONT_SIZE);
	optionsButton->setTitleText("Options");
	newGameButton->addChild(optionsButton);
	optionsButton->setPosition(Vec2(optionsButton->getParent()->getContentSize().width / 2, (optionsButton->getParent()->getContentSize().height / 2) - optionsButton->getParent()->getContentSize().height - PADDING));

	// CREDITS BUTTON

	auto creditsButton = Button::create("art/ui/blue_button02.png", "art/ui/blue_button03.png");
	creditsButton->setTitleFontName("fonts/kenvector_future.ttf");
	creditsButton->setTitleFontSize(DEFAULT_FONT_SIZE);
	creditsButton->setTitleText("Credits");
	optionsButton->addChild(creditsButton);
	creditsButton->setPosition(Vec2(creditsButton->getParent()->getContentSize().width / 2, (creditsButton->getParent()->getContentSize().height / 2) - creditsButton->getParent()->getContentSize().height - PADDING));

	// QUIT BUTTON

	auto quitButton = Button::create("art/ui/blue_button02.png", "art/ui/blue_button03.png");
	quitButton->setTitleFontName("fonts/kenvector_future.ttf");
	quitButton->setTitleFontSize(DEFAULT_FONT_SIZE);
	quitButton->setTitleText("Quit");
	creditsButton->addChild(quitButton);
	quitButton->setPosition(Vec2(quitButton->getParent()->getContentSize().width / 2, (quitButton->getParent()->getContentSize().height / 2) - quitButton->getParent()->getContentSize().height - PADDING));

	// TITLE LABEL

	auto label = Label::createWithTTF("Awesome Platformer", "fonts/kenvector_future.ttf", MAIN_MENU_TITLE_SIZE);
	label->setPosition(titleSprite->getContentSize().width / 2, titleSprite->getContentSize().height / 2);
	
	titleSprite->addChild(label, 1);
	
	this->addChild(newGameButton, 1);
	this->addChild(backgroundSprite);
	this->addChild(titleSprite, 1);

	return true;
}