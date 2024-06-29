#include "Title.h"
#include "Console.h"
#include "Core.h"
#include "define.h"
#include <fcntl.h>
#include <io.h>

Title* Title::m_pInst = nullptr;

void Title::Start()
{
	Init();
	while (true)
	{
		bool isEnd = Update();
		if (isEnd) break;
		Rander();
		Sleep(50);
	}
}

void Title::Init()
{
	currnetPlayerSelectMenu = (int)SelectMenu::GameStart;
	prevPlayerSelectMenu = currnetPlayerSelectMenu;

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
	cout << "게임 설명";
	GotoPos(x, y + 2);
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
	else if (currnetPlayerSelectMenu > 2) currnetPlayerSelectMenu = 2;


	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		switch (currnetPlayerSelectMenu)
		{
		case (int)SelectMenu::GameStart:
			system("cls");
			Core::GetInst()->Run();
			Core::DestoryInst();
			return true;
		case (int)SelectMenu::GameInfo:
			UpdateInfo();
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

void Title::UpdateInfo()
{
	system("cls");
	COORD Resolution = GetConsoleResolution();
	int x = (Resolution.X / 2) / 2;
	int y = Resolution.Y / 2 - 15;
	int originy = y;
	GotoPos(x - 4, y - 4);
	cout << "-게임설명-";

	//p1 control
	GotoPos(x - 16, y);
	cout << "-P1(도망자)";
	SetColor((int)COLOR::YELLOW);
	cout << "●";
	SetColor((int)COLOR::WHITE);
	cout << "조작키 - ";

	GotoPos(x - 16, y + 2);
	cout << "WASD : 이동";
	GotoPos(x - 16, y + 3);
	cout << "E : 순간이동 사용";
	GotoPos(x - 16, y + 4);
	cout << "F : 벽 부수기 사용";
	
	//p2 control
	GotoPos(x + 4, y);
	cout << "-P2(술래)";
	SetColor((int)COLOR::YELLOW);
	cout << "○";
	SetColor((int)COLOR::WHITE);
	cout << " 조작키 - ";
	GotoPos(x + 4, y+ 2);
	cout << "↑←↓→ : 이동";
	GotoPos(x + 4, y + 3);
	cout << "Enter : 순간이동 사용";
	GotoPos(x + 4, y + 4);
	cout << "R-Shift : 벽 부수기 사용";

	int itemX = x - 4;
	int itemY = y + 10;
	GotoPos(itemX - 1, itemY);
	cout << "-아이템 설명-";

	itemY += 2;
	GotoPos(x - 16, itemY++);
	cout << "光 : 잠시 맵의 전체를 밝게 해 준다.";
	GotoPos(x - 16, itemY++);
	cout << "∮ : 잠시 적의 시아를 제한한다.";
	GotoPos(x - 16, itemY++);
	cout << "Θ : 잠시 적의 움직임을 제한한다.";
	GotoPos(x - 16, itemY++);
	cout << "™ : 시간이 자신에게 유리하게 작용한다.";
	GotoPos(x - 16, itemY++);
	cout << "↑ : 자신의 시아를 증가시킨다.";


	GotoPos(x - 16, itemY++);
	cout << "℡ : 키를 눌러 순간이동 할 수 있게 해 준다.";
	GotoPos(x - 16, itemY++);
	cout << "※ : 키를 눌러 벽을 부술 수 있게 해 준다.";

	GotoPos(x - 16, itemY + 5);
	cout << "space 키를 눌러 설명 나가기";


	WaitUntilNotPressingX(VK_SPACE);

	WaitUntilPressingX(VK_SPACE);
	system("cls");
	Init();
	Rander();
	WaitUntilNotPressingX(VK_SPACE);
}

void Title::WaitUntilNotPressingX(int vKey)
{
	while (true) {
		bool pressing = GetAsyncKeyState(vKey) & 0x8000;
		if (!pressing) break;
	}
}

void Title::WaitUntilPressingX(int vKey)
{
	while (true) {
		bool pressing = GetAsyncKeyState(vKey) & 0x8000;
		if (pressing) break;
	}
}
