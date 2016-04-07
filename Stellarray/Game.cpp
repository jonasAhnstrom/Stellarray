#include "Game.h"

#include <QtOpenGL\qgl.h>


Game::Game()
{
	_gameScene.setSceneRect(QRectF(0, 0, 4000, 2980));
	_gameScene.setItemIndexMethod(QGraphicsScene::NoIndex);
	_gameScene.setBackgroundBrush(QBrush(QPixmap("Resources/bg.png")));

	_gameCourse.createCourse(/*courseNumber*/ 1, &_gameScene);

	_gameScene.addItem(&_player);

	_gameView.setScene(&_gameScene);
	_gameView.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	_gameView.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	_gameView.setFixedSize(1400, 900);

	QTimer *timer = new QTimer;
	connect(timer, SIGNAL(timeout()), &_gameScene, SLOT(advance()));
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start((int)(1000 / 16,5));
}


Game::~Game()
{
}


void Game::update()
{
	_gameView.centerOn(_player.x() + _player.boundingRect().width() / 2, _player.y() + _player.boundingRect().height() / 2);
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