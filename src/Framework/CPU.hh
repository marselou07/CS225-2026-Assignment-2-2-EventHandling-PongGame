#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/entity.hh"
#include "CollisionEvent.hh"
#include "../Framework/Ball.hh"
#include <AEEngine.h>
class Component;

class CPU : public Entity
{
	int x;
	int y;

	int xscale = 30;
	int yscale = 200;
	Ball* ballseen;
	int xvel = 0;
	int yvel = 130;
	bool seing = true;

	EventHandler<CPU, CollisionEvent> coll_handler;
	public:
		~CPU();
		CPU(int startx, int starty, Ball* b);
		void Draw() override;
		void Update() override;
		int Getx_();
		int Gety_();
		int getScaleX();
		int getScaleY();
		void OnHitEvent(CollisionEvent* coll);

		IEventHandler* getHandler_coll()
		{
			return &coll_handler;
		}
};