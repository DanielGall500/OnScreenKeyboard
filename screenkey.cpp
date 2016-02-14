#include "screenkey.h"

ScreenKey::ScreenKey(const QString &letter, QWidget *parent) : QWidget(parent)
{
    pKeyLetter = &letter;
    pKeyButton = new QPushButton(letter, parent);

    pKeyButton->setStyleSheet(QString::fromUtf8(
                                                "background-color: rgb(52,61,66);" //should be matdesign -= 5 which is 52,61,66
                                                "color: white;"
                                                "font: 20px;"
                                                "padding: 6px;"
                                                "border: none;"
                                                ));

    connect(pKeyButton, SIGNAL(clicked()), parent, SLOT(keyPressed()));
}

ScreenKey::~ScreenKey(){}

void ScreenKey::keyPressed()
{

}

