#include "radiodialog.h"
#include "ui_radiodialog.h"

RadioDialog::RadioDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RadioDialog)
{
    ui->setupUi(this);

    init();
}

RadioDialog::~RadioDialog()
{
    delete ui;
}

void RadioDialog::setPlaying(bool playing)
{
    if (playing)
        showPause();
    else
        showPlay();
}

void RadioDialog::setVolume(int value)
{
    ui->volumeVerticalSlider->setValue(value);
}

void RadioDialog::init()
{
    connect(ui->playPushButton, &QPushButton::clicked, this, &RadioDialog::play);
    connect(ui->playPushButton, &QPushButton::clicked, this, &RadioDialog::showPause);

    connect(ui->pausePushButton, &QPushButton::clicked, this, &RadioDialog::pause);
    connect(ui->pausePushButton, &QPushButton::clicked, this, &RadioDialog::showPlay);

    connect(ui->stopPushButton, &QPushButton::clicked, this, &RadioDialog::stop);
    connect(ui->stopPushButton, &QPushButton::clicked, this, &RadioDialog::showPlay);

    connect(ui->lastPushButton, &QPushButton::clicked, this, &RadioDialog::lastStation);
    connect(ui->lastPushButton, &QPushButton::clicked, this, &RadioDialog::showPause);

    connect(ui->nextPushButton, &QPushButton::clicked, this, &RadioDialog::nextStation);
    connect(ui->nextPushButton, &QPushButton::clicked, this, &RadioDialog::showPause);

    connect(ui->refreshPushButton, &QPushButton::clicked, this, &RadioDialog::refreshStation);
    connect(ui->refreshPushButton, &QPushButton::clicked, this, &RadioDialog::showPause);

    connect(ui->volumeVerticalSlider, &QSlider::valueChanged, this, &RadioDialog::changeVolume);
}

void RadioDialog::showPlay()
{
    ui->playPushButton->hide();
    ui->pausePushButton->show();
}

void RadioDialog::showPause()
{
    ui->playPushButton->show();
    ui->pausePushButton->hide();
}
