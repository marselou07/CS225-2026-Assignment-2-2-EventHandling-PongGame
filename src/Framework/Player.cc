#include "Player.hh"
Player::~Player()
{
}

Player::Player(int startx, int starty): input_handler(this, &Player::OnEvent),
coll_handler(this,&Player::OnHitEvent)
{
	x = startx;
	y = starty;
}

void Player::Draw()
{
	AEGfxRect(x,y,0,xscale,yscale, AE_COLORS_WHITE);
}

void Player::Update()
{
	
}
int Player::Get_x()
{
	return x;
}
int Player::Get_y()
{
	return y;
}
int Player::getXScale()
{
	return xscale;
}

int Player::getYScale()
{
	return yscale;
}

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
