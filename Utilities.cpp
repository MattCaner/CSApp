#pragma once
#include "Utilities.h"
#include<cmath>

v2d v2d::operator+(const v2d& v) const {
	return v2d(x + v.x, y + v.y);
}
v2d v2d::operator-(const v2d& v) const {
	return v2d(x - v.x, y - v.y);
}
v2d v2d::operator*(float f) const {
	return v2d(x * f, y * f);
}

float v2d::CartesianLenght() const {
	return sqrtf(x * x + y * y);
}



v2di v2di::operator+(const v2di& v) const {
	return v2di(x + v.x, y + v.y);
}
v2di v2di::operator-(const v2di& v) const {
	return v2di(x - v.x, y - v.y);
}
v2di v2di::operator*(int i) const {
	return v2di(x * i, y * i);
}

float v2di::CartesianLenght() const {
	return sqrtf((float)x * x + (float)y * y);
}
