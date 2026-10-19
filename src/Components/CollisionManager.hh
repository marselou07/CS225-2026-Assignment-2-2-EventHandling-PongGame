#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/Ball.hh"
#include "../Framework/Player.hh"
#include "../Framework/CollisionEvent.hh"
class CollisionEventManager : public EventManager
{
	Ball* ball;
	Player* player;
	public:
		CollisionEventManager(Ball* b,Player*p)
			:ball(b), player(p)
		{}
		void update() override;

};
