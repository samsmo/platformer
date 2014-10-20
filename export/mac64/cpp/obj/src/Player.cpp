#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif

Void Player_obj::__construct(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",7,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_X,"X")
HX_STACK_ARG(__o_Y,"Y")
Float X = __o_X.Default(0);
Float Y = __o_Y.Default(0);
{
	HX_STACK_LINE(14)
	this->hasDoubleJumped = false;
	HX_STACK_LINE(13)
	this->ACCELERATION = (int)600;
	HX_STACK_LINE(12)
	this->DRAG = (int)600;
	HX_STACK_LINE(10)
	this->MAX_SPEED = (int)200;
	HX_STACK_LINE(9)
	this->GRAVITY = (int)980;
	HX_STACK_LINE(17)
	super::__construct(X,Y,null());
	HX_STACK_LINE(19)
	this->MAX_JUMP = (Float(this->GRAVITY) / Float((int)3));
	HX_STACK_LINE(21)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),true,(int)32,(int)32,null(),null());
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",23,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , false,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(23)
	this->_facingFlip->set((int)1,_Function_1_1::Block());
	struct _Function_1_2{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",24,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , true,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(24)
	this->_facingFlip->set((int)16,_Function_1_2::Block());
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("run"),Array_obj< int >::__new().Add((int)3).Add((int)4).Add((int)5),(int)6,false);
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("jump"),Array_obj< int >::__new().Add((int)0),(int)6,false);
	HX_STACK_LINE(28)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)3),(int)6,false);
	HX_STACK_LINE(29)
	this->drag->set_x(this->DRAG);
	HX_STACK_LINE(31)
	this->acceleration->set_y(this->GRAVITY);
	HX_STACK_LINE(32)
	this->maxVelocity->set_x(this->MAX_SPEED);
	HX_STACK_LINE(33)
	this->maxVelocity->set_y(this->MAX_JUMP);
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(hx::Null< Float >  __o_X,hx::Null< Float >  __o_Y)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(__o_X,__o_Y);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::movement( ){
{
		HX_STACK_FRAME("Player","movement",0x91ad8bbc,"Player.movement","Player.hx",37,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)65,::flixel::FlxG_obj::keys->pressed->checkStatus))){
			HX_STACK_LINE(39)
			this->acceleration->set_x(-(this->ACCELERATION));
			HX_STACK_LINE(40)
			this->set_facing((int)16);
		}
		else{
			HX_STACK_LINE(41)
			if ((::flixel::FlxG_obj::keys->checkStatus((int)68,::flixel::FlxG_obj::keys->pressed->checkStatus))){
				HX_STACK_LINE(42)
				this->acceleration->set_x(this->ACCELERATION);
				HX_STACK_LINE(44)
				this->set_facing((int)1);
			}
			else{
				HX_STACK_LINE(46)
				this->acceleration->set_x((int)0);
			}
		}
		HX_STACK_LINE(49)
		if (((  ((::flixel::FlxG_obj::keys->checkStatus((int)87,::flixel::FlxG_obj::keys->pressed->checkStatus))) ? bool((((int(this->touching) & int((int)4096))) > (int)0)) : bool(false) ))){
			HX_STACK_LINE(51)
			this->velocity->set_y(-(this->ACCELERATION));
			HX_STACK_LINE(52)
			this->set_facing((int)256);
		}
		else{
			HX_STACK_LINE(54)
			if (((  (((  (((  ((::flixel::FlxG_obj::keys->checkStatus((int)87,::flixel::FlxG_obj::keys->pressed->checkStatus))) ? bool(!(((((int(this->touching) & int((int)4096))) > (int)0)))) : bool(false) ))) ? bool(!(this->hasDoubleJumped)) : bool(false) ))) ? bool((bool((this->velocity->y >= (Float(-(this->MAX_JUMP)) / Float(1.5)))) && bool((this->velocity->y <= (Float(this->MAX_JUMP) / Float(1.5)))))) : bool(false) ))){
				HX_STACK_LINE(57)
				this->hasDoubleJumped = true;
				HX_STACK_LINE(58)
				this->maxVelocity->set_y((this->MAX_JUMP * (int)2));
				HX_STACK_LINE(59)
				this->velocity->set_y(-(this->ACCELERATION));
				HX_STACK_LINE(60)
				this->maxVelocity->set_y(this->MAX_JUMP);
			}
			else{
				HX_STACK_LINE(62)
				if (((((int(this->touching) & int((int)4096))) > (int)0))){
					HX_STACK_LINE(63)
					this->hasDoubleJumped = false;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,movement,(void))

Void Player_obj::animationCheck( ){
{
		HX_STACK_FRAME("Player","animationCheck",0xcbeb1971,"Player.animationCheck","Player.hx",69,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(69)
		if (((bool((bool((this->velocity->x != (int)0)) && bool((this->velocity->y == (int)0)))) || bool((this->velocity->y != (int)0))))){
			HX_STACK_LINE(71)
			int _g = this->facing;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(71)
			switch( (int)(_g)){
				case (int)1: case (int)16: {
					HX_STACK_LINE(74)
					this->animation->play(HX_CSTRING("run"),null(),null());
				}
				;break;
				case (int)256: {
					HX_STACK_LINE(76)
					this->animation->play(HX_CSTRING("jump"),null(),null());
				}
				;break;
			}
		}
		else{
			HX_STACK_LINE(79)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,animationCheck,(void))

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",83,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(84)
		this->movement();
		HX_STACK_LINE(85)
		this->animationCheck();
		HX_STACK_LINE(87)
		this->super::update();
	}
return null();
}



Player_obj::Player_obj()
{
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"DRAG") ) { return DRAG; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { return GRAVITY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_JUMP") ) { return MAX_JUMP; }
		if (HX_FIELD_EQ(inName,"movement") ) { return movement_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MAX_SPEED") ) { return MAX_SPEED; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ACCELERATION") ) { return ACCELERATION; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"animationCheck") ) { return animationCheck_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasDoubleJumped") ) { return hasDoubleJumped; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"DRAG") ) { DRAG=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GRAVITY") ) { GRAVITY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_JUMP") ) { MAX_JUMP=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MAX_SPEED") ) { MAX_SPEED=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ACCELERATION") ) { ACCELERATION=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"hasDoubleJumped") ) { hasDoubleJumped=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("GRAVITY"));
	outFields->push(HX_CSTRING("MAX_SPEED"));
	outFields->push(HX_CSTRING("MAX_JUMP"));
	outFields->push(HX_CSTRING("DRAG"));
	outFields->push(HX_CSTRING("ACCELERATION"));
	outFields->push(HX_CSTRING("hasDoubleJumped"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Player_obj,GRAVITY),HX_CSTRING("GRAVITY")},
	{hx::fsInt,(int)offsetof(Player_obj,MAX_SPEED),HX_CSTRING("MAX_SPEED")},
	{hx::fsFloat,(int)offsetof(Player_obj,MAX_JUMP),HX_CSTRING("MAX_JUMP")},
	{hx::fsInt,(int)offsetof(Player_obj,DRAG),HX_CSTRING("DRAG")},
	{hx::fsInt,(int)offsetof(Player_obj,ACCELERATION),HX_CSTRING("ACCELERATION")},
	{hx::fsBool,(int)offsetof(Player_obj,hasDoubleJumped),HX_CSTRING("hasDoubleJumped")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("GRAVITY"),
	HX_CSTRING("MAX_SPEED"),
	HX_CSTRING("MAX_JUMP"),
	HX_CSTRING("DRAG"),
	HX_CSTRING("ACCELERATION"),
	HX_CSTRING("hasDoubleJumped"),
	HX_CSTRING("movement"),
	HX_CSTRING("animationCheck"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Player_obj::__boot()
{
}

