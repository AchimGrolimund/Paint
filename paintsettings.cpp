#include "paintsettings.h"
#include "eventhandler.h"

#include <QGridLayout>
#include <QObject>
#include <QDebug>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QFormLayout>

paintSettings::paintSettings(EventHandler *h,
							 QWidget *parent) : QWidget(parent) {
	sliderAnzahlLinien = new QSlider(Qt::Orientation::Horizontal);
	sliderAnzahlLinien->setTracking(true);
	sliderAnzahlLinien->setMinimum(1);
	sliderAnzahlLinien->setSliderPosition(20);
	sliderAnzahlLinien->setMaximum(999);
	sliderAnzahlLinien->setToolTip(tr("Anzahl Formen, Kreise oder Punkte"));
	sliderDicke = new QSlider(Qt::Orientation::Horizontal);
	sliderDicke->setTracking(true);
	sliderDicke->setMinimum(1);
	sliderDicke->setMaximum(50);
	sliderDicke->setSliderPosition(10);
	sliderDicke->setToolTip(tr("Dicker der Linien"));
	sliderHint1 = new MyHintLabel(this, sliderAnzahlLinien);
	sliderHint2 = new MyHintLabel(this, sliderDicke);
	sliderRotation = new QSlider(Qt::Orientation::Horizontal);
	sliderRotation->setRange(1, 179);
	sliderRotationAbstand = new QSlider(Qt::Orientation::Horizontal);
	sliderRotationAbstand->setRange(1, 50);
	sliderRotation->setToolTip(tr("Rotation der Form"));
	//--------------------------------------------------
	QLabel *StatusLabel = new
	QLabel("© <a href=\"https://github.com/EvilAcid\"style=\"color: red;\">Achim Grolimund</a> thanks to <a href=\"https://github.com/Misch2k\"style=\"color: red;\">Michel Kugler</a>");
	StatusLabel->setTextFormat(Qt::TextFormat::RichText);
	StatusLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
	StatusLabel->setOpenExternalLinks(true);
	//--------------------------------------------------
	radioButtonDrawLines = new QRadioButton();
	radioButtonDrawLines->setChecked(true);
	radioButtonDrawElipses = new QRadioButton();
	radioButtonDrawQuader = new QRadioButton();
	radioButtonDrawSpirale = new QRadioButton();
	checkBoxDrawPoints = new QCheckBox();
	//--------------------------------------------------
	QFrame *line = new QFrame(this);
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	line->setFixedHeight(2);
	line->setStyleSheet("color:white");
	//--------------------------------------------------
	QFormLayout *einstellungenFormLayout = new QFormLayout;
	QGroupBox *einstellungenGroupBox = new QGroupBox(tr("Einstellung"));
	einstellungenFormLayout->addRow(tr("Anz.Linien"), sliderAnzahlLinien);
	einstellungenFormLayout->addRow(tr("Dicke"), sliderDicke);
	einstellungenGroupBox->setLayout(einstellungenFormLayout);
	//--------------------------------------------------
	QFormLayout *musterFormLayout = new QFormLayout;
	QGroupBox *musterGroupBox = new QGroupBox("Muster");
	musterFormLayout->addRow(tr("Linien"), radioButtonDrawLines);
	musterFormLayout->addRow(tr("Elipse"), radioButtonDrawElipses);
	musterFormLayout->addRow(tr("Quader"), radioButtonDrawQuader);
	musterFormLayout->addRow(tr("Spirale"), radioButtonDrawSpirale);
	musterFormLayout->addRow(tr("<ul><li> Rotation</li></ul>"), sliderRotation);
	musterFormLayout->addRow(tr("<ul><li> Abstand</li></ul>"),
							 sliderRotationAbstand);
	musterFormLayout->addRow(tr("<ul><li> Punkte</li></ul>"), checkBoxDrawPoints);
	musterGroupBox->setLayout(musterFormLayout);
	//--------------------------------------------------
	QGridLayout *layout = new QGridLayout();
	layout->setRowStretch(0, 20);
	layout->addWidget(einstellungenGroupBox, 1, 0, 2, 7);
	layout->addWidget(musterGroupBox, 4, 0, 3, 7);
	//--------------------------------------------------
	//Line, Copyright and Thanks Label
	layout->addWidget(line, 10, 0, 1, 7);
	layout->addWidget(StatusLabel, 11, 0, 1, 7);
	//--------------------------------------------------
	setWindowTitle(tr("Settings"));
	setWindowIcon(QIcon(":/icons/settings_1.ico"));
	setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Window |
				   Qt::WindowCloseButtonHint);
	setFixedSize(220, 270);
	setLayout(layout);
	//--------------------------------------------------
	//--------------------------------------------------
	//--------------------------------------------------
	//Slider Valuechanched sende Daten an EventHandler
	QObject::connect(this->sliderAnzahlLinien, SIGNAL(valueChanged(int)),
					 h, SLOT(slotSliderChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(this->sliderDicke, SIGNAL(valueChanged(int)),
					 h, SLOT(slotSliderDickeChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect( this->radioButtonDrawLines, SIGNAL(toggled(bool)),
					  h, SLOT(slotToggleLinesRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->radioButtonDrawElipses, SIGNAL(toggled(bool)),
					  h, SLOT(slotToggleElipsRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->radioButtonDrawQuader, SIGNAL(toggled(bool)),
					  h, SLOT(slotToggleQuaderRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect( this->radioButtonDrawSpirale, SIGNAL(toggled(bool)),
					  h, SLOT(slotToggleTestRadioButton(bool)));
	//--------------------------------------------------
	QObject::connect(this->sliderRotation, SIGNAL(valueChanged(int)),
					 h, SLOT(slotSliderRotationChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect(this->sliderRotationAbstand, SIGNAL(valueChanged(int)),
					 h, SLOT(slotSliderRotationAbstandChanchedValue(int)));
	//--------------------------------------------------
	QObject::connect( this->checkBoxDrawPoints, SIGNAL(toggled(bool)),
					  h, SLOT(slotPointsCheckBoxChanched(bool)));
	//--------------------------------------------------
	sliderHint2->raise();
}
