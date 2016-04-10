#pragma once

#include <QGraphicsPixmapItem>
#include <QObject>


class Enemy : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT

public:
	Enemy(QGraphicsItem *parent = 0);
	Enemy(const QPixmap &pixmap, QGraphicsItem *parent = 0);
	~Enemy();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
	virtual int type() const Q_DECL_OVERRIDE;
	void updateVelocity();
	bool updateCollision();
	void destroy();

	enum { Type = UserType + 2 };
	int _id;

signals:
	void enemyKill(int enemyId);

protected:
		void advance(int step) Q_DECL_OVERRIDE;

private:
	struct VelocityComponent
	{
		qreal x;
		qreal y;
	};
	VelocityComponent _velocityComponent;

	static int _enemyCounter;
};

