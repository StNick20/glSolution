#pragma once

#include "core.h"

/// <summary>
/// Draws a polygon
/// </summary>
/// <param name="_x">center point x</param>
/// <param name="_y">center point y</param>
/// <param name="_sides">number of sides the shape will have</param>
/// <param name="radius">radius of shape</param>
void drawPolygon(float _x, float _y, int _sides, float _radius);

/// <summary>
/// Draws a star
/// </summary>
/// <param name="_x">center point x</param>
/// <param name="_y">center point y</param>
void drawStar(float _x, float _y);

/// <summary>
/// draws a tank
/// </summary>
/// <param name="_x">center point x</param>
/// <param name="_y">center point y</param>
void drawTank(float _x, float _y);

void drawSemiCircleStudio();

void drawQuads();