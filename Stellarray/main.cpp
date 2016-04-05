#include <QtWidgets/QApplication>

#include "stellarray.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Stellarray w;
	w.show();
	return a.exec();
}
