#include "screenkey.h"

ScreenKey::ScreenKey(const QString &letter, QWidget *parent) : QWidget(parent)
{
    pKeyLetter = &letter;
    pKeyButton = new QPushButton(letter, parent);


}

ScreenKey::~ScreenKey()
{

}

