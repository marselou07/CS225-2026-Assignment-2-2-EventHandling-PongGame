#pragma once
#include "event.hh"
#include <string>
/******************************************************************************
filename    CollisionEvent.hh
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: The event type that will handle the collisions
******************************************************************************/
class CollisionEvent : public Event
{
	public:
	std::string type;
	CollisionEvent(const std::string& e): type(e)
	{}

};