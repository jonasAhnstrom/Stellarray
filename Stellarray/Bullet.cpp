#define _USE_MATH_DEFINES

#include <math.h>

#include "Bullet.h"

#include <QPainter>
#include <QtWidgets>

#include "Enemy.h"

#include <qdebug.h>



Bullet::Bullet(QPoint bulletPos, qreal angle, Player *player, QGraphicsItem *parent) : QGraphicsPixmapItem(QPixmap("Resources/bullet.png"))
{
	setPos(bulletPos);
	_speed = 1;
	_angle = angle;
	_bulletLife.start();
	setRotation(angle);

	qreal currentRotation = rotation()/* < 90 ? rotation() - 90 : rotation()*/; // If first quadrant, special case -90
	qreal theta = (abs(fmod(currentRotation, 360)) / -1 + 90) * M_PI / 180; // Max 360 degrees rotation, absolute value, anti clockwise (-1), +90 to start from horizontal x-axle, degrees to radians

	qreal cosTheta;
	qreal sinTheta;
	if (currentRotation < 0) // To deal with negative values from rotation()
	{
		theta /= -1;
		cosTheta = cos(theta) / -1;
		sinTheta = sin(theta) / -1;
	}
	else
	{
		cosTheta = cos(theta);
		sinTheta = sin(theta);
	}

	qreal eX = cosTheta >= 0 ? 1 : -1;
	qreal eY = sinTheta >= 0 ? 1 : -1;

	_velocityComponent.x = eX * _speed * abs(cosTheta) + player->getVelocityX() / 2;
	_velocityComponent.y = eY * _speed * abs(sinTheta) + player->getVelocityY() / 2;

	/*qDebug() << "x = ";
	qDebug() << _velocityComponent.x;
	qDebug() << "y = ";
	qDebug() << _velocityComponent.y;*/
}


Bullet::Bullet(const QPixmap &pixmap, QGraphicsItem *parent)
{
}


Bullet::~Bullet()
{
	//qDebug() << "Bullet killed";
}


QPainterPath Bullet::shape() const
{
	QPainterPath path;
	path.addRect(-10, -20, 20, 40);
	return path;
}


void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0, 0, pixmap());
}


int Bullet::type() const
{
	return Type;
}


void Bullet::updateVelocity()
{
	moveBy(_velocityComponent.x, -_velocityComponent.y);
}


bool Bullet::updateCollision()
{
	if (_collisionTimer.elapsed() > 15 || !_collisionTimer.isValid())
	{
		// TODO: Change to collidinItems point checkup instead of bounding rect
		//QList<QGraphicsItem*> item = collidingItems(Qt::IntersectsItemBoundingRect);
		QGraphicsScene *scene = static_cast<QGraphicsScene *>(this->scene());
		//QList<QGraphicsItem *> items = scene->items(pos());
		/*if (!items.isEmpty())
		{*/
		qDebug() << "Bullet pos";
		qDebug() << pos();
			foreach(QGraphicsItem * item, scene->items(pos())) {
				if (item->type() == Enemy::Type) {
					Enemy *enemy = static_cast<Enemy *>(item);
					qDebug() << "---------------------------------- Enemy pos ----------------------------------";
					qDebug() << enemy->pos();
					enemy->destroy();
					//emit bulletKill();
				}
			}
			/*if (items.front()->type() == Enemy::Type)
			{
				Enemy *s = static_cast<Enemy *>(item.front());
				s->destroy();
				return true;
			}*/
		//}
		_collisionTimer.restart();
	}




	//for each(QGraphicsItem *item in danger)
	//{
	//	if (Enemy *enemy = qgraphicsitem_cast<Enemy*>(item))
	//		delete enemy;
	//		//emit bulletKill();
	//		return true;
	//}
	return false;
}


void Bullet::advance(int step)
{
	if (!step)
	{
		return;
	}
	updateVelocity();
	//_collisionTimer.start();

	if (!updateCollision() && _bulletLife.elapsed() >= 2000 /*350*/)
	{
		emit bulletKill();
	}
}