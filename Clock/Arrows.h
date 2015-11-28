#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
using namespace sf;
using namespace std;

typedef enum enumTypeArrow
{
	SECOND,
	MINUTE,
	HOUR
}TypeArrow;

typedef struct strClockArrows
{
	RectangleShape * MinuteArrow;
	RectangleShape * SecondArrow;
	RectangleShape * HourArrow;
}Arrows;

void iniArrows(Arrows & arrows);
void update(Arrows & arrows, SYSTEMTIME & currTime);
void dispArrow(Arrows & arrows);

