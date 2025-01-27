#pragma once

// 1.������ ����ȭ
// ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������

// 2. Ű �Է� �̺�Ʈ ó��
// tap, hold, away


enum class KEY_STATE
{
	NONE, // ������ �ʰ�, �������� ������ ���� ����
	TAP, // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY, // �� �� ����
};
enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,
	ALT,
	LSHIFT,
	SPACE,
	CTAL,
	ENTER,
	ESC,

	LAST,
};
struct tKeyInfo
{
	KEY_STATE eState = KEY_STATE::NONE; // Ű�� ���°�
	bool bPrevPush
		= false; // ���� �����ӿ� ���ȴ���
};

class CKeyMgr
{
	SINGLE(CKeyMgr);
private:
	std::vector<tKeyInfo> m_vecKey;

public:
	void Init();
	void update();

	KEY_STATE GetKeyState(KEY _key)
	{
		return m_vecKey[static_cast<int>(_key)].eState;
	}

};

