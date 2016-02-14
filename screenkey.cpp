#include "screenkey.h"

ScreenKey::ScreenKey(const QString &letter, QWidget *parent) : QWidget(parent)
{
    pKeyLetter = &letter;
    pKeyButton = new QPushButton(letter, parent);

    pKeyButton->setStyleSheet(QString::fromUtf8(
                                                "background-color: rgb(100, 100, 100);"
                                                "border-width: 2px;"
                                                "border-color: red;"
                                                "font: bold 14px;"
                                                "min-width: 10em;"
                                                "padding: 6px;"
                                                "border: none;"
                                                ));

}

ScreenKey::~ScreenKey()
{

}

