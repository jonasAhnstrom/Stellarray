#include <QGraphicsItem>

#include "Course.h"


Course::Course()
{
}


Course::~Course()
{
}

// TODO: rect is not added to scene
void Course::createCourse(int courseNumber, QGraphicsScene *gameScene)
{
	QGraphicsRectItem *testRect = new QGraphicsRectItem();
	testRect->setRect(20, 20, 100, 100);
	gameScene->addItem(testRect);
}