#include "Title.h"
#include "Console.h"
#include "Core.h"
#include "define.h"
#include <fcntl.h>
#include <io.h>

void Title::Start()
{
	Init();
	while (true)
	{
		bool isEnd = Update();
		if (isEnd) break;
		Rander();
		Sleep(25);
	}
}

void Title::Init()
{
	currnetPlayerSelectMenu = (int)SelectMenu::GameStart;

	SetFontSize(FW_BOLD, 40, 40);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < 3; ++i)
	{
		wcout << L" ______         __         __         _______         __ __              _______                    " << endl;
		wcout << L"|      |.---.-.|  |_.----.|  |--.    |   |   |.--.--.|  |  |_.--.--.    |   |   |.---.-.-----.-----." << endl;
		wcout << L"|   ---||  _  ||   _|  __||     |    |       ||  |  ||  |   _|  |  |    |       ||  _  |-- __|  -__|" << endl;
		wcout << L"|______||___._||____|____||__|__|    |__|_|__||_____||__|____|___  |    |__|_|__||___._|_____|_____|" << endl;
		wcout << L"                                                             |_____|                                " << endl;
	}
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void Title::Rander()
{
	COORD Resolution = GetConsoleResolution();
	int x = (Resolution.X / 2) / 2 - 4;
	int y = Resolution.Y / 2.5;
	int originy = y;

	GotoPos(x, y);
	cout << "게임 시작";
	GotoPos(x, y + 1);
	cout << "게임 종료";

	GotoPos(x - 1, y + currnetPlayerSelectMenu);
	cout << "> ";
	if (prevPlayerSelectMenu != currnetPlayerSelectMenu)
	{
		GotoPos(x - 1, y + prevPlayerSelectMenu);
		cout << "  ";
		prevPlayerSelectMenu = currnetPlayerSelectMenu;
	}
}

bool Title::Update()
{
	int prevPlayerSelectMenu = currnetPlayerSelectMenu;
	if (GetAsyncKeyState(VK_UP) & 0x8000 || 
		GetAsyncKeyState(0x57) & 0x8000)
		--currnetPlayerSelectMenu;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000 || 
			 GetAsyncKeyState(0x53) & 0x8000)
		++currnetPlayerSelectMenu;

	if (currnetPlayerSelectMenu < 0) currnetPlayerSelectMenu = 0;
	else if (currnetPlayerSelectMenu > 1) currnetPlayerSelectMenu = 1;


	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		switch (currnetPlayerSelectMenu)
		{
		case (int)SelectMenu::GameStart:
			system("cls");
			Core::GetInst()->Run();
			Core::DestoryInst();
			return false;
		case (int)SelectMenu::GameExit:
			system("cls");
			cout << "종료^^";
			return true;
		default:
			break;
		}
	}

	return false;
}
