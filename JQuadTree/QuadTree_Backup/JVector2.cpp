#include"JVector2.h"

JVector2::JVector2(float fX, float fY){
	this->x = fX;
	this->y = fY;
}

JVector2 JVector2::operator + (JVector2 pos){
	JVector2 ret;
	ret.x = this->x + pos.x;
	ret.y = this->y + pos.y;
	return ret;
}

JVector2 JVector2::operator += (JVector2 pos){
	this->x += pos.x;
	this->y += pos.y;
	return *this;
}

JVector2 JVector2::operator - (JVector2 pos){
	JVector2 ret;
	ret.x = this->x - pos.x;
	ret.y = this->y - pos.y;
	return ret;
}

JVector2 JVector2::operator*(float t)
{
	JVector2 ret;
	ret.x = this->x * t;
	ret.y = this->y * t;
	return ret;
}

float JVector2::operator | (JVector2 pos){
	return (this->x * pos.x) + (this->y + pos.y);
}





JRact::JRact() {
	p0 = JVector2(0, 0);
	p1 = JVector2(0, 0);
	wh = JVector2(0, 0);
}
