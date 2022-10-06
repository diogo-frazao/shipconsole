#include "spaceship.h"

void Spaceship::ReadUserInput(char InputString)
{
	if (InputString == 'w')
	{
		SpaceshipPosition.Y -= Speed;
	}
	else if (InputString == 's')
	{
		SpaceshipPosition.Y += Speed;
	}
	else if (InputString == 'a')
	{
		SpaceshipPosition.X -= Speed;
	}
	else if (InputString == 'd')
	{
		SpaceshipPosition.X += Speed;
	}
	else if (InputString == 'z')
	{
		if (SpaceShipGun == nullptr) { return; }
		SpaceShipGun->TryFireBullet(SpaceshipPosition.X, SpaceshipPosition.Y - (Speed * 2), 2.f, 3.f);
	}
	else if (InputString == 'r')
	{
		if (SpaceShipGun == nullptr) { return; }
		SpaceShipGun->ReloadBullets();
	}
}

void Spaceship::ClampShipToGameScreen(int MaxRows, int MaxColumns)
{
	if (SpaceshipPosition.X < 1)
	{
		SpaceshipPosition.X = MaxColumns - 2;
	}
	else if (SpaceshipPosition.X > MaxColumns - 2)
	{
		SpaceshipPosition.X = 1;
	}
	if (SpaceshipPosition.Y < 1)
	{
		SpaceshipPosition.Y = MaxRows - 2;
	}
	else if (SpaceshipPosition.Y > MaxRows - 2)
	{
		SpaceshipPosition.Y = 1;
	}
}

void Spaceship::GetPlayerPosition(int* X, int* Y)
{
	*X = SpaceshipPosition.X;
	*Y = SpaceshipPosition.Y;
}