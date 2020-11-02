#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics &gfx);
	void DrawCell(const Location &loc, Color c);
	int GetWidth();
	int GetHeight();
	bool isInsideBoard(Location& loc);
private:
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	Graphics &gfx;//creating a cache ,hence recreating the refference wont be done
};
