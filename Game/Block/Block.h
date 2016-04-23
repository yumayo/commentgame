#pragma once

#include "../AppEnv.h"
#include "../Object/Object.h"

class BlockBase : public GameObject
{
public:
	BlockBase(Vec2f _pos, Vec2f _size) : GameObject(_pos, _size) 
	{

	}
	void update() override;
	void draw() override;

};