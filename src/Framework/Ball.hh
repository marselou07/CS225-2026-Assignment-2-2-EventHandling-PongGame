#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/entity.hh"
#include <AEEngine.h>

class Component;

class Ball : public Entity
{
	int x = 0;
	int y = 0;

	int rad = 20;

	int xvel = 200;
	int yvel = 200;
public:
	~Ball();
	void Draw() override;
	void Update() override;

};