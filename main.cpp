#include <iostream>
#include "rlutil.h"
#include "spaceship.h"
#include "shot.h"
#include <conio.h>

void DebugPlayerPosition(Spaceship*);

int main()
{
	const int ScreenRows = 16;
	const int ScreenColumns = 32;

	char PlayerInput = 'R';

	Spaceship* PlayerSpaceship = new Spaceship(1, 1, 1);

	while (true)
	{
		DebugPlayerPosition(PlayerSpaceship);

		for (int row = 0; row < ScreenRows; ++row)
		{
			for (int column = 0; column < ScreenColumns; ++column)
			{
				// Draw Screen edges
				if (row == 0 || row == ScreenRows - 1)
				{
					rlutil::setColor(3);
					std::cout << ".";
					rlutil::setColor(7);
				}
				else if (column == 0 || column == ScreenColumns - 1)
				{
					rlutil::setColor(3);
					std::cout << ".";
					rlutil::setColor(7);
				}
				else
				{
					if (PlayerSpaceship == nullptr) { return -1; }

					// Whether or not is something drawn at this node [row][column]
					bool IsNodeDrawn = false;

					// Get player position
					int PlayerX, PlayerY;
					PlayerSpaceship->GetPlayerPosition(&PlayerX, &PlayerY);

					// Get fired bullets
					std::list<Shot*> BulletsFiredList = PlayerSpaceship->GetSpaceshipGun()->GetBulletsFiredList();
					
					// Draw bullets
					if (BulletsFiredList.size() > 0)
					{
						for (auto Bullet : BulletsFiredList)
						{
							if (Bullet->BulletPosition.X == column &&
								Bullet->BulletPosition.Y == row && 
								!IsNodeDrawn)
							{
								rlutil::setColor(9);
								std::cout << "x";
								rlutil::setColor(7);

								IsNodeDrawn = true;

								// Update bullet position but will only be drawn on next frame
								if (Bullet->BulletPosition.Y > 0)
								{
									Bullet->UpdateBulletPosition();
								}
								else
								{
									BulletsFiredList.remove(Bullet);
								}
							}
						}
					}

					// Draw player
					if (PlayerX == column && PlayerY == row)
					{
						rlutil::setColor(5);
						std::cout << "X";
						rlutil::setColor(7);

						IsNodeDrawn = true;
					}
					else
					{
						if (IsNodeDrawn) { continue; }
						std::cout << " ";
					}
				}
			}
			std::cout << std::endl;
		}

		// Get Player input and move accordingly
		PlayerInput = _getch();
		PlayerSpaceship->ReadUserInput(PlayerInput);

		// Clamp ship to game screen
		PlayerSpaceship->ClampShipToGameScreen(ScreenRows, ScreenColumns);

		system("cls");
	}
	return 0;
}

void DebugPlayerPosition(Spaceship* PlayerSpaceship)
{
	if (PlayerSpaceship == nullptr) { return; }

	// Debug player position
	rlutil::setColor(4);
	std::cout << "X: ";
	rlutil::setColor(7);
	std::cout << PlayerSpaceship->SpaceshipPosition.X;
	rlutil::setColor(2);
	std::cout << " Y: ";
	rlutil::setColor(7);
	std::cout << PlayerSpaceship->SpaceshipPosition.Y;
	rlutil::setColor(6);
	std::cout << " Bullets: ";
	rlutil::setColor(7);
	std::cout << PlayerSpaceship->GetSpaceshipGun()->GetCurrentBullets() << std::endl;
}


