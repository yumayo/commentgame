#pragma once
#include "../Block/Block.h"
#include "../Block/NormaBlock/NormalBlock.h"
#include <vector>

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw();
	void Load(int);
	Vec2f collision(Vec2f, Vec2f, Vec2f);
	
private:
	Vec2i sell(Vec2f);

	Vec2f block_size;
	std::vector<std::vector<std::shared_ptr<BlockBase>>> block;
};
