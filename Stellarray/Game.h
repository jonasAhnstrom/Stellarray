#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Course.h"


class Game : public QWidget
{
	friend class Stellarray;

public:
	Game();
	~Game();

private:
	QGraphicsScene _gameScene;
	QGraphicsView _gameView;
	Course _gameCourse;
	//Player _player;
};

