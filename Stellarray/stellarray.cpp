#include "stellarray.h"
#include "Game.h"


Stellarray::Stellarray(QWidget *parent)
	: QMainWindow(parent)
{
	_ui.setupUi(this);

	connect(_ui.pushButton_newGame, SIGNAL(clicked()), this, SLOT(startNewGame()));
}


Stellarray::~Stellarray()
{
}


void Stellarray::startNewGame()
{
	//QApplication b();

	Game game;
	_ui.setupUi(&game);
	this->repaint();
	//game._gameView.show();
	//return b.exec();
}