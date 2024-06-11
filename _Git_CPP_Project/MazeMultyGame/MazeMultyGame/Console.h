#pragma once
#include <Windows.h>
void FullScrean();
void Gotoxy(int x, int y);
BOOL GotoPos(int x, int y);
COORD CursorPos();
void CursorVis(bool vis, DWORD size);
void SetColor(int textcolor = 15, int bgcolor = 0);
int GetColor();
void LockResize();
COORD GetConsoleResolution();
void SetFontSize(UINT _weight, UINT _fontx, UINT _fonty);
enum class COLOR {
	BLACK, BLUE, GREEN, SKYBLUE, RED, VOILET,
	YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE, LIGHT_GREEN,
	MINT, LIGHT_RED, LIGHT_VOILET, LIGHT_YELLOW, WHITE, END
};
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;