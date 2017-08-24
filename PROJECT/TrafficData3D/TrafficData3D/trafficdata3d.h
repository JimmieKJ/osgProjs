#ifndef TRAFFICDATA3D_H
#define TRAFFICDATA3D_H

#include <QtWidgets/QMainWindow>
#include "ui_trafficdata3d.h"

class TrafficData3D : public QMainWindow
{
	Q_OBJECT

public:
	TrafficData3D(QWidget *parent = 0);
	~TrafficData3D();

private:
	Ui::TrafficData3DClass ui;
};

#endif // TRAFFICDATA3D_H
