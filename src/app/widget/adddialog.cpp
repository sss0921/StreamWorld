#include "adddialog.h"
#include "ui_adddialog.h"

#include <QMessageBox>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(addDialog, "streamWorld.AddDialog")

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    init();
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::init()
{
    connect(ui->addGroupRadioButton, &QRadioButton::clicked, this, &AddDialog::stationInvaild);
    connect(ui->addChannelRadioButton, &QRadioButton::clicked, this, &AddDialog::groupInvalid);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddDialog::onDialogAccepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AddDialog::onDialogRejected);

    initComponent();
}

void AddDialog::initComponent()
{
    ui->addChannelRadioButton->setChecked(true);
    ui->channelGroupBox->setEnabled(true);

    ui->addGroupRadioButton->setChecked(false);
    ui->groupLineEdit->setEnabled(false);
}

void AddDialog::onDialogAccepted()
{
    if (ui->addGroupRadioButton->isChecked()) {
        QString groupName = ui->groupLineEdit->text();
        if (!groupName.isEmpty())
            emit addGroupOrStation(groupName, "");
        else
            QMessageBox::warning(this, tr("Info"), tr("Please input full information!"),
                                 QMessageBox::Ok);

    } else {
        QString stationName = ui->channelTitleLineEdit->text();
        QString stationAddress = ui->channelAddressLineEdit->text();

        if (stationName.isEmpty() || stationAddress.isEmpty())
            QMessageBox::warning(this, tr("Info"), tr("Please input full information!"),
                                 QMessageBox::Ok);
        else
            emit addGroupOrStation(stationName, stationAddress);
    }
}

void AddDialog::onDialogRejected()
{
    initComponent();
    this->rejected();
}

void AddDialog::stationInvaild()
{
    ui->channelGroupBox->setEnabled(false);
    ui->groupLineEdit->setEnabled(true);
}

void AddDialog::groupInvalid()
{
    ui->channelGroupBox->setEnabled(true);
    ui->groupLineEdit->setEnabled(false);
}
