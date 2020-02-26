#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_gonometria.h"
#include <qpainter.h>

class gonometria : public QMainWindow
{
	Q_OBJECT

public:
	gonometria(QWidget* parent = Q_NULLPTR);


private:
	Ui::gonometriaClass ui;

private slots:
	void on_vykresli_clicked();
	void on_vymaz_clicked();

};
