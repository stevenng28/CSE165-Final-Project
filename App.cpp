#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

	disp = new Display(-0.75f, -0.75f, 1.50f, 1.0f);

	//Shuffles a random vector of 10 values to be sorted
	vector<Rect> rectVector;
	for (int i = 0; i < 10; i++) {
		rectVector.push_back(Rect(i + 1));
	}
	random_shuffle(rectVector.begin(), rectVector.end());

	//Push a few shuffled arrays into display for animation testing, remove later
	for (int i = 0; i < 5; i++) {
		vector<Rect> test;
		for (int i = 0; i < 10; i++) {
			test.push_back(Rect(i + 1));
		}
		random_shuffle(test.begin(), test.end());
		disp->rectPush(test);
	}
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(0, 0, 0);
    
	//Draw display
	disp->draw();

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
	if (key == '+') {
		disp->forward();
		redraw();
	}
	if (key == '-') {
		disp->backward();
		redraw();
	}
}
