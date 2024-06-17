#include"Core.h"
#include "Player.h"
using namespace VietEngine;
int main() {
	Core* c = Core::GetInst();
	Player* p = new Player(false);
	Player* p2 = new Player(true);
	p->currentPos = Vector2(0, 0);
	p2->currentPos = Vector2(0, 0);

	c->Init(p, p2);
	c->Run();
	c->DestoryInst();
}