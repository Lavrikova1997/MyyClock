#pragma once
#include <SFML/Graphics.hpp>
#include "Arrows.h"

typedef struct strClock
{
	Arrows arrows;
	CircleShape * CentralPoint;
}MyClock;

void iniClock(MyClock & clock);

void dispClock(MyClock & clock);

void updateClock(MyClock & clock, SYSTEMTIME & currTime);

void drawCirclePoint(RenderWindow & window);

void drawClock(RenderWindow & window, MyClock & clock);