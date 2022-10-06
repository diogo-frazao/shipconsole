#include "shot.h"
#include "gun.h"

void Shot::UpdateBulletPosition()
{
	BulletPosition.Y -= Speed;
}
