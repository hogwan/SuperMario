#pragma once

#define SINGLE(type) public: static type* GetInst(){static type mgr;return &mgr;} private: type(); ~type();
#define DT CTimeMgr::GetInst()->GetDT();
#define fDT CTimeMgr::GetInst()->GetfDT();

#define CLONE(type) type* Clone() {return new type(*this);}

#define KEY_CHECK(key,state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEYSTATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEYSTATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEYSTATE::AWAY)
#define MOUSE_POS CKeyMgr::GetInst()->GetMousePos()

#define PI 3.1415926535f

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MONSTER,
	PROJ_PLAYER,
	PROJ_MONSTER,


	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE 
{
	RED,
	GREEN,
	BLUE,

	END,
};

enum class EVENT_TYPE
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,

	END,
};