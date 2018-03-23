#ifndef PAINTSETTINGS_H
#define PAINTSETTINGS_H

#include <QSlider>
#include <QLabel>
#include <QWidget>
#include <QRadioButton>
#include <QCheckBox>
#include "paintwidget.h"
#include "myhintlabel.h"

class EventHandler;

class paintSettings : public QWidget {
	Q_OBJECT
  public:
	explicit paintSettings(EventHandler *h, QWidget *parent = nullptr);

  private:
	QSlider *sliderAnzahlLinien;
	QSlider *sliderDicke;
	QSlider *sliderRotation;
	QSlider *sliderRotationAbstand;
	paintWidget *paintWidget;
	MyHintLabel *sliderHint1;
	MyHintLabel *sliderHint2;
	QRadioButton *radioButtonDrawLines;
	QRadioButton *radioButtonDrawElipses;
	QRadioButton *radioButtonDrawQuader;
	QRadioButton *radioButtonDrawSpirale;
	QRadioButton *radioButtonDrawPoints;
	QCheckBox *checkBoxDrawPoints;


  signals:
	void sliderMoved();



};

#endif // PAINTSETTINGS_H
