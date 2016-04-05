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
	QGraphicsRectItem *testRect1 = new QGraphicsRectItem();
	testRect1->setRect(450, 40, 100, 100);
	gameScene->addItem(testRect1);

	QGraphicsRectItem *testRect2 = new QGraphicsRectItem();
	testRect2->setRect(2000, 1500, 120, 60);
	gameScene->addItem(testRect2);

}