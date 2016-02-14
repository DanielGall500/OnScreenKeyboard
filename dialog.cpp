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
}

Dialog::~Dialog()
{
    delete ui;
}
