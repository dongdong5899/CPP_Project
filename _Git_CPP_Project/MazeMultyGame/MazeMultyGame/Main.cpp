
#include"Core.h"
#include "Player.h"
int main() {
	char gayFuck[MAP_HEIGHT][MAP_WIDTH];
	Core* c = Core::GetInst();
	Player* p = new Player();
	c->Init(gayFuck);
	c->Run(gayFuck, *p);
	c->DestoryInst();
}