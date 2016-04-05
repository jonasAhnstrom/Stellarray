#include "stellarray.h"


Stellarray::Stellarray(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);

	connect(_ui.pushButton_newGame, SIGNAL(clicked()), this, SLOT(startNewGame()));
}


Stellarray::~Stellarray()
{
}

// TODO: Launch game somehow
void Stellarray::startNewGame()
{
	_game = new Game();
	_game->_gameView.show();
	this->hide();
}