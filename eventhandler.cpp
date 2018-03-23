#include "eventhandler.h"
#include <QDebug>

EventHandler::EventHandler(QObject *parent) : QObject(parent) {
}

//Empfange Daten von paintsettings
void EventHandler::slotSliderChanchedValue(int v) {
	qDebug() << "Eventhandler Slider " << v;
	//Löse Signal aus und Sende Daten mit
	emit signalSliderChanched(v);
}

void EventHandler::slotSliderDickeChanchedValue(int v) {
	qDebug() << "Eventhandler SliderDicke " << v;
	emit signalSliderDickeChanched(v);
}

void EventHandler::slotOpenSettingsWindow() {
	emit signalOpenSettings();
}

void EventHandler::slotToggleElipsRadioButton(bool v) {
	qDebug() << "Elips Radiobutton tooglet ";
	emit signalElipsRadioButtonToogled(v);
}

void EventHandler::slotToggleLinesRadioButton(bool v) {
	qDebug() << "Lines Radiobutton tooglet ";
	emit signalLinesRadioButtonToogled(v);
}
void EventHandler::slotToggleQuaderRadioButton(bool v) {
	qDebug() << "Quader Radiobutton tooglet ";
	emit signalQuaderRadioButtonToogled(v);
}
void EventHandler::slotToggleTestRadioButton(bool v) {
	qDebug() << "Test Radiobutton tooglet ";
	emit signalTestRadioButtonToogled(v);
}
void EventHandler::slotSliderRotationChanchedValue(int v) {
	qDebug() << "Eventhandler SliderRotation " << v;
	emit signalSliderRotationChanched(v);
}
void EventHandler::slotSliderRotationAbstandChanchedValue(int v) {
	qDebug() << "Eventhandler SliderRotationAbstand " << v;
	emit signalSliderRotationAbstandChanched(v);
}

void EventHandler::slotPointsCheckBoxChanched(bool v) {
	qDebug() << "Points CheckBox tooglet " << v;
	emit signalPointsCheckBoxToogled(v);
}

void EventHandler::slotTogglePointsRadioButton(bool v) {
	qDebug() << "Draw Points Radiobutton tooglet ";
	emit signalPointsRadioButtonToogled(v);
}

