#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void init_Head(const Location& in_loc);
		void init_Body();
		void Follow(const Segment& next);
		void Moveby(const Location& delta_loc);
		void Draw(Board& brd)const;
		const Location& GetLocation()const;//The return type for this function is a refference not value 
	private:
		Location loc;
		Color c;

	};
public:
	Snake(const Location& loc);
	void Moveby(const Location& Delta_loc);
	Location GetHeadNextLocation(const Location delta_loc);
	void Grow();
	void Draw(Board& brd)const;
	bool IsInsideTileExceptLast(const Location& target);//This function checks if the snake would bite itself iin the next header location
	bool IsInsideTile(const Location& target);
private:
	static constexpr Color headColor = Colors::Green;
	static constexpr Color bodyColor = Colors::White;
	static constexpr int nMaxSegments = 100;
	Segment segments[nMaxSegments];
	int nsegments = 1;
};