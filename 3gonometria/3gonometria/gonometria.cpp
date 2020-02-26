#include "gonometria.h"
#include "gono.h"

gonometria::gonometria(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	gono* plot = new gono(ui.graf->currentIndex(), 0, ui.del->value(), ui.en->value());
	ui.platno->setWidget(plot);
	ui.platno->setBackgroundRole(QPalette::Dark);
}

void gonometria::on_vykresli_clicked() {
	int type = (ui.bod->isChecked()) ? 1 : (ui.ciar->isChecked() ? 2 : ((ui.stlp->isChecked()) ? 3 : 0));
	gono* plot = new gono(ui.graf->currentIndex(), type, ui.del->value(), ui.en->value());
	ui.platno->setWidget(plot);
	ui.platno->setBackgroundRole(QPalette::Dark);
}

void gonometria::on_vymaz_clicked() {
	gono* plot = new gono(ui.graf->currentIndex(), 0, ui.del->value(), ui.en->value());
	ui.platno->setWidget(plot);
	ui.platno->setBackgroundRole(QPalette::Dark);
}
