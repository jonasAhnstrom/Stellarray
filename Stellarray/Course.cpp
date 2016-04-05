#include <QGraphicsItem>

#include "Course.h"


Course::Course()
{
}


Course::~Course()
{
}


void Course::createCourse(int courseNumber, QGraphicsScene &gameScene)
{
	QGraphicsRectItem *testRect = new QGraphicsRectItem();
	testRect->setRect(20, 20, 100, 100);
	gameScene.addItem(testRect);
}