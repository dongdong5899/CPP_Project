#pragma once
class Title
{
public:
	void Start();
private:
	void Init();
	void Rander();
	bool Update();
	enum class SelectMenu
	{
		GameStart, GameExit
	};
	int currnetPlayerSelectMenu;
	int prevPlayerSelectMenu;
};


