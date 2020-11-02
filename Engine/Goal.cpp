#include "Goal.h"

Goal::Goal(std::mt19937 & rng,  Board & brd, Snake & snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937 & rng,  Board & brd,  Snake & snake)
{
	std::uniform_int_distribution<int>xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int>yDist(0, brd.GetHeight() - 1);

	Location newLoc;

	do {
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInsideTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
