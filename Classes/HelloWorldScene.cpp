#include "HelloWorldScene.h"
#include "testResource.h"
#include "AudioEngine.h"
#include "chipmunk.h"

USING_NS_CC;
using namespace cocos2d::experimental;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
class Lens3d :public cocos2d::Node
{
public:
	virtual void setPosition(const Vec2& var)
	{
		_lens3D->setPosition(var);
	}

	virtual const Vec2& getPosition() const
	{
		return _lens3D->getPosition();
	}

	static Lens3d* create(Lens3D* pAction)
	{
		Lens3d* pRet = new (std::nothrow) Lens3d();
		pRet->_lens3D = pAction;
		pRet->autorelease();
		return pRet;
	}
private:
	Lens3d() :_lens3D(nullptr) {}
	Lens3D* _lens3D;
};

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto director = Director::getInstance();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
 //   auto closeItem = MenuItemImage::create(
 //                                          "CloseNormal.png",
 //                                          "CloseSelected.png",
 //                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
 //   
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
 //                               origin.y + closeItem->getContentSize().height/2));

 //   // create menu, it's an autorelease object
 //   auto menu = Menu::create(closeItem, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   this->addChild(menu, 1);

 //   /////////////////////////////
 //   // 3. add your codes below...

 //   // add a label shows "Hello World"
 //   // create and initialize a label
 //   
 //   auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
 //   
 //   // position the label on the center of the screen
 //   label->setPosition(Vec2(origin.x + visibleSize.width/2,
 //                           origin.y + visibleSize.height - label->getContentSize().height));

 //   // add the label as a child to this layer
 //   this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("Hello.png");

	//// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//// add the sprite as a child to this layer
	//this->addChild(sprite, 0);

	//-----------------------------------------------------------------------
	//
	//  Action-Progress
	//
	//-----------------------------------------------------------------------

	/*
	**@ProgressTimer�Ǽ̳�Node�ģ�����Ҳ�̳���Node�ܶ�ķ���
	**@ProgressTo::create(time,topercent);����ʱ�䣬��Ҫ���ֵİٷֱ�
	**@Sequence::createWithTwoActions();�����������Զ���
	*/
	//auto to1 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 100));
	//auto left = ProgressTimer::create(Sprite::create(s_pathSister1));
	////left->setType(ProgressTimer::Type::RADIAL);//ProgressTimer�Ľ�������
	//left->setType(ProgressTimer::Type::BAR); //ProgressTimer�Ľ���������Ϊ����
	//left->setMidpoint(Vec2(0, 0.5));
	//left->setBarChangeRate(Vec2(0, 1));
	//left->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	////this->addChild(left);
	//left->runAction(to1);
	////left->setReverseProgress(false); //��ת��������ʾ
	//auto to2 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 100));
	//auto right = ProgressTimer::create(Sprite::create(s_pathSister2));
	//right->setReverseProgress(true);  //��ת��������ʾ��Ŀǰ������setReverseDirection()һ��
	//right->setMidpoint(Vec2(0.7, 0.7));
	//right->setPosition(visibleSize.width / 2 + 100, visibleSize.height / 2);
	////this->addChild(right);
	//right->runAction(to2);
	//��ProgressTimer������ΪBar��ʱ��setMidpoint��setBarChangeRate�ܹ�չʾ���������ǰ���ʲô����
	//��������ң����ϵ��£������ĵ��ı�

	//-----------------------------------------------------------------------
	//
	//  Audio-NewAduioEnfine
	//
	//-----------------------------------------------------------------------
	/*
	**@AudioEngine
	**@AudioEngine::play2d(path,loop,volume,AudioProfile);��Ƶ·�����Ƿ�ѭ����������С����Ƶ�����ļ�(û�о��ǰ���Ĭ�ϵ�)
	**@end(),����API����˵���������Ҫ�У������ṩ��ʵ�������У�û���ҵ���������ĵ���
	**@�ϰ����Ƶ�Ͳ�д���룬��д����Ҫ��
	**@Ҫ����SimpleAudioEngine.h
	**using namespace CocosDeshion;��Ҫʹ�������ռ�CocosDeshion
	*/
	//auto ae = AudioEngine::play2d("F:\\music\\Stole The Show.mp3", false, 1.0f, nullptr);
	//log("this is an AudioEngine id:%d", ae);
	//auto ae1 = AudioEngine::play2d("F:\\music\\Suit & Tie - Justin Timberlake,Jay-Z.mp3", false, 1.0f, nullptr);
	//log("this is an AudioEngine id%d:", ae1);
	//AudioEngine::stop(ae);

	//-----------------------------------------------------------------------
	//
	//  ClickAndMove
	//
	//-----------------------------------------------------------------------
	/*
	**
	**
	*/
	//auto s = Sprite::create(s_pathGrossini);
	//s->setPosition(100, 100);
	//this->addChild(s);
	//auto listner = EventListenerTouchOneByOne::create();
	//listner->onTouchBegan = [this](Touch* touch, Event* event)
	//{
	//	return true;
	//};
	//listner->onTouchEnded = [this, s](Touch* touch, Event* event)
	//{
	//	auto location = touch->getLocation();
	//	s->stopAllActions();
	//	s->runAction(MoveTo::create(1, Vec2(location.x, location.y)));
	//	//log("click position: x->%f  y->%f", location.x, location.y);
	//	auto i = location.x - s->getPosition().x;
	//	auto j = location.y - s->getPosition().y;
	//	auto ij = (float)CC_RADIANS_TO_DEGREES(atanf(i / j));
	//	if (j < 0)
	//		if (i < 0)
	//			ij = 180 + fabs(ij);
	//		else
	//			ij = 180 - fabs(ij);
	//	s->runAction(RotateTo::create(1, ij));
	//};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listner, this);

	//-----------------------------------------------------------------------
	//
	//  EventDispatcher
	//
	//-----------------------------------------------------------------------
	/*
	**
	**
	*/
	//int zorder = 0;
	//auto s1 = Sprite::create("Images/CyanSquare.png");
	//s1->setPosition(100, 100);
	//this->addChild(s1);
	//s1->setTag(1);
	//s1->setZOrder(zorder);

	//auto s2 = Sprite::create("Images/MagentaSquare.png");
	//s2->setPosition(150, 100);
	//this->addChild(s2);
	//s2->setTag(2);
	//s2->setZOrder(++zorder);

	//auto s3 = Sprite::create("Images/YellowSquare.png");
	//s3->setPosition(120, 80);
	//s2->addChild(s3);
	//s3->setTag(3);
	//s3->setZOrder(++zorder);

	//auto lis = EventListenerTouchOneByOne::create();
	//lis->setSwallowTouches(true);
	//lis->onTouchBegan = [&](Touch* touch, Event* event)
	//{
	//	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//	Vec2 location = target->convertToNodeSpace(touch->getLocation());
	//	Size s = target->getContentSize();
	//	Rect rect = Rect(0, 0, s.width, s.height);
	//	if (rect.containsPoint(location))
	//	{
	//		//target->setOpacity(180);
	//		target->setZOrder(++zorder);
	//		log("this target tag is %d", target->getTag());
	//		return true;
	//	}
	//	return false;
	//};
	//lis->onTouchMoved = [](Touch* touch, Event* event)
	//{
	//	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//	log("this target tag is %d", target->getTag());
	//	target->setPosition(target->getPosition() + touch->getDelta());
	//};
	//lis->onTouchEnded = [](Touch* touch, Event* event)
	//{

	//};
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(lis, s1);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(lis->clone(), s2);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(lis->clone(), s3);

	//auto pop = MenuItemFont::create("PopUp", [=](Ref* ref)
	//{
	//	_eventDispatcher->pauseEventListenersForTarget(this, true);
	//	//_eventDispatcher->resumeEventListenerForTarget(this,true);
	//	//�ǻָ������Ӧ�¼�����ͬ���ķ�ʽ�ڴ��������������һ���㣬һ���˵�������صĲ����ָ�
	//});
	//Menu* menu = Menu::create(pop, nullptr);
	//menu->setPosition(0, 0);
	//this->addChild(menu);

	//-----------------------------------------------------------------------
	//
	//  EffectsAdvanced
	//
	//-----------------------------------------------------------------------
	/*
	**@Lense3D:͹͸������
	**@Waves3D:��������
	*/
	//auto nodegrid = NodeGrid::create();
	//this->addChild(nodegrid, 1);

	//auto nodeg = NodeGrid::create();
	////nodeg->addChild(nodegrid);
	//this->addChild(nodeg);

	//auto bg = Sprite::create("Images/background3.png");
	//bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//nodeg->addChild(bg, 1);
	//auto s = Sprite::create(s_pathGrossini);
	//s->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//nodegrid->addChild(s, 2);

	//auto lense = Lens3D::create(0.0f, Size(15, 10), Vec2(visibleSize.width / 2, visibleSize.height / 2), 240);
	//auto waves = Waves3D::create(10, Size(15, 10), 18, 15);
	//auto re = ReuseGrid::create(1);
	//auto delay = DelayTime::create(8);
	//nodegrid->runAction(Sequence::create(lense, re, delay, waves, nullptr));0
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@ShakyTiles3D:��
	**@ShuffleTiles:ϴ��
	**@TurnOffTiles:�رգ�ʹ��reveres���п���
	*/
	//auto shaky = ShakyTiles3D::create(5, Size(15, 10), 4, false);
	//auto shuff = ShuffleTiles::create(3, Size(15, 10), 3);
	//auto turnoff = TurnOffTiles::create(5, Size(15, 10));
	//auto turnon = turnoff->reverse();
	//auto reuse = ReuseGrid::create(2);
	//auto delay = DelayTime::create(1);
	//nodegrid->runAction(Sequence::create(shaky, delay, reuse, shuff, delay->clone(), turnoff, turnon, nullptr));
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Waves:���ĸ��������������
	**@Shaky3D
	*/
	//auto waves = Waves::create(4.0f, Size(15, 10), 6, 20, true, false);
	//auto shaky = Shaky3D::create(5.0f, Size(15, 10), 3, false);
	//nodeg->runAction(RepeatForever::create(waves));
	//nodegrid->runAction(RepeatForever::create(shaky));
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Lens3D:
	**@JumpBy:
	**@director->getActionManager()->addAction(action,node,puase)
	*/
	//auto lens = Lens3D::create(10, Size(15, 10), Vec2(10, 10), 120);
	//auto jump = JumpBy::create(4.0f, Vec2(280, 0), 100, 4);
	//auto jump_back = jump->reverse();
	//auto lenstarget = Lens3d::create(lens);
	//this->addChild(lenstarget);
	//director->getActionManager()->addAction(Sequence::create(jump, jump_back, nullptr), lenstarget, false);
	//nodeg->runAction(lens);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**:
	**@Liquid:Һ��Ч��
	** create(time,size,waves,amplitude),����ʱ�䣬��С���������������
	*/
	//auto liquid = Liquid::create(4.0f, Size(5, 5), 4, 5);
	//auto seq = Sequence::create(liquid, DelayTime::create(3.0f), StopGrid::create(), nullptr);
	//nodegrid->runAction(seq);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**:
	**@BlendFunc �������ԣ���API����д��
	**
	*/
	//����������������
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**:
	**@
	**
	*/
	//auto s1 = Sprite::create(s_pathGrossini);
	//s1->setPosition(100, 50);
	//auto jump = JumpBy::create(3.0f, Vec2(visibleSize.width - 80, 0), 40, 2);
	//this->addChild(s1);
	//s1->runAction(RepeatForever::create(Sequence::create(jump, jump->reverse(), nullptr)));

	//auto item = MenuItemFont::create("pause", [&](Ref* ref)
	//{
	//	if (Director::getInstance()->isPaused())
	//		Director::getInstance()->resume();
	//	else
	//		Director::getInstance()->pause();
	//});
	//auto menu = Menu::create(item, nullptr);
	//menu->setPosition(240, 300);
	//this->addChild(menu);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Meterial System Sprite3D
	**@Sprite3D:��Sprite���÷�һ��
	**
	*/
	//auto sprite3d = Sprite3D::create("Sprite3DTest/boss1.obj", "Sprite3DTest/boss.png");
	//sprite3d->setPosition(240, 120);
	//sprite3d->setScale(8.0f);
	////sprite3d->setTexture("Sprite3DTest/boss.png");
	//this->addChild(sprite3d);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Meterial System Sprite3D
	**@Sprite3D:��Sprite���÷�һ��
	**
	*/
	//const char* names[] = {
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//	"Sprite3DTest/ReskinGirl.c3b",
	//};
	//const int totalNames = sizeof(names) / sizeof(names[0]);
	//for (int i = 0; i < totalNames; i++)
	//{
	//	auto sprite = Sprite3D::create(names[i]);
	//	sprite->setPosition((visibleSize.width / (totalNames + 1))*(i + 1), visibleSize.height / 4);
	//	sprite->setScale(3.0f);
	//	this->addChild(sprite);
	//}
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Properties:���ڼ����ı��ļ��������ļ�,create(fliename)·����
	**@Meterial:��������,createWithProperties(properties)��������֮ǰ������properties�����������Ĵ���������API
	**@setGLProgramState(material->getTechniqueByName(name)->getPassByIndex(0)->getGLProgramState());�̳�Node
	*/
	//auto pro = Properties::createNonRefCounted("Materials/2d_effects.material#sample");
	//Material* met = Material::createWithProperties(pro);
	//auto s1 = Sprite::create("Images/grossini.png");
	//s1->setPosition(visibleSize.width / 4, visibleSize.height / 2);
	//s1->setGLProgramState(met->getTechniqueByName("noise")->getPassByIndex(0)->getGLProgramState());
	//this->addChild(s1);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@Sprite3D
	**@Meterial:��������,createWithFilename(filename)��������·���������������Ĵ���������API
	**@Ambientlight:�����ƹ⣬����������
	**@Directionlight:�����
	*/
	//auto sprite3d = Sprite3D::create("Sprite3DTest/boss1.obj");
	//sprite3d->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//sprite3d->setScale(6);
	//this->addChild(sprite3d);

	//Material* me = Material::createWithFilename("Materials/3d_effects.material");
	//sprite3d->setMaterial(me);

	////auto light1 = AmbientLight::create(Color3B::RED);
	////this->addChild(light1);
	//
	//auto light2 = DirectionLight::create(Vec3(-1, 1, 0), Color3B::RED);
	//this->addChild(light2);

	//auto rot = RotateBy::create(5, Vec3(30, 60, 270));
	//auto repeat = RepeatForever::create(rot);
	//sprite3d->runAction(repeat);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@ClippingNode:�ü�
	**@stencil:ģ�壬ֻ����״������ģ�屾��������Ⱦ������Ž�ȥһ��������ɫ�ķ��Σ�ֻ�����һ�����Σ���������������ɫ
	**@setInverted(bool);����δ���������Ƿ���ʾ
	**@
	*/
	//auto stencil = DrawNode::create();
	////auto stencil = Node::create();
	////stencil->addChild(Sprite::create("CloseNormal.png"));
	//Vec2 vec[4];
	//vec[0] = Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100);
	//vec[1] = Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 + 100);
	//vec[2] = Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100);
	//vec[3] = Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 100);
	//stencil->drawPolygon(vec, 4, Color4F(0.0f, 1.0f, 0.0f, 1.0f), 0, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
	////stencil->setContentSize(visibleSize / 4);
	//auto clippingnode = ClippingNode::create(stencil);
	//clippingnode->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//clippingnode->setInverted(true);
	//this->addChild(clippingnode);
	//clippingnode->addChild(Sprite::create("HelloWorld.png"));
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@DrawNode:����˵��Ǧ�ʹ���,��API
	*/
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@MotionStreak:β��Ч��
	**@create(fadetime,minseg,width,color,path);
	**@create(fadetime,minseg,width,color,*texture);
	**����create:��ʧ��ʱ�䣬��С��Ƭ�γ��ȣ���ȣ���ǰ�ߣ������·�������ߣ������ָ��
	*/
	//sprite = Sprite::create("Images/SpinningPeas.png");
	//sprite->setPosition(100, 100);
	//motion = MotionStreak::create(3.0f, 5.0f, 23, Color3B::WHITE, s_streak);
	//motion->setPosition(sprite->getPosition());
	//this->addChild(sprite);
	//this->addChild(motion);
	//auto move = MoveBy::create(3.0f, Vec2(400, 400));
	//auto moveback = move->reverse();
	//sprite->runAction(RepeatForever::create(Sequence::create(move, moveback, nullptr)));
	//scheduleUpdate();
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@ParallaxNode:͸�ӣ�ֱ��create()
	**@ע��:addChild�����У�������������͸���ʣ���˵���Ǽ�������֮��x��y����ƶ��仯�ʣ�Խ�������ֳ���Խ�죬Ϊ0���ƶ������ĸ���������ӵĶ����λ��
	**@�˶��Ľڵ���ParallaxNode������˶��ܹ����ֳ�͸��
	**@���Ӽ򵥵�˵������ڵ���ǽ����󼯺ϼ�����������װ��͸���㷨��Ҳ�����Լ��ֶ�д������װ��Ϊɶ����
	*/
	//auto par = ParallaxNode::create();
	//auto s1 = Sprite::create("Hello.png");
	//auto s2 = Sprite::create("HelloWorld.png");
	//par->addChild(s1, 0, Vec2(0.4f, 0.3f), Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//par->addChild(s2, 1, Vec2(1.0f, 1.0f), Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
	//auto moveto = MoveBy::create(4.0f, Vec2(300, 0));
	//auto moveback = moveto->reverse();
	//par->runAction(RepeatForever::create(Sequence::create(moveto, moveback, nullptr)));
	//this->addChild(par);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@
	**@ParticleSystemQuad:API
	**@
	**@
	*/


	return true;
}

void HelloWorld::update(float dt)
{
	motion->setPosition(sprite->getPosition());
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
