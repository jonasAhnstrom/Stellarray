#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_stellarray.h"

#include "Game.h"


class Stellarray : public QMainWindow
{
	Q_OBJECT

public:
	Stellarray(QWidget *parent = 0);
	~Stellarray();
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:
	Ui::StellarrayClass _ui;
	Game *_game;

private slots:
	void startNewGame();
};
