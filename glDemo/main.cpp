#include "core.h"
#include "MyShapes.h"

using namespace std;
// global variables
mt19937 engine;
uniform_real_distribution<float> pointPositionRandom;
uniform_real_distribution<float> pointSizeRandom;
uniform_real_distribution<float> pointColourRandom;

vector<glm::vec2> vertexCoords;
vector<float> pointSize;
vector<glm::vec4> pointColour;


// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

const int pointAmount = 1000;

// Function prototypes
void renderScene();
void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();

//randoms
float randomFloat();
int randomSides();
float randomRadius();
void randomShape();
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

	random_device rd;
	engine = mt19937(rd());
	pointPositionRandom = uniform_real_distribution<float>(-10.0f, 10.0f);
	pointColourRandom = uniform_real_distribution<float>(0.0f, 1.0f);
	pointSizeRandom = uniform_real_distribution<float>(1.0f, 5.0f);

	vertexCoords = vector<glm::vec2>(pointAmount, glm::vec2(0.0, 0.0f));
	pointSize = vector<float>(pointAmount, 0.0f);
	pointColour = vector<glm::vec4>(pointAmount, glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

	for (int i = 0; i < pointAmount; i++)
	{
		float x = pointPositionRandom(engine);
		float y = pointPositionRandom(engine);

		vertexCoords[i] = glm::vec2(x, y);

		float s = pointSizeRandom(engine);
		pointSize[i] = s;

		float r = pointColourRandom(engine) * 255;
		float g = pointColourRandom(engine) * 255;
		float b = pointColourRandom(engine) * 255;
		pointColour[i] = glm::vec4(r, g, b, 255.0f);
	}
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


	for (int i = 0; i < pointAmount; i++)
	{
		glPointSize(pointSize[i]);
		// Render objects here...
		glColor3ub(pointColour[i].r, pointColour[i].g, pointColour[i].b);

		glBegin(GL_POINTS);

		glVertex2f(vertexCoords[i].x, vertexCoords[i].y);

		glEnd();
	}
	//randomShape();
}

float randomFloat()
{
	return (float)rand() / RAND_MAX;
}

int randomSides()
{
	return rand() % (50 - 3) + 3;
}

float randomRadius()
{
	return rand() % (4 - 1) + 1;
}

void randomShape()
{

	glColor3f(randomFloat(), randomFloat(), randomFloat());

	switch (rand() % 6 + 1)
	{
	case 1:
		randomFill();
		drawStar(pointPositionRandom(engine), pointPositionRandom(engine));
		break;
	case 2:
		randomFill();
		drawPolygon(pointPositionRandom(engine), pointPositionRandom(engine), randomSides(), randomRadius());
		break;
	case 3:
		drawTank(pointPositionRandom(engine), pointPositionRandom(engine));
		break;
	case 4:
		randomFill();
		drawSemiCircleStudio();
		break;
	case 5:
		randomFill();
		drawQuads();
		break;
	case 6:
		spiral(pointPositionRandom(engine), pointPositionRandom(engine), (float)(rand() / RAND_MAX) * (0.1f - 0.01f) + 0.01f);
		break;
	default:
		std::cout << "well this shouldn't be happening :(" << std::endl;
		break;
	};

	std::this_thread::sleep_for(std::chrono::milliseconds(250));
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







