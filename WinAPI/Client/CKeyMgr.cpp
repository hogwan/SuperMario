#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"

int g_arrVK[static_cast<int>(KEY::LAST)] =
{
	VK_LEFT,//LEFT,
	VK_RIGHT,//RIGHT,
	VK_UP,//UP,
	VK_DOWN,//DOWN,
	'Q',//Q,
	'W',//W,
	'E',//E,
	'R',//R,
	'T',//T,
	'Y',//Y,
	'U',//U,
	'I',//I,
	'O',//O,
	'P',//P,
	'A',//A,
	'S',//S,
	'D',//D,
	'F',//F,
	'G',//G,
	'H',//H,
	'J',//J,
	'K',//K,
	'L',//L,
	'Z',//Z,
	'X',//X,
	'C',//C,
	'V',//V,
	'B',//B,
	'N',//N,
	'M',//M,
	VK_MENU,//ALT,
	VK_LSHIFT,//LSHIFT,
	VK_SPACE,//SPACE,
	VK_CONTROL,//CTAL,
	VK_RETURN,//ENTER,
	VK_ESCAPE,//ESC,

	VK_LBUTTON,//LBTN,
	VK_RBUTTON,//RBTN,

	//LAST,
};

CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::Init()
{
	for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
	{
		m_vecKey.push_back(tKeyInfo());
	}
}

void CKeyMgr::update()
{
	//윈도우 포커싱 알아내기
	//HWND hMainWnd = CCore::GetInst()->GetMainWnd();
	HWND hWnd = GetFocus();

	//윈도우 포커싱 중일 때 키 이벤트 동작
	if (nullptr != hWnd)
	{
		for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				//키가 눌려있다.
				if (m_vecKey[i].bPrevPush)
				{
					//이전에도 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					//이전에 눌려 있지 않았다
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
					m_vecKey[i].bPrevPush = true;
			}
			else
			{
				//키가 눌려있지않다
				if (m_vecKey[i].bPrevPush)
				{
					//이전에 눌려있었다.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					//이전에도 눌려 있지 않았다
					m_vecKey[i].eState = KEY_STATE::NONE;

				}
					m_vecKey[i].bPrevPush = false;
			}
		}

		//Mouse 위치 계산
		POINT ptPos = {};
		GetCursorPos(&ptPos);
		ScreenToClient(CCore::GetInst()->GetMainWnd(), &ptPos);
		m_vCurMousePos = ptPos;
	}

	//윈도우 포커싱이 아닐때
	else
	{
		for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
		{
			m_vecKey[i].bPrevPush = false;
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				if (m_vecKey[i].eState == KEY_STATE::HOLD ||
					m_vecKey[i].eState == KEY_STATE::TAP)
				{
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					m_vecKey[i].eState = KEY_STATE::NONE;
				}
			}
		}
	}
}
