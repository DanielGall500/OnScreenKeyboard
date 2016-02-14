#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopWidget>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QWidget::setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);

    QRect rec = QApplication::desktop()->screenGeometry();

    this->setFixedSize(rec.width() * 0.7, rec.height() * 0.4);
    this->move((rec.width() - this->width()) / 2 , (rec.height() - this->height()) * 0.9);
}

Dialog::~Dialog()
{
    delete ui;
}
