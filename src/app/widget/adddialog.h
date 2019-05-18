#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

signals:
    void addGroupOrStation(const QString &str1, const QString &str2);

private:
    void init();
    void initComponent();
    void onDialogAccepted();
    void onDialogRejected();
    void stationInvaild();
    void groupInvalid();

    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
