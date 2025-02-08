#include "core.h"
#include "MyShapes.h"


void drawStar(float _x, float _y)
{
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0.0 + _x, 0.0 + _y);

	glVertex2f(0.0 + _x, 2.5 + _y);
	glVertex2f(1.0 + _x, 1.0 + _y);
	glVertex2f(2.5 + _x, 0.8 + _y);
	glVertex2f(1.5 + _x, -0.5 + _y);
	glVertex2f(2.5 + _x, -2.5 + _y);
	glVertex2f(0.0 + _x, -1.25 + _y);
	glVertex2f(-2.5 + _x, -2.5 + _y);
	glVertex2f(-1.5 + _x, -0.5 + _y);
	glVertex2f(-2.5 + _x, 0.8 + _y);
	glVertex2f(-1.0 + _x, 1.0 + _y);
	glVertex2f(0.0 + _x, 2.5 + _y);
	glEnd();
}

void drawPolygon(float _x, float _y, int _sides, float radius)
{

	if (_sides > 2)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i < _sides; i++)
		{
			float angle = 2.0f * 3.14 * i / _sides;
			float x = _x + radius * cos(angle);
			float y = _y + radius * sin(angle);
			glVertex2f(x, y);
		}
		glEnd();
	}


}

void drawTank(float _x, float _y)
{
	glBegin(GL_LINE_LOOP);

	glVertex2f(-0.85 + _x, 0.5 + _y);
	glVertex2f(0.85 + _x, 0.5 + _y);
	glVertex2f(0.85 + _x, -0.5 + _y);
	glVertex2f(-0.85 + _x, -0.5 + _y);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2f(-0.6 + _x, 0.4 + _y);
	glVertex2f(0.6 + _x, 0.0 + _y);
	glVertex2f(-0.6 + _x, -0.4 + _y);

	glEnd();
}

void drawQuads()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	glBegin(GL_QUADS);
	glColor4ub(255, 0, 0, 128);
	glVertex2f(-5.0, 6.0);
	glVertex2d(5.0, 6.0);
	glVertex2f(5.0, -2.0);
	glVertex2f(-5.0, -2.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4ub(0, 255, 0, 128);
	glVertex2f(-9.0, 2.0);
	glVertex2f(1.0, 2.0);
	glVertex2f(1.0, -6.0);
	glVertex2f(-9.0, -6.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4ub(0, 0, 255, 128);
	glVertex2f(-1.0, 2.0);
	glVertex2f(9.0, 2.0);
	glVertex2f(9.0, -6.0);
	glVertex2f(-1.0, -6.0);
	glEnd();

	glDisable(GL_BLEND);
}

void drawSemiCircleStudio()
{

	glShadeModel(GL_FLAT);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3ub(255, 0, 0);
	glVertex2f(-2.5f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(-7.5f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(-2.16506351f, 1.25f);

	glColor3ub(255, 0, 0);
	glVertex2f(-6.49519053f, 3.75f);

	glColor3ub(255, 255, 0);
	glVertex2f(-1.25, 2.16506351f);

	glColor3ub(255, 255, 0);
	glVertex2f(-3.75f, 6.49519053f);

	glColor3ub(0, 255, 0);
	glVertex2f(0.0f, 2.5f);

	glColor3ub(0, 255, 0);
	glVertex2f(0.0f, 7.5f);

	glColor3ub(0, 255, 255);
	glVertex2f(1.25f, 2.16506351f);

	glColor3ub(0, 255, 255);
	glVertex2f(3.75f, 6.49519053f);

	glColor3ub(0, 0, 255);
	glVertex2f(2.16506351f, 1.25f);

	glColor3ub(0, 0, 255);
	glVertex2f(6.49519053f, 3.75f);

	glColor3ub(255, 0, 255);
	glVertex2f(2.5f, 0.0f);

	glColor3ub(255, 0, 255);
	glVertex2f(7.5f, 0.0f);

	glEnd();
}

void spiral(float _x, float _y, float angleStep)
{
	glBegin(GL_LINE_STRIP);

	float x, y;
	float angle = 0;
	float radius = 0.1;

	while (angle < 15 * 3.14)
	{
		x = _x + radius * cos(angle);
		y = _y + radius * sin(angle);
		glVertex2f(x, y);

		angle += angleStep;
		radius += 0.01;
	}

	glEnd();
}