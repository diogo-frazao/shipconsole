#pragma once
#include <iostream>
#include "gun.h"
#include "components.h"

class Spaceship
{
public:
	Spaceship(float startingX, float startingY, float speed)
	{
		SpaceshipPosition.X = startingX;
		SpaceshipPosition.Y = startingY;
		Speed = speed;
	}

	Position SpaceshipPosition = Position(0, 0);
	void ClampShipToGameScreen(int MaxRows, int MaxColumns);
	void ReadUserInput(char InputString);

private:
	Gun* SpaceShipGun = new Gun(4, 1.f);
	float Speed = 1.f;

public:
	float GetSpeed() const { return Speed; }
	Gun* GetSpaceshipGun() const { return SpaceShipGun; }
	void GetPlayerPosition(int* X, int* Y);
};

