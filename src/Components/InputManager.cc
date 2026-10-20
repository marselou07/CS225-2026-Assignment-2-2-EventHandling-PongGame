#include "InputManager.hh"

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
