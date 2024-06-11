#include"Core.h"
#include "Player.h"
using namespace VietEngine;
int main() {
	Core* c = Core::GetInst();
	Player* p = new Player();
	Player* p2 = new Player();
	p->vector = Vector2(1, 0);
	p2->vector = Vector2(0, 0);
	//p.vector = new Vector2(1,0);
	//p2->vector = new Vector2(3,0);
	//Vector2 a = Vector2::up;

	c->Init(p, p2);
	c->Run();
	c->DestoryInst();
}