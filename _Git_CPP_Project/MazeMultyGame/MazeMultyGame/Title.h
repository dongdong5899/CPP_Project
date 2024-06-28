#pragma once
class Title
{
public:
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
};


