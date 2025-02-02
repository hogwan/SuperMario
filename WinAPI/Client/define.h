#pragma once

#define SINGLE(type) public: static type* GetInst(){static type mgr;return &mgr;} private: type(); ~type();
#define DT CTimeMgr::GetInst()->GetDT();
#define fDT CTimeMgr::GetInst()->GetfDT();
#define KEY_CHECK(key,state) CKeyMgr::GetInst()->GetKeyState(key,state) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEYSTATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEYSTATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEYSTATE::AWAY)

#define PI 3.1415926535f

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,


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