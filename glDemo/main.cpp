#include "core.h"
#include "MyShapes.h"
#include <thread>
#include <chrono>

// global variables

// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

// Function prototypes
void renderScene();
void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();

//randoms
float randomFloat();
int randomSides();
int randomPoint();
float randomRadius();
int randomShape();
void randomFill();



int main() {

	//
	// 1. Initialisation
	//
	srand(time(NULL));

	// Initialise glfw and setup window
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "Real-Time Computer Graphics", NULL, NULL);

	// Check window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// Set callback functions to handle different events
	glfwSetFramebufferSizeCallback(window, resizeWindow); // resize window callback
	glfwSetKeyCallback(window, keyboardHandler); // Keyboard input callback


	// Initialise glew
	glewInit();

	
	// Setup window's initial size
	resizeWindow(window, initWidth, initHeight);

	// Initialise scene - geometry and shaders etc
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // setup background colour to be black

	gluOrtho2D(-10.00, 10.00, -10.00, 10.00);

	//
	// 2. Main loop
	// 
	

	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

		updateScene();
		renderScene();						// Render into the current buffer
		glfwSwapBuffers(window);			// Displays what was just rendered (using double buffering).

		// Poll events (key presses, mouse events)
		// glfwWaitEvents();				// Use this if no animation.
		// glfwWaitEventsTimeout(1.0/60.0);	// Use this to animate at 60 frames/sec (timing is NOT reliable)
		glfwPollEvents();					// Use this version when animating as fast as possible
	}

	glfwTerminate();
	return 0;
}



// renderScene - function to render the current scene
void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render objects here...

	/*glBegin(GL_TRIANGLES);
		//triangle one
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(1.0f, 1.0f);
		glVertex2f(1.0f, -1.0f);

		//triangle two
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
		glVertex2f(-1.0f, -1.0f);
	glEnd();*/

	glColor3f(randomFloat(), randomFloat(), randomFloat());



	switch (randomShape())
	{
	case 1:
		randomFill();
		drawStar(randomPoint(), randomPoint());
		break;
	case 2:
		randomFill();
		drawPolygon(randomPoint(), randomPoint(), randomSides(), randomRadius());
		break;
	case 3:
		drawTank(randomPoint(), randomPoint());
		break;
	case 4:
		randomFill();
		drawSemiCircleStudio();
		break;
	case 5:
		randomFill();
		drawQuads();
		break;
	default:
		std::cout << "well this shouldn't be happening :(" << std::endl;
		break;
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

float randomFloat()
{
	return (float)rand() / RAND_MAX;
}

int randomSides()
{
	return rand() % (50 - 3) + 3;
}

int randomPoint()
{
	return rand() % (10 + 10) - 10;
}

float randomRadius()
{
	return rand() % (4 - 1) + 1;
}

int randomShape()
{
	return rand() % 5 + 1;
}

void randomFill()
{
	if (rand() % 2 > 0)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// Function to call when window resized
void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window
}


// Function to call to handle keyboard input
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {

		// check which key was pressed...
		switch (key)
		{
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;

			default:
			{
			}
		}
	}
	else if (action == GLFW_RELEASE) {
		// handle key release events
	}
}


// Function called to animate elements in the scene
void updateScene() {

}







