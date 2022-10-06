#pragma once
#include "components.h"

class Shot
{
public:
	Shot(float startingX, float startingY, float speed, float destructionPower)
	{
		BulletPosition.X = startingX;
		BulletPosition.Y = startingY;
		Speed = speed;
		DestructionPower = destructionPower;
	}

	void UpdateBulletPosition();

	Position BulletPosition = Position(0, 0);
private:

	float Speed = 2.f;
	float DestructionPower = 40.f;
};

