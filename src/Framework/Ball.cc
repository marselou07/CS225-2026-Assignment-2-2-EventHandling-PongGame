#include"Ball.hh"

Ball::~Ball()
{
}

Ball::Ball(int startx, int starty) : handler(this, &Ball::OnEvent)
{
	x = startx;
	y = starty;

}

void Ball::Draw()
{
	AEGfxCircle(x,y, rad, AE_COLORS_WHITE);
}

void Ball::Update()
{
	x += xvel * AEGetFrameTime();
	y += yvel * AEGetFrameTime();
}

int Ball::Getx()
{
	return x;
}

int Ball::Gety()
{
	return y;
}

void Ball::OnEvent(CollisionEvent* coll)
{
	if (coll->type == "RightWall")
	{
		this->xvel = -xvel;
	}
	if (coll->type == "LeftWall")
	{
		this->xvel = -xvel;
	}
	if (coll->type == "TopWall")
	{
		this->yvel = -yvel;
	}
	if (coll->type == "DownWall")
	{
		this->yvel = -yvel;
	}
	if (coll->type == "PlayerToBall")
	{
		if (this->x < 50)
		{
			this->yvel = yvel;
			this->xvel = -xvel;
			return;
		}
		this->yvel = -yvel;
		this->xvel = -xvel;
	}
	if (coll->type == "CPUToBall")
	{
		if (this->x > -50)
		{
			this->yvel = yvel;
			this->xvel = -xvel;
			return;
		}
		this->yvel = -yvel;
		this->xvel = -xvel;
	}
}

int Ball::getRad()
{
	return rad;
}
