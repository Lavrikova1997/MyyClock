#include "Constants.h"
#include "Clock.h"

const float RADIUS_COMMON_POINT = 1.f;
const float RADIUS_HOUR_POINT = 3.f;
const float ROTATE_ANGLE = 6.f;
const float RADIUS_CIRCLE = 130.f;

void iniClock(MyClock & clock)
{
	iniArrows(clock.arrows);
	clock.CentralPoint = new CircleShape(3.f);
	clock.CentralPoint->setOrigin(3.f, 3.f);
	clock.CentralPoint->setPosition(CENTER_CLOCK, CENTER_CLOCK);
}

void dispClock(MyClock & clock) 
{
	dispArrow(clock.arrows);
	delete(clock.CentralPoint);
}

void updateClock(MyClock & clock, SYSTEMTIME & currTime)
{
	update(clock.arrows, currTime);
}

void drawCirclePoint(RenderWindow & window)
{	
	CircleShape DrawerPoint(RADIUS_COMMON_POINT);
	DrawerPoint.setFillColor(Color(150, 150, 150));
	for (int i = 0; i < 60; i++)
	{
		if (i % 5 == 0)
		{
			DrawerPoint.setRadius(RADIUS_HOUR_POINT);
			DrawerPoint.setOrigin(RADIUS_HOUR_POINT, RADIUS_CIRCLE);
			DrawerPoint.setPosition(CENTER_CLOCK, CENTER_CLOCK);
		}
		else
		{
			DrawerPoint.setRadius(RADIUS_COMMON_POINT);
			DrawerPoint.setOrigin(RADIUS_COMMON_POINT, RADIUS_CIRCLE);
			DrawerPoint.setPosition(CENTER_CLOCK, CENTER_CLOCK);
		}
		DrawerPoint.setRotation(i*ROTATE_ANGLE);
		window.draw(DrawerPoint);
	}
}

void drawClock(RenderWindow & window, MyClock & clock)
{
	drawCirclePoint(window);
	window.draw(*(clock.arrows.HourArrow));
	window.draw(*(clock.arrows.MinuteArrow));
	window.draw(*(clock.arrows.SecondArrow));
	window.draw(*clock.CentralPoint);
}