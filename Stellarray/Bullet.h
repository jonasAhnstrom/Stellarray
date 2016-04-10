#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QElapsedTimer>

#include "player.h"


class Bullet : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Bullet(QPoint bulletPos, qreal angle, Player *player, QGraphicsItem *parent = 0);
	Bullet(const QPixmap &pixmap, QGraphicsItem *parent = 0);
	~Bullet();

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
	QPainterPath shape() const Q_DECL_OVERRIDE;
	virtual int type() const Q_DECL_OVERRIDE;
	void updateVelocity();
	bool updateCollision();

	enum { Type = UserType + 3 };

signals:
	void bulletKill();

protected:
	void advance(int step) Q_DECL_OVERRIDE;

private:
	qreal _speed;
	qreal _angle;
	QElapsedTimer _bulletLife;
	QElapsedTimer _collisionTimer;
	struct VelocityComponent
	{
		qreal x;
		qreal y;
	};
	VelocityComponent _velocityComponent;
};

