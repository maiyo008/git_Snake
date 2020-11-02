#pragma once

class Location
{
	public:
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	/*We can define operators for objects as shown below*/
	bool operator ==(const Location& rhs)const
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};