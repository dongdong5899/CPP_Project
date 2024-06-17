#pragma once
#include<iostream>
using std::cout;
using std::wcout;
using std::endl;
const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;
#include<Windows.h>
#define SAFE_DELETE(p) if (p != nullptr){ delete p;	p = nullptr;}