#include "Player.hh"
#include "CPU.hh"
/******************************************************************************
filename    Player.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: This probram will create the logic for the player
******************************************************************************/
/**
 * Player
 * @param context: constructor also subscribe to coll and input 
 * managers
 * @param startx: starting position
 * @param starty: starting position
 * @return nothing
 */
Player::Player(int startx, int starty): input_handler(this, &Player::OnEvent),
coll_handler(this,&Player::OnHitEvent)
{
	x = startx;
	y = starty;
}
/**
 * Draw
 * @param context: draw the player in the position each frame
 * @return nothing
 */
void Player::Draw()
{
	AEGfxRect(x,y,0,xscale,yscale, AE_COLORS_WHITE);
}
/**
 * Update
 * @param context: do nothing
 * @return nothing
 */
void Player::Update()
{
	
}
/**
 * Get_x
 * @param context: gettor for x
 * @return the x position
 */
int Player::Get_x()
{
	return x;
}
/**
 * Get_y
 * @param context: gettor for y
 * @return the y position
 */
int Player::Get_y()
{
	return y;
}
/**
 * getXScale
 * @param context: gettor for the scale of x
 * @return the x scale
 */
int Player::getXScale()
{
	return xscale;
}
/**
 * getYScale
 * @param context: gettor for the scale of y
 * @return the y scale
 */
int Player::getYScale()
{
	return yscale;
}
/**
 * OnEvent
 * @param context: handle the inputs for the 
 * player
 * @param input:the input event that tells 
 * the type of call
 * @return nothing
 */
void Player::OnEvent(InputEvent* input)
{
	if (input->type == "UP")
	{
		this->y += yvel * AEGetFrameTime();
	}
	if (input->type == "DOWN")
	{
		this->y -= yvel * AEGetFrameTime();
	}
	
}
/**
 * OnHitEvent
 * @param context: handle the collisions 
 * of the player
 * @param input:the collision event that tells
 * the type of call
 * @return nothing
 */
void Player::OnHitEvent(CollisionEvent* coll)
{
	if (coll->type == "TopWallPlayer")
	{
		y = (int)AEGetSysWindowWidth() / 2 - getYScale();
	}
	if (coll->type == "DownWallPlayer")
	{
		y = -(int)AEGetSysWindowWidth() / 2 + getYScale();
	}
}
