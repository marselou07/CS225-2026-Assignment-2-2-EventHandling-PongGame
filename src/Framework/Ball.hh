#pragma once
#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/entity.hh"
#include "CollisionEvent.hh"
#include <AEEngine.h>

class Component;

class Ball : public Entity
{
	int x = 0;
	int y = 0;

	int rad = 20;

	int xvel = 200;
	int yvel = 200;
	EventHandler<Ball, CollisionEvent> handler;
public:
	~Ball();
	Ball(int startx, int starty);
	void Draw() override;
	void Update() override;
	int Getx();
	int Gety();
	void OnEvent(CollisionEvent* coll);
	int getRad();
	IEventHandler* getHandler()
	{
		return &handler;
	}
};