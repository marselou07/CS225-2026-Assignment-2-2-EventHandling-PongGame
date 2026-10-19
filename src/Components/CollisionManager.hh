#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/Ball.hh"
#include "../Framework/CollisionEvent.hh"
class CollisionEventManager : public EventManager
{
	Ball* ball;
	public:
		CollisionEventManager(Ball* b)
			:ball(b)
		{}
		void update() override;

};
