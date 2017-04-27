#pragma once

#include <iostream>
#include <vector>
#include "GlutApp.h"
#include "Rect.h"

using namespace std;


#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
	float x, y, width, height; //Pixels
	int index;
public:
	int size;
	vector<vector<Rect>> rects;

	Display(float ix = -0.75f, float iy = -0.75f, float w = 1.50f, float h = 1.0f);

	int getX() { return x; }
	int getY() { return y; }
	int getWidth() { return width; }
	int getHeight() { return height; }

	//Push states in for animation, use these during algorithm
	void rectPush(vector<Rect> rect);
	void arrayPush(int arr[], int size);

	//Advance and rewind through states
	void forward();
	void backward();

	//Draw current state
	void draw();
};

#endif