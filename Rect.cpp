#include "Rect.h"

Rect::Rect(int val, float r, float g, float b) {
	value = val;
	red = r;
	green = g;
	blue = b;
}

void Rect::setValue(int val) {
	value = val;
}

void Rect::setColors(float r, float g, float b) {
	red = r;
	green = g;
	blue = b;
}