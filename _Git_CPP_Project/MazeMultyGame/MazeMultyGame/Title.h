#pragma once
class Title
{
public:
	static Title* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Title;
		return m_pInst;
	}
	void Start();
private:
	void Init();
	void Rander();
	bool Update();
	void UpdateInfo();
	void WaitUntilNotPressingX(int vKey);
	void WaitUntilPressingX(int vKey);
	enum class SelectMenu
	{
		GameStart, GameInfo, GameExit
	};
	int currnetPlayerSelectMenu;
	int prevPlayerSelectMenu;

	static Title* m_pInst;
};


