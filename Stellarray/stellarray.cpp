#include "stellarray.h"


Stellarray::Stellarray(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);
	this->setWindowTitle("Stellarray");
	connect(_ui.pushButton_newGame, SIGNAL(clicked()), this, SLOT(startNewGame()));
}


Stellarray::~Stellarray()
{
}


void Stellarray::keyPressEvent(QKeyEvent *event)
{
	_game.keyPress(event);
}


void Stellarray::keyReleaseEvent(QKeyEvent *event)
{
	_game.keyRelease(event);
}


void Stellarray::startNewGame()
{
	_game.setParent(this);
	_game.setFocus();
	_game.show();

	setFixedSize(_game.size());
}

