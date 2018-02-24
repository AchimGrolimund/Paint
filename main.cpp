#include "paintwidget.h"
#include <QApplication>
#include <QFile>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	//--------------------------------------------------
	//--------------------------------------------------
	paintWidget w;
	QFile file(":/StyleSheet/style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	a.setStyleSheet(styleSheet);
	w.show();
	return a.exec();
}
