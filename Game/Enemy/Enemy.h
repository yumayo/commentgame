#pragma once
#include "../Object/Object.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(Vec2f _pos, Vec2f _size);
	~Enemy();
	void update() override;
	void draw() override;

private:

};





