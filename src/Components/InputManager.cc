#include "InputManager.hh"
/******************************************************************************
filename    InputManager.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: The program will handle each case of the input
for the player
******************************************************************************/
/**
 * update
 * @param context: when an specific key is triggered
 * use the notifyEvent to send the message to all objects
 * subscribed
 * @return nothing
 */
void InputEventManager::update()
{
	if (AEInputKeyPressed('W'))
	{
		InputEvent* event = new InputEvent("UP");
		this->notifyEvent(event);
	}
	if (AEInputKeyPressed('S'))
	{
		InputEvent* event = new InputEvent("DOWN");
		this->notifyEvent(event);
	}
}
