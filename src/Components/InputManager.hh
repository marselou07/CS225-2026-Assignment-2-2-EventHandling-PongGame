#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/Player.hh"
#include "../Framework/InputEvent.hh"
class InputEventManager : public EventManager
{
	Player* player;
	public:
		InputEventManager(Player* p) : player(p)
		{}
		void update() override;
};