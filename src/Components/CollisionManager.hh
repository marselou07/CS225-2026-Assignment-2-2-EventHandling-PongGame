#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/Ball.hh"
#include "../Framework/Player.hh"
#include "../Framework/CPU.hh"
#include "../Framework/CollisionEvent.hh"
class CollisionEventManager : public EventManager
{
	Ball* ball;
	Player* player;
	CPU* cpu;
	public:
		//Constructor get all the objects which have collisions
		CollisionEventManager(Ball* b,Player*p, CPU* c)
			:ball(b), player(p), cpu(c)
		{}
		void update() override;

};
