#include "console.h"

void FullScrean()
{
	/*SetConsoleDisplayMode
	(GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE, 0);*/

		//ShowWindow(GetConsoleWindow(),
		//	SW_MAXIMIZE); //��üȭ�� ����������������

	::SendMessage(GetConsoleWindow(),
		WM_SYSKEYDOWN,
		VK_RETURN, 0x20000000);
}

//void Gotoxy(int x, int y)
//{
//	//�ܼ�â �ڵ�
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	//Ŀ�� ���� ����ü
//	COORD Cur = { x, y }; //{x * 2, y} �� �� �ڿ������� ���� ����
//	//Ŀ�� ������ ���� �Լ�
//	SetConsoleCursorPosition(hOut, Cur);
//}

BOOL GotoPos(int x, int y)
{
	//�ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Ŀ�� ���� ����ü
	COORD Cur = { x * 2, y }; //{x * 2, y} �� �� �ڿ������� ���� ����
	//Ŀ�� ������ ���� �Լ�
	return SetConsoleCursorPosition(hOut, Cur);
}

COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
		&buf);

	return buf.dwCursorPosition;
}

void CursorVis(bool vis, DWORD size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.dwSize = size; //Ŀ�� ����
	curinfo.bVisible = vis; //on off

	SetConsoleCursorInfo
	(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void SetColor(int textcolor, int bgcolor)
{
	SetConsoleTextAttribute
	(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | textcolor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console) //��� ǥ����
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}

void SetFontSize(UINT _weight, UINT _fontx, UINT _fonty)
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _fontx;
	font.dwFontSize.Y = _fonty;
	GetCurrentConsoleFontEx(hout, false, &font);
}
