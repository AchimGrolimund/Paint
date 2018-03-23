#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QMainWindow>
#include <QStatusBar>

class EventHandler;

class paintWidget : public QMainWindow {
	Q_OBJECT

  public:
	paintWidget(QWidget *parent = 0);
	~paintWidget();

  private:
	void paintEvent(QPaintEvent *event);
	int distValue = 20;
	int dickeValue = 10;
	int rotation = 1;
	int versatz = 1;
	bool isLines = 1;
	bool isElips = 0;
	bool isQuader = 0;
	bool isSpirale = 0;
	bool isSpirale_Points = 0;
	//-----
	bool isPoints = 0;
	EventHandler *h;
	//QStatusBar *statusbar;
	//-------
	int PointA[2];
	int PointB[2];
	int PointC[2];


  public slots:
	void slotOpenSettingsWindow();
	void slotSliderChanchedValue(int );
	void slotSliderDickeChanchedValue(int );
	void slotLinesRadioButtonChanched(bool );
	void slotElipsRadioButtonChanched(bool );
	void slotQuaderRadioButtonChanched(bool );
	void slotSpiraleRadioButtonChanched(bool );
	void slotSliderRotationChanchedValue(int );
	void slotSliderRotationAbstandChanchedValue(int );
	void slotPointsCheckBoxChanched(bool);
	//-----
	void slotPointsRadioButtonChanched(bool );

  signals:
	void signalOpenSettingsWindow();




};

#endif // PAINTWIDGET_H
