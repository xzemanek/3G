#include "gonometria.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gonometria w;
	w.show();
	return a.exec();
}
