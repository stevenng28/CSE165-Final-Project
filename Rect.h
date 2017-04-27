#ifndef RECT_H
#define RECT_H

class Rect {
	int value; //, width;
	float red, green, blue;
public:
	Rect(int val = 1, float r = 0, float g = 0, float b = 0);

	int getValue() { return value; }
	int getRed() { return red; }
	int getGreen() { return green; }
	int getBlue() { return blue; }

	void setValue(int val);
	void setColors(float r = 0, float g = 0, float b = 0);

	//Operators to compare via value
	bool operator==(const Rect &r2) { return (this->value == r2.value); }
	bool operator!=(const Rect &r2) { return !(this->value == r2.value); }

	bool operator< (const Rect &r2) { return (this->value < r2.value); }
	bool operator>= (const Rect &r2) { return !(this->value < r2.value); }

	bool operator> (const Rect &r2) { return (this->value > r2.value); }
	bool operator<= (const Rect &r2) { return !(this->value > r2.value); }

};

#endif
