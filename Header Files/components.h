#pragma once

struct Position
{
	Position() : X{ 0.f }, Y{ 0.f } {};
	Position(float XX, float YY) : X{ XX }, Y{ YY } {};
	float X = 0.f;
	float Y = 0.f;
};