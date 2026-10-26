#include"Ball.hh"
/******************************************************************************
filename    ball.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: This probram will create the logic for the ball
******************************************************************************/

/**
 * Ball
 * @param context: constructor
 * @param startx: starting position
 * @param starty: starting position
 * @return nothing
 */
Ball::Ball(int startx, int starty) : handler(this, &Ball::OnEvent)
{
	x = startx;
	y = starty;

}
/**
 * Draw
 * @param context: draw the ball in a location
 * @return nothing
 */
void Ball::Draw()
{
	AEGfxCircle(x,y, rad, AE_COLORS_WHITE);
}
/**
 * Update
 * @param context: update the position of
 * ball each frame
 * @return nothing
 */
void Ball::Update()
{
	x += xvel * AEGetFrameTime();
	y += yvel * AEGetFrameTime();
}
/**
 * Getx
 * @param context: gettor for x
 * @return the x position
 */
int Ball::Getx()
{
	return x;
}
/**
 * Gety
 * @param context: gettor for y
 * @return the y position
 */
int Ball::Gety()
{
	return y;
}
/**
 * OnEvent
 * @param context: for each time the manager call and 
 * event handle all types of events
 * @param coll: the type of collision event
 * @return nothing
 */
void Ball::OnEvent(CollisionEvent* coll)
{
	if (coll->type == "RightWall")
	{
		this->xvel = -xvel;
	}
	if (coll->type == "LeftWall")
	{
		this->xvel = -xvel;
	}
	if (coll->type == "TopWall")
	{
		this->yvel = -yvel;
	}
	if (coll->type == "DownWall")
	{
		this->yvel = -yvel;
	}
	if (coll->type == "PlayerToBall")
	{
		if (this->x < 50)
		{
			this->yvel = yvel;
			this->xvel = -xvel;
			return;
		}
		this->yvel = -yvel;
		this->xvel = -xvel;
	}
	if (coll->type == "CPUToBall")
	{

		this->yvel = -yvel;
		this->xvel = -xvel;
	}
}
/**
 * getRad
 * @param context: gettor of the radius
 * @return the radius
 */
int Ball::getRad()
{
	return rad;
}
