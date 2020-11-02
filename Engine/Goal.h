#pragma once
#include"Graphics.h"
#include "Location.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal {
public:
	Goal(std::mt19937& rng, Board& brd,  Snake& snake);
	void Respawn(std::mt19937& rng, Board& brd, Snake& snake);
	void Draw(Board&brd);
	const Location& GetLocation()const;

private:
	static constexpr Color c = Colors::Red;
	Location loc;
};
