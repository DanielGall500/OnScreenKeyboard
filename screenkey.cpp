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

                                                "QPushButton::pressed {"
                                                "background-color: rgb(224,0,0);"
                                                "border-style: inset;"
                                                "}"
                                                ));
    //setting up keyboard event
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; //hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x41; //0x41 is hex number for "a" key
    ip.ki.dwFlags = 0; //0 for key press

    //handle = QWidget::effectiveWinId();

    connect(pKeyButton, SIGNAL(clicked()), this, SLOT(keyPressed()));
}
ScreenKey::~ScreenKey(){}

void ScreenKey::keyPressed()
{
    SetWindowPos(windowHandle, HWND_TOP, 0,0,0,0, SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
    //Press the "a" key
    SendInput(1, &ip, sizeof(INPUT));

    //Release the "a" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; //for key release

    SendInput(1,&ip,sizeof(INPUT));


}











