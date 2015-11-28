#include "Arrows.h"
#include "Constants.h"

void iniArrow(RectangleShape & Arrow, TypeArrow type)
{
	switch (type)
	{
	case SECOND:
		Arrow.setSize(Vector2f(2.f, 125.f));
		Arrow.setOrigin(1.f, 100.f);
		Arrow.setPosition(150.f, 150.f);
		Arrow.setFillColor(Color::Red);
		break;
	case MINUTE:
		Arrow.setSize(Vector2f(3.f, 100.f));
		Arrow.setOrigin(1.5f, 95.f);
		Arrow.setPosition(150.f, 150.f);
		Arrow.setFillColor(Color(150, 150, 150));
		break;
	case HOUR:
		Arrow.setSize(Vector2f(4.f, 75.f));
		Arrow.setOrigin(2.f, 70.f);
		Arrow.setPosition(150.f, 150.f);
		Arrow.setFillColor(Color(100, 100, 100));
		break;
	}
}

void iniArrows(Arrows & arrows)
{
	arrows.MinuteArrow = new RectangleShape;
	arrows.SecondArrow = new RectangleShape;
	arrows.HourArrow = new RectangleShape;
	iniArrow(*arrows.MinuteArrow, MINUTE);
	iniArrow(*arrows.SecondArrow, SECOND);
	iniArrow(*arrows.HourArrow, HOUR);
}


void rotateArrow(RectangleShape & Arrow, float coef, WORD time)
{
	Arrow.setRotation(time*coef);
}

void update(Arrows & arrows, SYSTEMTIME & currTime)
{
	rotateArrow(*arrows.SecondArrow, COEF_SECOND, currTime.wSecond);
	rotateArrow(*arrows.MinuteArrow, COEF_MINUTE, currTime.wMinute);
	rotateArrow(*arrows.HourArrow, COEF_HOUR, currTime.wHour);
}

void dispArrow(Arrows & arrows)
{
	delete(arrows.HourArrow);
	delete(arrows.MinuteArrow);
	delete(arrows.SecondArrow);
}
