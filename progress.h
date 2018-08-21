#pragma once

#include <QWidget>

class QProgressBar;

class Progress : public QWidget
{
    Q_OBJECT

private:
    QProgressBar* prBar_;
    int step_;

public:
    Progress(QWidget* obj = 0);

public slots:
    void slotStep();
    void slotReset();
};
