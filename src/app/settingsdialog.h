#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QCloseEvent>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog() override;

    void loadSettings(QSettings *settings);
    void saveSettings(QSettings *settings);

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
