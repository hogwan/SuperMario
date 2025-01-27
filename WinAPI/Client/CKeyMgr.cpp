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
	//������ ��Ŀ�� �˾Ƴ���
	//HWND hMainWnd = CCore::GetInst()->GetMainWnd();
	HWND hWnd = GetFocus();

	//������ ��Ŀ�� ���� �� Ű �̺�Ʈ ����
	if (nullptr != hWnd)
	{
		for (int i = 0; i < static_cast<int>(KEY::LAST); i++)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				//Ű�� �����ִ�.
				if (m_vecKey[i].bPrevPush)
				{
					//�������� �����־���.
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					//������ ���� ���� �ʾҴ�
					m_vecKey[i].eState = KEY_STATE::TAP;
				}
					m_vecKey[i].bPrevPush = true;
			}
			else
			{
				//Ű�� ���������ʴ�
				if (m_vecKey[i].bPrevPush)
				{
					//������ �����־���.
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					//�������� ���� ���� �ʾҴ�
					m_vecKey[i].eState = KEY_STATE::NONE;

				}
					m_vecKey[i].bPrevPush = false;
			}
		}
	}

	//������ ��Ŀ���� �ƴҶ�
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
