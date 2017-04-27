#include "Display.h"

Display::Display(float ix, float iy, float w, float h) {
	x = ix;
	y = iy;
	width = w;
	height = h;
	index = 0;
}

void Display::rectPush(vector<Rect> rect) {
	rects.push_back(rect);
}

void Display::arrayPush(int arr[], int size) {
	vector<Rect> rect;
	for (int i = 0; i < size; i++) {
		rect.push_back(Rect(arr[i]));
	}
	rects.push_back(rect);
}

void Display::forward() {
	index++;
	if (index >= rects.size())
		index = rects.size() - 1;
}

void Display::backward() {
	index--;
	if (index < 0)
		index = 0;
}

void Display::draw() {
	//Draw bottom line
	glLineWidth(6);
	glBegin(GL_LINES);

	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x, y);
	glVertex2f(x + width, y);

	glEnd();

	//X Pixel gap between pillars in animation
	float gap = 0.03;
	float xInc = width / 10;
	float yInc = height / 10;
	if (!rects.empty()) {
		xInc = width / rects[index].size();
		yInc = height / rects[index].size();
	}

	glLineWidth(3);
	glColor3f(1.0, 0.0, 0.0);

	for (int i = 0; i < rects[index].size(); i++) {
		glBegin(GL_POLYGON);

		glColor3f(rects[index][i].getRed(), rects[index][i].getGreen(), rects[index][i].getBlue());

		glVertex2f(x + gap + xInc * i, y);
		glVertex2f(x + gap + xInc * i, y + yInc * rects[index][i].getValue());
		glVertex2f(x + xInc * (i + 1) - gap, y + yInc * rects[index][i].getValue());
		glVertex2f(x + xInc * (i + 1) - gap, y);

		glEnd();
	}

	glColor3f(0.0, 0.0, 0.0);

	glEnd();

	cout << "Redrew" << endl;
}