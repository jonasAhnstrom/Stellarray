#pragma once

#include <QGraphicsItem>
#include <QKeyEvent>


class Player : public QGraphicsItem
{
public:
	Player();
	~Player();

	QRectF boundingRect() const Q_DECL_OVERRIDE;
	QPainterPath shape() const Q_DECL_OVERRIDE;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
	void update(QKeyEvent *event);

protected:
	void advance(int step) Q_DECL_OVERRIDE;
	Qt::Key _keyDown;

private:
	QPixmap _playerPixmap;
};