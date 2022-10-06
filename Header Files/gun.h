#pragma once
#include <iostream>
#include <list>

class Gun
{
public:
	Gun(int bullets, float timeBetweenShots) : MaxBullets{ bullets }, TimeBetweenShots{ timeBetweenShots } {};

	void ReloadBullets();
	void TryFireBullet(float startingX, float startingY, float speed, float destructionPower);
	void OnBulletFired();

private:
	std::list<class Shot*> BulletsFiredList;	
	int MaxBullets = 4;
	int CurrentBullets = MaxBullets;

	float TimeBetweenShots = 1.f;
	float CurrentTimeBetweenShots = 0.f;
public:
	std::list<Shot*> GetBulletsFiredList() const { return BulletsFiredList; }
	int GetCurrentBullets() const { return CurrentBullets; }
};

