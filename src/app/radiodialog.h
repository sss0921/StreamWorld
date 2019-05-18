#ifndef RADIODIALOG_H
#define RADIODIALOG_H

#include <QDialog>

namespace Ui {
class RadioDialog;
}

class RadioDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RadioDialog(QWidget *parent = nullptr);
    ~RadioDialog();

    void setPlaying(bool playing);
    void setVolume(int value);

signals:
    void play();
    void pause();
    void lastStation();
    void nextStation();
    void refreshStation();
    void stop();
    void changeVolume(int volume);

private:
    void init();
    void showPlay();
    void showPause();

    Ui::RadioDialog *ui;
};

#endif // RADIODIALOG_H
