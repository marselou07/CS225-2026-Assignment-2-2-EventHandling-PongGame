#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/entity.hh"
#include "CollisionEvent.hh"
#include "InputEvent.hh"
#include <AEEngine.h>
class Component;

class Player : public Entity
{
	int x;
	int y;

	int xscale = 30;
	int yscale = 200;

	int xvel = 0;
	int yvel = 150;
	EventHandler<Player, InputEvent> input_handler;
	EventHandler<Player, CollisionEvent> coll_handler;
	// Add version for input
	public:
		~Player();
		Player(int startx, int starty);
		void Draw() override;
		void Update() override;
		int Get_x();
		int Get_y();
		int getXScale();
		int getYScale();
		void OnEvent(InputEvent* input);
		void OnHitEvent(CollisionEvent* coll);
		IEventHandler* getHandler()
		{
			return &input_handler;
		}
		IEventHandler* getHandler_coll()
		{
			return &coll_handler;
		}
};