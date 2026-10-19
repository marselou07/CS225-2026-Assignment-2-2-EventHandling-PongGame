#include "CollisionManager.hh"

void CollisionEventManager::update()
{
	int halfx = (int)AEGetSysWindowWidth() / 2;
	int halfy = (int)AEGetSysWindowHeight() / 2;
	if (ball->Getx() + ball->getRad() >= halfx)
	{
		CollisionEvent* event = new CollisionEvent("RightWall");
		this->notifyEvent(event);
	}
	 if (ball->Getx() - ball->getRad()  <= -1* halfx)
	{
		CollisionEvent* event = new CollisionEvent("LeftWall");
		this->notifyEvent(event);
	}
	 if (ball->Gety() + ball->getRad()  >= halfy)
	{
		CollisionEvent* event = new CollisionEvent("TopWall");
		this->notifyEvent(event);

	}
	 if (ball->Gety() - ball->getRad()  <= -1 * halfy)
	{
		CollisionEvent* event = new CollisionEvent("DownWall");
		this->notifyEvent(event);
	}
}
