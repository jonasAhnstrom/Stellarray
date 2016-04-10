#define _USE_MATH_DEFINES

#include <math.h>
#include <QPainter>

#include "Player.h"


#include <qdebug.h>


Player::Player(QGraphicsItem *parent) : _velocity(0), _rotationSpeed(0), _velocityComponent(), QGraphicsPixmapItem(QPixmap("Resources/player.png").scaled(60, 100, Qt::KeepAspectRatio))
{
	//QPixmap pix = QPixmap("Resources/player.png");
	//pix.scaled(40, 60, Qt::KeepAspectRatio); // TODO: change size in photoshop for better quality scaling
	//setPixmap(pix);
	//pixmap().scaled(40, 60, Qt::KeepAspectRatio);

	setPos(2000, 1500);
	setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
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


int Player::type() const
{
	return Type;
}


void Player::updateInput(QKeyEvent *event)
{
	if (event->type() == QEvent::KeyRelease)
	{
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
		case Qt::Key::Key_Space:
			_keysDown.key_Space = false;
			break;
		default:
			break;
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
		case Qt::Key::Key_Space:
			_keysDown.key_Space = true;
			break;
		case Qt::Key::Key_R:
			setPos(2000, 1500);
			break;
		default:
			break;
		}
	}
}


void Player::updateVelocity()
{
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

	if (_velocity < 4.5 && _keysDown.key_W && !_keysDown.key_S) // Check if max speed
	{
		_velocityComponent.x += (pow(0.03, 2) + 0.02) * eX * abs(cosTheta);
		_velocityComponent.y += (pow(0.03, 2) + 0.02) * eY * abs(sinTheta);
		/*qDebug() << "x = ";
		qDebug() << _velocityComponent.x;
		qDebug() << "y = ";
		qDebug() << _velocityComponent.y;*/
	}
	else if (_velocity < 3 && _keysDown.key_S && !_keysDown.key_W)
	{
		_velocityComponent.x -= (pow(0.01, 2) + 0.01) * eX * abs(cosTheta);;
		_velocityComponent.y -= (pow(0.01, 2) + 0.01) * eY * abs(sinTheta);
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
	if (_rotationSpeed > -6 && _keysDown.key_A && !_keysDown.key_D)
	{
		_rotationSpeed -= pow(0.12, 2);
	}
	else if (_rotationSpeed < 6 && _keysDown.key_D && !_keysDown.key_A)
	{
		_rotationSpeed += pow(0.12, 2);
	}
	else
	{
		_rotationSpeed > 0 ? _rotationSpeed /= 1.013 : _rotationSpeed /= 1.013;
	}
	setRotation(rotation() + _rotationSpeed);
}


void Player::updateBullet()
{
	if (_keysDown.key_Space)
	{
		qreal currentRotation = Player::rotation()/* < 90 ? rotation() - 90 : rotation()*/; // If first quadrant, special case -90
		qreal theta = (abs(fmod(currentRotation, 360)) / -1 + 90) * M_PI / 180; // Max 360 degrees rotation, absolute value, anti clockwise (-1), +90 to start from horizontal x-axle, degrees to radians

		qreal cosTheta;
		qreal sinTheta;
		//qDebug() << currentRotation;
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

		QPoint bulletPos = QPoint(x() + (boundingRect().width() / 2) + (boundingRect().width() / 1.5) * cosTheta, (y() - 8 + (boundingRect().height() / 2) + (boundingRect().height() / 1.5) * (sinTheta / -1)));

		//qDebug() << theta;

		qreal angle;
		if (currentRotation >= 0)
		{
			angle = ((((theta * 180.0 / M_PI) + 90) / -1) + 180);
		}
		else
		{
			angle = (((theta * 180.0 / M_PI) + 90) / -1);
		}

		//qDebug() << angle;

		emit bullet(bulletPos, angle);
	}
}


qreal Player::getVelocity()
{
	return _velocity;
}


qreal Player::getVelocityX()
{
	return _velocityComponent.x;
}


qreal Player::getVelocityY()
{
	return _velocityComponent.y;
}


void Player::advance(int step)
{
	if (!step)
	{
		return;
	}
	updateVelocity();
	updateRotation();
	updateBullet();
}