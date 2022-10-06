#include<cstdio>
#include<iostream>
#include<ctime>
#include "shot.h"
#include "gun.h"

void Gun::ReloadBullets()
{
	CurrentBullets = MaxBullets;
}

void Gun::TryFireBullet(float startingX, float startingY, float speed, float destructionPower)
{
	if (CurrentBullets > 0 && CurrentTimeBetweenShots <= 0)
	{
		Shot* Bullet = new Shot(startingX, startingY, speed, destructionPower);
		if (Bullet == nullptr) { return; }

		BulletsFiredList.push_back(Bullet);

		OnBulletFired();
	}
}

void Gun::OnBulletFired()
{
	CurrentBullets--;
	//TODO delay to shoot 
	CurrentTimeBetweenShots = 0.f;
}
