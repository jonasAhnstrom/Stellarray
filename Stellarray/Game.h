#pragma once

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "Course.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <vector>

class Game : public QGraphicsView
{
	Q_OBJECT

public:
	Game(QWidget *parent = 0);
	~Game();

	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	QGraphicsScene _gameScene;
	//QGraphicsView _gameView;
	Course _gameCourse;
	QTimer gameTimer;
	Player _player;
	QList<Bullet*> _bullets;
	QElapsedTimer _bulletTimer;
	QList<Enemy*> _enemys;
	//int _enemys;

	friend class Stellarray;

private slots:
	void update();
	void newBullet(QPoint bulletPos, qreal angle);
	void deleteBullet();
	void deleteEnemy(int enemyId);
};