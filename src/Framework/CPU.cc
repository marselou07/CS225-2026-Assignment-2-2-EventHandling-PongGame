#include "CPU.hh"
/******************************************************************************
filename    CPU.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: This probram will create the logic for the cpu
******************************************************************************/
/**
 * CPU
 * @param context: constructor also subscribe to coll manager
 * @param startx: starting position
 * @param starty: starting position
 * @param b: a ball bointer to store its position
 * @return nothing
 */
CPU::CPU(int startx, int starty, Ball* b):coll_handler(this, &CPU::OnHitEvent), ballseen(b)
{
	x = startx;
	y = starty;
}
/**
 * Draw
 * @param context: draw the cpu in the position each frame
 * @return nothing
 */
void CPU::Draw()
{
	AEGfxRect(x, y, 0, xscale, yscale, AE_COLORS_WHITE);
}
/**
 * Update
 * @param context: when the seing is activated
 * get to the same position as the ball current position
 * @return nothing
 */
void CPU::Update()
{
	if (seing == false)
	{
		return;
	}
	if (ballseen->Gety() > y)
	{
		y += yvel * AEGetFrameTime();
	}
	else if (ballseen->Gety() < y)
	{
		y -= yvel * AEGetFrameTime();
	}
	
}
/**
 * Getx_
 * @param context: gettor for x
 * @return the x position
 */
int CPU::Getx_()
{
	return x;
}
/**
 * Gety_
 * @param context: gettor for y
 * @return the y position
 */
int CPU::Gety_()
{
	return x;
}
/**
 * getScaleX
 * @param context: gettor for the scale of x
 * @return the x scale
 */
int CPU::getScaleX()
{
	return xscale;
}
/**
 * getScaleY
 * @param context: gettor for the scale of y
 * @return the y scale
 */
int CPU::getScaleY()
{
	return yscale;
}
/**
 * OnHitEvent
 * @param context: handle the collisions
 * of the cpu
 * @param input:the collision event that tells
 * the type of call
 * @return nothing
 */
void CPU::OnHitEvent(CollisionEvent* coll)
{
	//For some collisions
	//set the seing bool to false to 
	//Stop looking at the ball
	if (coll->type == "CPUToBall")
	{
		seing = false;
	}
	if (coll->type == "RightWall")
	{
		seing = false;
	}
	if (coll->type == "LeftWall")
	{
		seing = false;
	}
	if (coll->type == "PlayerToBall")
	{
		seing = true;

	}
}

