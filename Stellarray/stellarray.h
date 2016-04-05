#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_stellarray.h"


class Stellarray : public QMainWindow
{
	Q_OBJECT

public:
	Stellarray(QWidget *parent = 0);
	~Stellarray();

private:
	Ui::StellarrayClass _ui;

private slots:
	void startNewGame();
};
