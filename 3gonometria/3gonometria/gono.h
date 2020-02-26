#pragma once

#include <QObject>
#include<QPainter>
#include<QtWidgets>
const int MAXPOINTS = 2000;

class gono : public QWidget
{
	Q_OBJECT

private:
	int function;
	int type;
	int division;
	int n;
	QImage* img = nullptr;
	QPainter* painter = nullptr;
	QPoint* points = nullptr;

	void drawAxes() {
		QPen pen = QPen();
		pen.setColor(Qt::black);
		pen.setWidth(5);
		painter->setRenderHint(QPainter::Antialiasing);
		painter->setPen(pen);
		painter->drawLine(20, 250, 480, 250);
		painter->drawLine(250, 20, 250, 480);

		pen.setWidth(2);
		painter->setPen(pen);
		int deltaX = 460 / (double)division;
		int deltaY = 460 / 20;

		for (int i = 0; i <= division / 2; i++) {
			painter->drawLine(250 - deltaX * i, 245, 250 - deltaX * i, 255);
			painter->drawLine(250 + deltaX * i, 245, 250 + deltaX * i, 255);
		}

		for (int i = 0; i <= division / 2; i++) {
			painter->drawLine(245, 250 - deltaY * i, 255, 250 - deltaY * i);
			painter->drawLine(245, 250 + deltaY * i, 255, 250 + deltaY * i);
		}
	}

	void drawDotsPlot() {
		QPen pen = QPen();
		pen.setColor(Qt::blue);
		pen.setCapStyle(Qt::RoundCap);
		pen.setWidth(5);
		painter->setRenderHint(QPainter::Antialiasing);
		painter->setPen(pen);
		int deltaPx = 460 / division;
		int deltaPy = 230;
		double deltaX = (double)2 * n * M_PI / division;
		for (int i = -division / 2; i <= division / 2; i++) {
			double functValue = (i + (division / (double)2)) * deltaX - n * M_PI;
			double value = function == 1 ? cos(functValue) : sin(functValue);
			painter->drawPoint(250 + deltaPx * i, 250 - deltaPy * value);
		}
	}

	void drawLinePlot() {
		QPen pen = QPen();
		pen.setColor(Qt::blue);
		pen.setCapStyle(Qt::RoundCap);
		pen.setJoinStyle(Qt::RoundJoin);
		pen.setWidth(5);
		painter->setRenderHint(QPainter::Antialiasing);
		painter->setPen(pen);
		int deltaPx = (460 / division);
		int deltaPy = 230;
		double deltaX = (double)2 * n * M_PI / division;
		int count = 0;
		points = new QPoint[MAXPOINTS];
		for (int i = -division / 2; i <= division / 2; i++) {
			double functValue = (i + (division / (double)2)) * deltaX - n * M_PI;
			double value = function == 1 ? cos(functValue) : sin(functValue);
			points[i + (division / 2)] = QPoint(250 + deltaPx * i, 250 - deltaPy * value);
			count++;
		}
		for (int i = 0; i < count - 1; i++)
			painter->drawLine(points[i], points[i + 1]);

	}

	void drawRectPlot() {
		QPen pen = QPen();
		pen.setColor(Qt::blue);
		pen.setCapStyle(Qt::RoundCap);
		pen.setWidth(4);
		painter->setRenderHint(QPainter::Antialiasing);
		painter->setPen(pen);
		int deltaPx = (460 / division);
		int deltaPy = 230;
		double deltaX = (double)2 * n * M_PI / division;
		for (int i = -division / 2; i < division / 2; i++) {
			double functValue = (i + (division / (double)2)) * deltaX - n * M_PI;
			double value = function == 1 ? cos(functValue) : sin(functValue);
			painter->setBrush(QColor(0, 0, 255, 127));
			painter->drawRect((250 - deltaPx / 2) + deltaPx * i, 250, deltaPx, (250 - deltaPy * value) - 250);
		}
	}

public:
	gono(int function, int type, int division, int n, QWidget* parent = nullptr) :QWidget(parent) {
		this->function = function;
		this->type = type;
		this->division = division;
		this->n = n;

		QSize size = QSize(500, 500);
		img = new QImage(size, QImage::Format_ARGB32);
		img->fill(Qt::white);

		this->setMinimumSize(size);
		this->setMaximumSize(size);
		this->resize(size);
		painter = new QPainter(img);

		painter->drawText(15, 265, "x");
		painter->drawText(265, 15, "y");

		drawAxes();
		if (type == 1)
			drawDotsPlot();
		if (type == 2)
			drawLinePlot();
		if (type == 3)
			drawRectPlot();

		painter->end();
	}

	~gono();

private slots:
	void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
};
