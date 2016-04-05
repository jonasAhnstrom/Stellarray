#include "Game.h"


Game::Game()
{
	_gameScene.setSceneRect(QRectF(0, 0, 4000, 3000));
	_gameScene.setItemIndexMethod(QGraphicsScene::NoIndex);

	_gameCourse.createCourse(/*courseNumber*/ 1, &_gameScene);

	_gameScene.addItem(&_player);

	_gameView.setScene(&_gameScene);
	_gameView.setRenderHint(QPainter::Antialiasing);
	_gameView.setCacheMode(QGraphicsView::CacheBackground);
	_gameView.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	_gameView.setFixedSize(1200, 800);

	QTimer *timer = new QTimer;
	connect(timer, SIGNAL(timeout()), &_gameScene, SLOT(advance()));
	timer->start((int)(1000 / 16,5));
}


Game::~Game()
{
}


void Game::update()
{
	_gameView.centerOn(_player.x() + _gameView.rect().width() / 5, _player.y());
}


void Game::keyPressEvent(QKeyEvent *event)
{
	_player.update(event);
	update();
}


//void Game::keyReleaseEvent(QKeyEvent *event){
//	switch (event->key()){
//	case Qt::Key::Key_Space:
//		_keysDown.jumpKey = false;
//
//		break;
//	default:
//
//		break;
//	}
//}