#pragma once

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
//#include <QElapsedTimer>

//#include "Bullet.h"


class Player : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Player(QGraphicsItem *parent = 0);
	Player(const QPixmap &pixmap, QGraphicsItem *parent = 0);
	~Player();

	//QRectF boundingRect() const Q_DECL_OVERRIDE;
	//QPainterPath shape() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
	void update(QKeyEvent *event);
	void updateVelocity();
	void updateRotation();
	void updateBullet();
	qreal getVelocity();

signals:
	void bullet(QPoint bulletPos, qreal angle);

protected:
	void advance(int step) Q_DECL_OVERRIDE;

	struct KeysDown
	{
		bool key_W = 0;
		bool key_A = 0;
		bool key_S = 0;
		bool key_D = 0;
		bool key_Space = 0;
	};
	KeysDown _keysDown;

private:
	struct VelocityComponent
	{
		qreal x;
		qreal y;
	};
	VelocityComponent _velocityComponent;
	qreal _velocity;
	qreal _rotationSpeed;

	//QElapsedTimer _bulletTimer;

	//QList<Bullet> _bullets;
};