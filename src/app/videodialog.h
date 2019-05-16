#ifndef VIDEODIALOG_H
#define VIDEODIALOG_H

#include <QDialog>

namespace Ui {
class VideoDialog;
}

class VideoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoDialog(QWidget *parent = nullptr);
    ~VideoDialog();

    WId getWinId();

    bool playing() const;
    void setPlaying(bool playing);

    int volume() const;
    void setVolume(int volume);

signals:
    void play();
    void pause();
    void lastStation();
    void nextStation();
    void refreshStation();
    void volumeChanged(int volume);

private:
    void init();
    void showPlay();
    void showPause();

    Ui::VideoDialog *ui;
};

#endif // VIDEODIALOG_H
