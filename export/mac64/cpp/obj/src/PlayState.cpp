#include <hxcpp.h>

#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_ogmo_FlxOgmoLoader
#include <flixel/addons/editors/ogmo/FlxOgmoLoader.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
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
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",17,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(17)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",27,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(28)
		::flixel::addons::editors::ogmo::FlxOgmoLoader _g = ::flixel::addons::editors::ogmo::FlxOgmoLoader_obj::__new(HX_CSTRING("assets/data/room-001.oel"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(28)
		this->level = _g;
		HX_STACK_LINE(30)
		::flixel::tile::FlxTilemap _g1 = this->level->loadTilemap(HX_CSTRING("assets/images/tiles.png"),(int)16,(int)16,HX_CSTRING("walls"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(30)
		this->levelWalls = _g1;
		HX_STACK_LINE(31)
		this->levelWalls->setTileProperties((int)1,(int)0,null(),null(),null());
		HX_STACK_LINE(32)
		this->levelWalls->setTileProperties((int)2,(int)4369,null(),null(),null());
		HX_STACK_LINE(33)
		this->add(this->levelWalls);
		HX_STACK_LINE(35)
		::Player _g2 = ::Player_obj::__new((int)20,(int)20);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(35)
		this->player = _g2;
		HX_STACK_LINE(37)
		this->level->loadEntities(this->placeEntities_dyn(),HX_CSTRING("entities"));
		HX_STACK_LINE(38)
		::flixel::FlxG_obj::camera->follow(this->player,(int)1,null(),(int)1);
		HX_STACK_LINE(39)
		this->add(this->player);
		HX_STACK_LINE(40)
		::flixel::FlxG_obj::mouse->set_visible(false);
		HX_STACK_LINE(41)
		this->super::create();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",50,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",57,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		::flixel::FlxG_obj::overlap(this->player,this->levelWalls,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(60)
		this->super::update();
	}
return null();
}


Void PlayState_obj::placeEntities( ::String entityName,::Xml entityData){
{
		HX_STACK_FRAME("PlayState","placeEntities",0xcb21ad57,"PlayState.placeEntities","PlayState.hx",65,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(entityName,"entityName")
		HX_STACK_ARG(entityData,"entityData")
		HX_STACK_LINE(65)
		if (((entityName == HX_CSTRING("player")))){
			HX_STACK_LINE(67)
			::String _g = entityData->get(HX_CSTRING("x"));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(67)
			Dynamic _g1 = ::Std_obj::parseInt(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(67)
			this->player->set_x(_g1);
			HX_STACK_LINE(68)
			::String _g2 = entityData->get(HX_CSTRING("y"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(68)
			Dynamic _g3 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(68)
			this->player->set_y(_g3);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,placeEntities,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(levelWalls,"levelWalls");
	HX_MARK_MEMBER_NAME(player,"player");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(level,"level");
	HX_VISIT_MEMBER_NAME(levelWalls,"levelWalls");
	HX_VISIT_MEMBER_NAME(player,"player");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"levelWalls") ) { return levelWalls; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"placeEntities") ) { return placeEntities_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< ::flixel::addons::editors::ogmo::FlxOgmoLoader >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"levelWalls") ) { levelWalls=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("levelWalls"));
	outFields->push(HX_CSTRING("player"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::addons::editors::ogmo::FlxOgmoLoader*/ ,(int)offsetof(PlayState_obj,level),HX_CSTRING("level")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,levelWalls),HX_CSTRING("levelWalls")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,player),HX_CSTRING("player")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("level"),
	HX_CSTRING("levelWalls"),
	HX_CSTRING("player"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("placeEntities"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
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

void PlayState_obj::__boot()
{
}

