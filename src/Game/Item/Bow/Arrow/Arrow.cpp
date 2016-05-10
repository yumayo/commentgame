#include "Arrow.h"


Arrow::Arrow() :
	ItemBase()
{
	//Textures::set("arrow", "res/Texture/Item/arrow.png");
}

Arrow::Arrow(Vec2f _pos, Vec2f _size, Vec2f _vec) :
	ItemBase(ItemID::ARROW, _pos, _size, _vec)
{
	//Textures::set("arrow", "res/Texture/Item/arrow.png");
}

Arrow::~Arrow() {

}

void Arrow::update() {

	move();
}

void Arrow::draw() {
	
	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_pos.x(), cut_pos.y(), cut_size.x(), cut_size.y(), Testures::get("arrow"), Color(color.x(), color.y(), color.z()));

	/*仮置き*/
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::red);
	/*仮置き*/
}

void Arrow::move() {

	pos = vec;
}
