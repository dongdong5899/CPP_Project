#include"Core.h"
#include "Player.h"

int main() {
	Player* p = new Player();
	Player* p2 = new Player();
	p->currentPos = Vector2(0, 0);
	p2->currentPos = Vector2(0, 0);

	Core* game = Core::GetInst();
	game->Init(p, p2);
	game->Run();
	game->DestoryInst();
}