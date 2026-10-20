#pragma once
#include "event.hh"
#include <string>
class InputEvent : public Event
{
	public:
	std::string type;
	InputEvent(const std::string& e) : type(e)
	{}
};