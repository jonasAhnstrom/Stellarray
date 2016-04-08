#pragma once

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Course.h"
#include "Player.h"
#include "Bullet.h"

#include <vector>

class Game : public QGraphicsView
{
	Q_OBJECT

public:
	Game(QWidget *parent = 0);
	~Game();

	void keyPress(QKeyEvent *event);
	void keyRelease(QKeyEvent *event);

private:
	QGraphicsScene _gameScene;
	//QGraphicsView _gameView;
	Course _gameCourse;
	Player _player;
	std::vector<Bullet*> _bullets;
	QElapsedTimer _bulletTimer;

/*	enum Key{
		bool Key_W = 0;
	};*/

	friend class Stellarray;

private slots:
	void update();
	void newBullet(QPoint bulletPos, qreal angle);
};