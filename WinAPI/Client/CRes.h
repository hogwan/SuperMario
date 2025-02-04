#pragma once
class CRes
{
private:
	std::wstring m_strKey;          // ���ҽ� Ű
	std::wstring m_strRelativePath; // �����

public:
	void SetKey(const std::wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const std::wstring& _strPath) { m_strRelativePath = _strPath; }

	const std::wstring& GetKey() { return m_strKey; }
	const std::wstring& GetRelativePath() { return m_strRelativePath; }
};

