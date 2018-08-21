#include "progress.h"

#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>

Progress :: Progress(QWidget* obj) : QWidget(obj), step_(0)
{
    prBar_ = new QProgressBar;
    prBar_->setRange(0, 5);
    prBar_->setMinimumWidth(200);
    prBar_->setAlignment(Qt::AlignCenter);

    QPushButton* cmdStep = new QPushButton("Step");
    QPushButton* cmdReset = new QPushButton("Reset");

    QObject::connect(cmdStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(cmdReset, SIGNAL(clicked()), SLOT(slotReset()));

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout -> addWidget(prBar_);
    hLayout -> addWidget(cmdStep);
    hLayout -> addWidget(cmdReset);
    setLayout(hLayout);
}

void Progress :: slotStep()
{
    prBar_->setValue(++step_);
}

void Progress :: slotReset()
{
    step_ = 0;
    prBar_->reset();
}
