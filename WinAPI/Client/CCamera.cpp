#include "pch.h"
#include "CCamera.h"
#include "CObject.h"
#include "CCore.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void CCamera::update()
{
	if (m_pTargetObj)
	{
		if (m_pTargetObj->IsDead())
		{
			m_pTargetObj = nullptr;
		}
		else
		{
			m_vLookAt = m_pTargetObj->GetPos();
		}
	}

	if (KEY_CHECK(KEY::UP, KEY_STATE::HOLD))
	{
		m_vLookAt.y -= 500.f * fDT;
	}
	if (KEY_CHECK(KEY::DOWN, KEY_STATE::HOLD))
	{
		m_vLookAt.y += 500.f * fDT;
	}
	if (KEY_CHECK(KEY::RIGHT, KEY_STATE::HOLD))
	{
		m_vLookAt.x += 500.f * fDT;
	}
	if (KEY_CHECK(KEY::LEFT, KEY_STATE::HOLD))
	{
		m_vLookAt.x -= 500.f * fDT;
	}

	//ȭ�� �߾���ǥ�� ī�޶� LookAt ��ǥ���� ���̰� ���
	CalDiff();
}

void CCamera::CalDiff()
{
	// ���� LookAt �� ���� Look �� ���̰��� �����ؼ� ������ LookAt�� ���Ѵ�
	Vec2 vDir = m_vLookAt - m_vPrevLookAt;
	if (vDir.Length() < 5.f)
	{
		m_vCurLookAt = m_vLookAt;
		m_vPrevLookAt = m_vLookAt;
	}
	else
	{
		m_vCurLookAt = m_vPrevLookAt + vDir.Normalize() * 500.f * fDT;
	}

	Vec2 vResolution = CCore::GetInst()->GetResolution();
	Vec2 vCenter = vResolution / 2;

	m_vDiff = m_vCurLookAt - vCenter;

	m_vPrevLookAt = m_vCurLookAt;
}
