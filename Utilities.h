#pragma once

struct v2d {
	v2d(float newx, float newy) : x(newx), y(newy) {}
	
	v2d operator+(const v2d& v) const;
	v2d operator-(const v2d& v) const;
	v2d operator*(float f) const;
	float CartesianLenght() const;

	float x;
	float y;
};

struct v2di {
	v2di(int newx, int newy) : x(newx), y(newy) {}

	v2di operator+(const v2di& v) const;
	v2di operator-(const v2di& v) const;
	v2di operator*(int i) const;
	float CartesianLenght() const;

	int x;
	int y;
};
