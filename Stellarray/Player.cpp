#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#define _USE_MATH_DEFINES

#include <math.h>

#include "Player.h"


#include <qdebug.h>


Player::Player(QGraphicsItem *parent) : _velocity(0), _rotationSpeed(2), _velocityComponent()/*, _playerPixmap("Resources/player.png")*/
{
	QPixmap pix = QPixmap("Resources/player.png");
	pix.setDevicePixelRatio(5); // TODO: change size in photoshop for better quality scaling
	setPixmap(pix);
	//_playerPixmap.setDevicePixelRatio(qreal(5)); // TODO: change size in photoshop for better quality scaling
	setPos(2000, 1500);
	setRotation(5);
}


Player::Player(const QPixmap &pixmap, QGraphicsItem *parent)
{
}


Player::~Player()
{
}

//// TODO: Set rect to correct size for image
//QRectF Player::boundingRect() const
//{
//	qreal adjust = 0.5;
//	return QRectF(-18 - adjust, -22 - adjust, 36 + adjust, 60 + adjust);
//	
//}

//// TODO: Make it the true path
//QPainterPath Player::shape() const
//{
//	QPainterPath path;
//	path.addRect(-10, -20, 20, 40);
//	return path;
//}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0, 0, pixmap());

}


void Player::update(QKeyEvent *event)
{
	if (event->type() == QEvent::KeyRelease)
	{
		/*if (!event->isAutoRepeat())
		{
		_velocity = 0;
		}*/
		switch (event->key())
		{
		case Qt::Key::Key_W:
			_keysDown.key_W = false;
			break;
		case Qt::Key::Key_A:
			_keysDown.key_A = false;
			break;
		case Qt::Key::Key_S:
			_keysDown.key_S = false;
			break;
		case Qt::Key::Key_D:
			_keysDown.key_D = false;
			break;
		default:
			break;
		}
		if (_keysDown.key_W == false && _keysDown.key_A == false && _keysDown.key_S == false && _keysDown.key_D == false)
		{
			_keysDown.noKey = true;
		}
	}
	else
	{
		switch (event->key())
		{
		case Qt::Key::Key_W:
			_keysDown.key_W = true;
			break;
		case Qt::Key::Key_A:
			_keysDown.key_A = true;
			break;
		case Qt::Key::Key_S:
			_keysDown.key_S = true;
			break;
		case Qt::Key::Key_D:
			_keysDown.key_D = true;
			break;
		default:
			break;
		}
		_keysDown.noKey = false;
	}
}


void Player::updateVelocity()
{
	qreal currentRotation = rotation() < 90 ? rotation() - 90 : rotation(); // If first quadrant, special case -90
	qDebug() << currentRotation;
	qreal theta = (abs(fmod(currentRotation, 360)) / -1 + 90) * M_PI / 180; // Max 360 degrees rotation, absolute value, anti clockwise (-1), +90 to start from horizontal x-axle, degrees to radians

	qDebug() << theta;

	qreal cosTheta = cos(theta);
	qreal sinTheta = sin(theta);

	// TODO: Fix zero rotation edge case, temp fix in constructor
	qreal eX = cosTheta >= 0 ? 1 : -1;
	qreal eY = sinTheta >= 0 ? 1 : -1;

	if (_velocity < 25 && _keysDown.key_W && !_keysDown.key_S) // Check if max speed
	{
		_velocityComponent.x += pow(0.2, 2) * eX * abs(cosTheta);
		_velocityComponent.y += pow(0.2, 2) * eY * abs(sinTheta);
		/*qDebug() << "x = ";
		qDebug() << _velocityComponent.x;
		qDebug() << "y = ";
		qDebug() << _velocityComponent.y;*/
	}
	else if (_keysDown.key_S && !_keysDown.key_W)
	{
		_velocityComponent.x -= pow(0.12, 2) * eX;
		_velocityComponent.y -= pow(0.12, 2) * eY;
	}
	else
	{
		// Decrease velocity components slowly
		qreal xVel = _velocityComponent.x / 1.01;
		_velocityComponent.x = abs(xVel) > 0 ? xVel : 0;

		qreal yVel = _velocityComponent.y / 1.01;
		_velocityComponent.y = abs(yVel) > 0 ? yVel : 0;
	}

	_velocity = sqrt(pow(_velocityComponent.x, 2) + pow(_velocityComponent.y, 2));
	//qDebug() << _velocity;
	//QPoint point;
	//point.setX(pos().x() + _velocityComponent.x);
	//setPos(QPoint(pos().x() + _velocityComponent.x, pos().y() + _velocityComponent.y));
	moveBy(_velocityComponent.x, -_velocityComponent.y); // -y for Qt cordinates
}


void Player::updateRotation()
{
	if (_keysDown.key_A && !_keysDown.key_D)
	{
		_rotationSpeed -= pow(2, 2);
	}
	else if (_keysDown.key_D && !_keysDown.key_A)
	{
		_rotationSpeed += pow(2, 2);
	}
	setRotation(_rotationSpeed);
}

// TODO: Velocity vector that knows x and y speed
void Player::advance(int step)
{
	if (!step)
	{
		return;
	}

	updateVelocity();
	updateRotation();

	//if (_keysDown.noKey)
	//{
	//	updateVelocity();
	//	updateRotation();
	//}
	//if (_keysDown.key_W)
	//{
	//		//_speed = _speed + pow(0.2, 2);
	//		//_velocityComponent.x = _velocityComponent.x + pow(0.2, 2);
	//		//_velocityComponent.y = _velocityComponent.y + pow(0.2, 2);
	//	updateVelocity();
	//}
	//if (_keysDown.key_A)
	//{
	//	_rotationSpeed += _rotationSpeed - pow(0.2, 2);
	//	setRotation(_rotationSpeed);
	//}
	//if (_keysDown.key_S)
	//{
	//	updateVelocity();
	//}
	//if (_keysDown.key_D)
	//{
	//	_rotationSpeed += _rotationSpeed + pow(0.2, 2);
	//	setRotation(_rotationSpeed);
	//}
	//moveBy(0, -1 * _velocity);
}