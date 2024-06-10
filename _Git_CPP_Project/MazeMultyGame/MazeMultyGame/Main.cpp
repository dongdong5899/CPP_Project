
#include"Core.h"
#include "Player.h"
int main() {
	Core* c = Core::GetInst();
	Player* p = new Player();
	p->vector = new Vector2(0,0);
	c->Init(p);
	c->Run();
	c->DestoryInst();
}