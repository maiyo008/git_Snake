#include "Snake.h"
#include<assert.h>
#include<math.h>

void Snake::Segment::init_Head(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::init_Body()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::Moveby(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation()const
{
	return loc;
}

Snake::Snake(const Location & loc)
{
	segments[0].init_Head(loc);
}

void Snake::Moveby(const Location & Delta_loc)
{
	for (int i = nsegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].Moveby(Delta_loc);
}

Location Snake::GetHeadNextLocation(const Location delta_loc) 
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nsegments < nMaxSegments)
	{
		segments[nsegments].init_Body();
		nsegments++;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nsegments; i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::IsInsideTileExceptLast(const Location & target)
{
	for (int i = 0; i < nsegments-1; i++)//nsegments - 1 will enable the check for tiles except for the last one
	{
		if (segments[i].GetLocation()==target)
		{
			return true;
		}
	}
	return false;
}
bool Snake::IsInsideTile(const Location & target)
{
	for (int i = 0; i < nsegments; i++) 
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}
