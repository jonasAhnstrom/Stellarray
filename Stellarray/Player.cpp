#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include "Player.h"


Player::Player()
{
	_playerPixmap.load("Resources/player.png");
	_playerPixmap.setDevicePixelRatio(qreal(5)); // TODO: change size in photoshop for better quality scaling
	setPos(2000, 1500);
}


Player::~Player()
{
}


QRectF Player::boundingRect() const
{
	qreal adjust = 0.5;
	return QRectF(-18 - adjust, -22 - adjust, 36 + adjust, 60 + adjust);
}


QPainterPath Player::shape() const
{
	QPainterPath path;
	path.addRect(-10, -20, 20, 40);
	return path;
}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	/*painter->setBrush(Qt::white);
	painter->drawEllipse(-10, -17, 8, 8);
	painter->drawEllipse(2, -17, 8, 8);*/
	painter->drawPixmap(-18, -20, _playerPixmap);
}


void Player::advance(int step)
{
	if (!step)
		return;

	switch (_keyDown)
	{
	case Qt::Key_A:
		moveBy(10, 0);
		break;
	case Qt::Key_D:
		break;
	case Qt::Key_S:
		break;
	case Qt::Key_W:
		break;
	case Qt::Key_Space:
		break;
	default:
		break;
	}
}


void Player::update(QKeyEvent *event)
{
	switch (event->key()){
	case Qt::Key::Key_W:
		_keyDown = Qt::Key::Key_W;

		break;
	default:

		break;
	}
}