#include "Game.h"

#include <qdebug.h>


Game::Game(QWidget *parent)
{
	_gameScene.setSceneRect(QRectF(0, 0, 4000, 2980));
	_gameScene.setItemIndexMethod(QGraphicsScene::NoIndex);
	_gameScene.setBackgroundBrush(QBrush(QPixmap("Resources/bg3.png")));
	
	_gameCourse.createCourse(/*courseNumber*/ 1, &_gameScene);

	_gameScene.addItem(&_player);

	setScene(&_gameScene);
	setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	setFixedSize(1400, 900);
	QTimer *gameTimer = new QTimer;
	connect(gameTimer, SIGNAL(timeout()), &_gameScene, SLOT(advance()));
	connect(gameTimer, SIGNAL(timeout()), this, SLOT(update()));
	gameTimer->start(1);

	// TODO: Creator class that handles creation of game objects (bullets, enemies), maybee this class
	connect(&_player, SIGNAL(bullet(QPoint, qreal)), this, SLOT(newBullet(QPoint, qreal)));
}


Game::~Game()
{
}

// Called from stellarray
void Game::keyPress(QKeyEvent *event)
{
	_player.update(event);
	//update();
}

// Called from stellarray
void Game::keyRelease(QKeyEvent *event)
{
	_player.update(event);
	//update();
}


void Game::update()
{
	centerOn(_player.x() + _player.boundingRect().width() / 2, _player.y() + _player.boundingRect().height() / 2);
}

// TODO: Add rotation for bullet
void Game::newBullet(QPoint bulletPos, qreal angle)
{
	while (_bulletTimer.hasExpired(100))
	{
		Bullet *nb = new Bullet(bulletPos, angle, &_player);
		_bullets.push_back(nb);
		_gameScene.addItem(nb);
		_bulletTimer.restart();
	}

	/*_bulletTimer = new QElapsedTimer();
	qDebug() << _bulletTimer->elapsed();
	if (_bulletTimer->elapsed() < 50)
	/*{
		
		_bulletTimer->restart();
	}*/
}
