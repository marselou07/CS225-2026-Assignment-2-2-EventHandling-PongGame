#include "Player.hh"
Player::~Player()
{
}

Player::Player(int startx, int starty): coll_handler(this, &Player::OnEvent)
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

void Player::OnEvent(CollisionEvent* coll)
{

}
