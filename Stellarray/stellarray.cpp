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
	_game->keyPress(event);
}


void Stellarray::keyReleaseEvent(QKeyEvent *event)
{
	_game->keyRelease(event);
}

// TODO: Launch in same window
void Stellarray::startNewGame()
{
	_game = new Game();
	_game->_gameView.setParent(this); // TODO: Gives assertion fail on app close
	_game->_gameView.show();

	this->setFixedSize(_game->_gameView.size());

	//this->hide();
}

