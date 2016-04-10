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
	setFixedSize(1400, 1000);

	connect(&gameTimer, SIGNAL(timeout()), &_gameScene, SLOT(advance()));
	connect(&gameTimer, SIGNAL(timeout()), this, SLOT(update()));
	gameTimer.start(1);

	// TODO: Creator class that handles creation of game objects (bullets, enemies), maybee this class
	connect(&_player, SIGNAL(bullet(QPoint, qreal)), this, SLOT(newBullet(QPoint, qreal)));

//	_player.setFlag(QGraphicsItem::ItemIsFocusable);
	//_gameScene.setFocusItem(&_player);
	//_game._gameScene.setFocus();
}


Game::~Game()
{
}


void Game::keyPressEvent(QKeyEvent *event)
{
	_player.updateInput(event);
}


void Game::keyReleaseEvent(QKeyEvent *event)
{
	_player.updateInput(event);
}


void Game::update()
{
	centerOn(_player.x() + _player.boundingRect().width() / 2, _player.y() + _player.boundingRect().height() / 2);

	// Temporary enemy add
	if (_enemys.size() < 12)
	{
		Enemy *enemy = new Enemy();
		_enemys.append(enemy);
		_gameScene.addItem(enemy);
		connect(enemy, SIGNAL(enemyKill(int)), this, SLOT(deleteEnemy(int)));
	}

	//for each (Bullet *bullet in _bullets)
	//{
	//	if (!bullet->collidingItems().isEmpty())
	//	{
	//		for each(QGraphicsItem *item in bullet->collidingItems())
	//		{
	//			if (item->type() == Enemy::Type)
	//			{
	//				delete item;
	//				//emit bulletkill();
	//			}
	//		}
	//	}
	//}

	//QList<QGraphicsItem*> items = _gameScene.collidingItems(!_bullets.isEmpty() ? _bullets.front() : 0);

	//if (!items.isEmpty())
	//{
	//	for each(QGraphicsItem *item in items)
	//		{
	//			if (Enemy *enemy = qgraphicsitem_cast<Enemy*>(item))
	//				delete enemy;
	//				//emit bulletkill();
	//		}
	//	/*if (item.front()->type() == Enemy::Type)
	//	{
	//		Enemy *s = static_cast<Enemy *>(item.front());
	//		s->destroy();
	//	}*/
	//}
}


void Game::newBullet(QPoint bulletPos, qreal angle)
{
	while (_bulletTimer.hasExpired(100))
	{
		Bullet *nb = new Bullet(bulletPos, angle, &_player);
		_bullets.append(nb);
		_gameScene.addItem(nb);
		_bulletTimer.restart();
		connect(nb, SIGNAL(bulletKill()), this, SLOT(deleteBullet()));

		//qDebug() << "New bullet";
		//qDebug() << _bullets.size();
	}
}


void Game::deleteBullet()
{
	delete _bullets.first();
	_bullets.pop_front();
}


void Game::deleteEnemy(int enemyId)
{
	//QSequentialAnimationGroup *group = new QSequentialAnimationGroup(sub);

	//qDebug() << "deleteEnemy - Id";
	//qDebug() << enemyId;

	bool notDeleted = true;
	int i = 0;
	do
	{
		if (_enemys.at(i)->_id == enemyId)
		{
			for (int j = 1; j <= 8; j++)
			{
				// TODO: Explosion effect


				//QGraphicsPixmapItem *step = new QGraphicsPixmapItem(QPixmap(QString("Resources/%1.png").arg(j)));
				//step->setPos(_enemys.at(i)->x(), _enemys.at(i)->y());


				//step->setOpacity(0);
				//QPropertyAnimation *anim = new QPropertyAnimation(step, "opacity", group);
				//anim->setDuration(100);
				//anim->setEndValue(1);
				
				/*QPainter *painter = new QPainter();
				painter->drawPixmap(x(), y(), *step);*/


				//_gameScene.addItem(step);
			}
			_gameScene.removeItem(_enemys.at(i));
			qDebug() << "Boom enemy";
			_enemys.removeAt(i);
			notDeleted = false;
		}

		//_enemys.at(i)->deleteLater();
		//delete _enemys.at(i); // TODO: Can not get the deletion to work
		//qDebug() << _enemys.size();
		i++;
	}
	while (notDeleted);
}