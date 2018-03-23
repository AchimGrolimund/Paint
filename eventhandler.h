#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class EventHandler : public QObject {
	Q_OBJECT
  public:
	explicit EventHandler(QObject *parent = nullptr);

  signals:
	void signalOpenSettingsWindow();
	void signalOpenSettings();
	void signalSliderChanched(int);
	void signalSliderDickeChanched(int);
	void signalLinesRadioButtonToogled(bool);
	void signalElipsRadioButtonToogled(bool);
	void signalQuaderRadioButtonToogled(bool);
	void signalTestRadioButtonToogled(bool);
	void signalSliderRotationChanched(int);
	void signalSliderRotationAbstandChanched(int);
	void signalPointsCheckBoxToogled(bool);
	void signalPointsRadioButtonToogled(bool);


  public slots:
	void slotSliderChanchedValue(int);
	void slotSliderDickeChanchedValue(int);
	void slotOpenSettingsWindow();
	void slotToggleElipsRadioButton(bool);
	void slotToggleLinesRadioButton(bool);
	void slotToggleQuaderRadioButton(bool);
	void slotToggleTestRadioButton(bool);
	void slotSliderRotationChanchedValue(int);
	void slotSliderRotationAbstandChanchedValue(int);
	void slotPointsCheckBoxChanched(bool);
	void slotTogglePointsRadioButton(bool);
};

#endif // EVENTHANDLER_H
