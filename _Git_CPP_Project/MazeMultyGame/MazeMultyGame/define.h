#pragma once
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;
const int MAP_WIDTH = 41;
const int MAP_HEIGHT = 40;
#include<Windows.h>
#define SAFE_DELETE(p) if (p != nullptr){ delete p;	p = nullptr;}
#define RenderLevel 7