#include <QPainter>

#include "Enemy.h"

#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>

#include <qdebug.h>




int Enemy::_enemyCounter = 0;


Enemy::Enemy(QGraphicsItem *parent) : QGraphicsPixmapItem(QPixmap("Resources/enemy1.png").scaled(50, 100, Qt::KeepAspectRatio))
{
	int x = (qrand() % 3000) + 500;
	int y = (qrand() % 2000) + 500;
	setPos(x, y);
	_velocityComponent.x = 0.01;
	_velocityComponent.y = 0.01;

	_id = _enemyCounter;
	_enemyCounter++;
}


Enemy::Enemy(const QPixmap &pixmap, QGraphicsItem *parent)
{
	setPixmap(pixmap);
}


Enemy::~Enemy()
{
	qDebug() << "Enemy deleted";
	qDebug() << _id;
}


void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0, 0, pixmap());
}


int Enemy::type() const
{
	return Type;
}


void Enemy::updateVelocity()
{
	if (pos().x() > 3800 || pos().x() < 200 || pos().y() > 2800 || pos().y() < 200)
	{
		_velocityComponent.x /= -1;
		_velocityComponent.y /= -1;
	}
	moveBy(_velocityComponent.x, -_velocityComponent.y);
}


bool Enemy::updateCollision()
{
	//QList<QGraphicsItem*> item = collidingItems(Qt::IntersectsItemBoundingRect);



	//if (!item.isEmpty())
	//{
	//	if (item.front()->type() == Enemy::Type)
	//	{
	//		Enemy *s = static_cast<Enemy *>(item.front());
	//		s->destroy();
	//		return true;
	//	}
	//}


	//for each(QGraphicsItem *item in danger)
	//{
	//	if (Enemy *enemy = qgraphicsitem_cast<Enemy*>(item))
	//		delete enemy;
	//		//emit bulletKill();
	//		return true;
	//}
	return false;
}


void Enemy::destroy()
{
	emit enemyKill(_id);
	qDebug() << "------- Enemy id -------";
	qDebug() << _id;
}


void Enemy::advance(int step)
{
	if (!step)
	{
		return;
	}
	updateVelocity();
	updateCollision();
}

