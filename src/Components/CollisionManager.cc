#include "CollisionManager.hh"
/******************************************************************************
filename    InputManager.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: The program will handle each case of collision for
all objects subscribed
******************************************************************************/
/**
 * update
 * @param context: for each objects check of the collisions
 * that are on the update are triggered in that case
 * send the Collision event to all objects subscribed
 * @return nothing
 */
void CollisionEventManager::update()
{
	int halfx = (int)AEGetSysWindowWidth() / 2;
	int halfy = (int)AEGetSysWindowHeight() / 2;
	AEVec2 playerpos(player->Get_x(), player->Get_y());
	AEVec2 ballpos(ball->Getx(), ball->Gety());
	AEVec2 cpupos(cpu->Getx_(), cpu->Gety_());
	if (ball->Getx() + ball->getRad() >= halfx)
	{
		CollisionEvent* event = new CollisionEvent("RightWall");
		this->notifyEvent(event);
		return;
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
		return;

	 }
	 if (ball->Gety() - ball->getRad()  <= -1 * halfy)
	 {
		CollisionEvent* event = new CollisionEvent("DownWall");
		this->notifyEvent(event);
		return;
	 }
	 if (AEStaticRectToStaticCircle(&playerpos, player->getXScale(), player->getYScale()
		 , &ballpos, (float)ball->getRad()))
	 {
		 CollisionEvent* event = new CollisionEvent("PlayerToBall");
		 this->notifyEvent(event);
		 return;
	 }
	 if (AEStaticRectToStaticCircle(&cpupos, cpu->getScaleX(), cpu->getScaleY()
		 , &ballpos, (float)ball->getRad()))
	 {
		 CollisionEvent* event = new CollisionEvent("CPUToBall");
		 this->notifyEvent(event);
		 return;
	 }
	 if (player->Get_y() + player->getYScale()/2>= halfy)
	 {
		 CollisionEvent* event = new CollisionEvent("TopWallPlayer");
		 this->notifyEvent(event);
		 return;
	 }
	 if (player->Get_y() - player->getYScale() / 2 <= -halfy)
	 {
		 CollisionEvent* event = new CollisionEvent("DownWallPlayer");
		 this->notifyEvent(event);
		 return;
	 }

}
