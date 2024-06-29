#include"Core.h"
#include"Title.h"
#include "Player.h"
#include "Item.h"
#include "Console.h"
int main() {
	Core* c = Core::GetInst();
	Title* title = Title::GetInst();
	
	c->Init();
	title->Start();
}