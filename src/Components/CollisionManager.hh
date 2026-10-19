#include "../Framework/event.hh"
#include "../Framework/event_handlers.hh"
#include "../Framework/component.hh"
class CollisionEventManager : public EventManager
{
	public:
		void update() override;

};
