#include"Core.h"
#include"Title.h"
#include "Player.h"
#include "Item.h"
#include "Console.h"
int main() {
	Core* c = Core::GetInst();
	Title* title = new Title();
	Player* p = new Player(false);
	Player* p2 = new Player(true);
	p->currentPos = Vector2(0, 0);
	p2->currentPos = Vector2(MAP_WIDTH - 1, MAP_HEIGHT - 1);
	
	c->Init(p, p2);
	title->Start();
}