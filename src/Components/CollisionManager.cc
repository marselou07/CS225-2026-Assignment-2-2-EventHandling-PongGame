#include "CollisionManager.hh"

void CollisionEventManager::update()
{
	int halfx = (int)AEGetSysWindowWidth() / 2;
	int halfy = (int)AEGetSysWindowHeight() / 2;
	AEVec2* playerpos = new AEVec2(player->Get_x(), player->Get_y());
	AEVec2* ballpos = new AEVec2(ball->Getx(), ball->Gety());
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
	 if (AEStaticRectToStaticCircle(playerpos, player->getXScale(), player->getYScale()
		 , ballpos, (float)ball->getRad()))
	 {
		 CollisionEvent* event = new CollisionEvent("PlayerToBall");
		 this->notifyEvent(event);
	 }
	 if (player->Get_y() + player->getYScale()/2>= halfy)
	 {
		 CollisionEvent* event = new CollisionEvent("TopWallPlayer");
		 this->notifyEvent(event);
	 }
	 if (player->Get_y() - player->getYScale() / 2 <= -halfy)
	 {
		 CollisionEvent* event = new CollisionEvent("DownWallPlayer");
		 this->notifyEvent(event);
	 }
}
