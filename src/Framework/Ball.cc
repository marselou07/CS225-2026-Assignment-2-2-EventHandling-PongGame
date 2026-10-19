#include"Ball.hh"

Ball::~Ball()
{
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
