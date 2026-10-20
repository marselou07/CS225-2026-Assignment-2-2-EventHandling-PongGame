#include "CPU.hh"
CPU::~CPU()
{
}

CPU::CPU(int startx, int starty, Ball* b):coll_handler(this, &CPU::OnHitEvent), ballseen(b)
{
	x = startx;
	y = starty;
}

void CPU::Draw()
{
	AEGfxRect(x, y, 0, xscale, yscale, AE_COLORS_WHITE);
}

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

int CPU::Getx_()
{
	return x;
}

int CPU::Gety_()
{
	return x;
}

int CPU::getScaleX()
{
	return xscale;
}

int CPU::getScaleY()
{
	return yscale;
}
void CPU::OnHitEvent(CollisionEvent* coll)
{
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
	if (coll->type == "CPUToBall")
	{
		seing = false;
	}

}

