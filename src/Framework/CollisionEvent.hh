#pragma once
#include "event.hh"
#include <string>
class CollisionEvent : public Event
{
	public:
	std::string type;
	CollisionEvent(const std::string& e): type(e)
	{}

};