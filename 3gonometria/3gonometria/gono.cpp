#include "gono.h"

gono::~gono()
{
	delete[] points;
}

void gono::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	QRect area = event->rect();
	painter.drawImage(area, *img, area);
}
