#pragma once

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Course.h"
#include "Player.h"


class Game : public QGraphicsView
{
	Q_OBJECT

	friend class Stellarray;

public:
	Game();
	~Game();

	void keyPress(QKeyEvent *event);
	void keyRelease(QKeyEvent *event);

private:
	QGraphicsScene _gameScene;
	QGraphicsView _gameView;
	Course _gameCourse;
	Player _player;
/*

	enum Key{
		bool Key_W = 0;
	};*/

private slots:
	void update();
};