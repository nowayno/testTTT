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
	**@ProgressTimer是继承Node的，所以也继承了Node很多的方法
	**@ProgressTo::create(time,topercent);持续时间，所要呈现的百分比
	**@Sequence::createWithTwoActions();创建两个线性动作
	*/
	//auto to1 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 100));
	//auto left = ProgressTimer::create(Sprite::create(s_pathSister1));
	////left->setType(ProgressTimer::Type::RADIAL);//ProgressTimer的进度类型
	//left->setType(ProgressTimer::Type::BAR); //ProgressTimer的进度条类型为条形
	//left->setMidpoint(Vec2(0, 0.5));
	//left->setBarChangeRate(Vec2(0, 1));
	//left->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	////this->addChild(left);
	//left->runAction(to1);
	////left->setReverseProgress(false); //反转进度条显示
	//auto to2 = Sequence::createWithTwoActions(ProgressTo::create(2, 100), ProgressTo::create(0, 100));
	//auto right = ProgressTimer::create(Sprite::create(s_pathSister2));
	//right->setReverseProgress(true);  //反转进度条显示，目前来看和setReverseDirection()一样
	//right->setMidpoint(Vec2(0.7, 0.7));
	//right->setPosition(visibleSize.width / 2 + 100, visibleSize.height / 2);
	////this->addChild(right);
	//right->runAction(to2);
	//↑ProgressTimer的类型为Bar的时候，setMidpoint与setBarChangeRate能够展示出进度条是按照什么样子
	//比如从左到右，从上到下，从中心到四边

	//-----------------------------------------------------------------------
	//
	//  Audio-NewAduioEnfine
	//
	//-----------------------------------------------------------------------
	/*
	**@AudioEngine
	**@AudioEngine::play2d(path,loop,volume,AudioProfile);音频路径，是否循环，声音大小，音频配置文件(没有就是按照默认的)
	**@end(),按照API上面说，这个必须要有，但在提供的实例工程中，没有找到这个方法的调用
	**@老版的音频就不写代码，就写点主要的
	**@要包含SimpleAudioEngine.h
	**using namespace CocosDeshion;需要使用命名空间CocosDeshion
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
	//	//是恢复点击响应事件，以同样的方式在此匿名函数内添加一个层，一个菜单，做相关的操作恢复
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
	**@Lense3D:凸透镜设置
	**@Waves3D:波浪设置
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
	**@ShakyTiles3D:震动
	**@ShuffleTiles:洗牌
	**@TurnOffTiles:关闭，使用reveres进行开启
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
	**@Waves:第四个参数是设置振幅
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
	**@Liquid:液体效果
	** create(time,size,waves,amplitude),持续时间，大小，波的数量，振幅
	*/
	//auto liquid = Liquid::create(4.0f, Size(5, 5), 4, 5);
	//auto seq = Sequence::create(liquid, DelayTime::create(3.0f), StopGrid::create(), nullptr);
	//nodegrid->runAction(seq);
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**:
	**@BlendFunc 纹理属性，看API，不写了
	**
	*/
	//……………………
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
	**@Sprite3D:与Sprite的用法一样
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
	**@Sprite3D:与Sprite的用法一样
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
	**@Properties:用于加载文本文件的属性文件,create(fliename)路径中
	**@Meterial:创建材质,createWithProperties(properties)，参数是之前创建的properties，还有其他的创建方法，API
	**@setGLProgramState(material->getTechniqueByName(name)->getPassByIndex(0)->getGLProgramState());继承Node
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
	**@Meterial:创建材质,createWithFilename(filename)，参数是路径名，还有其他的创建方法，API
	**@Ambientlight:环境灯光，向四周漫射
	**@Directionlight:方向光
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
	**@ClippingNode:裁剪
	**@stencil:模板，只有形状，但对模板本身不进行渲染，比如放进去一个五颜六色的方形，只会出现一个方形，而不会有五颜六色
	**@setInverted(bool);设置未被遮罩区是否显示
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
	**@DrawNode:可以说是铅笔工具,看API
	*/
	///////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	**@MotionStreak:尾巴效果
	**@create(fadetime,minseg,width,color,path);
	**@create(fadetime,minseg,width,color,*texture);
	**两个create:消失的时间，最小的片段长度，宽度，（前者）纹理的路径（后者）纹理的指针
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
	**@ParallaxNode:透视，直接create()
	**@注意:addChild方法中，第三个参数是透视率，简单说就是几个对象之间x，y轴的移动变化率，越大所呈现出的越快，为0则不移动，第四个就是所添加的对象的位置
	**@运动的节点是ParallaxNode，这个运动能够体现出透视
	**@更加简单的说，这个节点就是将对象集合集合起来，封装成透视算法，也可以自己手动写，但封装了为啥不用
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
