#pragma once

#include <QGraphicsScene>


class Course
{
public:
	Course();
	~Course();

	void createCourse(int courseNumber, QGraphicsScene *gameScene);
};

