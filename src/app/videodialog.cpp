#include "videodialog.h"
#include "ui_videodialog.h"

VideoDialog::VideoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VideoDialog)
{
    ui->setupUi(this);

    init();
}

VideoDialog::~VideoDialog()
{
    delete ui;
}

WId VideoDialog::getWinId()
{
    return ui->displayWidget->winId();
}

bool VideoDialog::playing() const
{
    return ui->playPushButton->isVisible();
}

void VideoDialog::setPlaying(bool playing)
{
    if (playing)
        showPlay();
    else
        showPause();
}

int VideoDialog::volume() const
{
    return ui->volumeHorizontalSlider->value();
}

void VideoDialog::setVolume(int volume)
{
    ui->volumeHorizontalSlider->setValue(volume);
}

void VideoDialog::init()
{
    connect(ui->playPushButton, &QPushButton::clicked, this, &VideoDialog::play);
    connect(ui->playPushButton, &QPushButton::clicked, this, &VideoDialog::showPause);

    connect(ui->pausePushButton, &QPushButton::clicked, this, &VideoDialog::pause);
    connect(ui->pausePushButton, &QPushButton::clicked, this, &VideoDialog::showPlay);

    connect(ui->lastPushButton, &QPushButton::clicked, this, &VideoDialog::lastStation);
    connect(ui->lastPushButton, &QPushButton::clicked, this, &VideoDialog::showPause);

    connect(ui->nextPushButton, &QPushButton::clicked, this, &VideoDialog::nextStation);
    connect(ui->nextPushButton, &QPushButton::clicked, this, &VideoDialog::showPause);

    connect(ui->refreshPushButton, &QPushButton::clicked, this, &VideoDialog::refreshStation);
    connect(ui->refreshPushButton, &QPushButton::clicked, this, &VideoDialog::showPause);

    connect(ui->volumeHorizontalSlider, &QSlider::valueChanged, this, &VideoDialog::volumeChanged);
}

void VideoDialog::showPlay()
{
    ui->playPushButton->show();
    ui->pausePushButton->hide();
}

void VideoDialog::showPause()
{
    ui->pausePushButton->show();
    ui->playPushButton->hide();
}
