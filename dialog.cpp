#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopWidget>
#include <QPushButton>
#include <screenkey.h>
#include <QPalette>
#include <QColor>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QWidget::setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    QPalette pal = this->palette();
    QColor materialDesRGB(52,61,66,255); // originals: 57,66,71,255 -= 5 to make darker

    pal.setColor(QPalette::Window, materialDesRGB);
    this->setPalette(pal);

    QRect rec = QApplication::desktop()->screenGeometry();

    this->setFixedSize(rec.width() * 0.7, rec.height() * 0.4);
    this->move((rec.width() - this->width()) / 2 , (rec.height() - this->height()) * 0.9);

    ScreenKey *screenKey = new ScreenKey("Q",this);
    screenKey->show();

    connect(screenKey, SIGNAL(clicked()), this, SLOT(ScreenKey::keyPressed()));
}

Dialog::~Dialog()
{
    delete ui;
}

