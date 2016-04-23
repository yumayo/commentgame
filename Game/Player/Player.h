#pragma once
#include "../Object/Object.h"


class Player : public GameObject
{
public:
	Player(Vec2f _pos, Vec2f _size);
	~Player();
	void draw() override;
	void update() override;

private:

};

