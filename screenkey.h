#ifndef SCREENKEY_H
#define SCREENKEY_H

#include <QObject>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QStyle>
#include <QEvent>
#include <QKeyEvent>
#include <w32api.h>
#include <windows.h>
#include <winuser.h>
#include <QMouseEvent>

class ScreenKey : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenKey(const QString &letter , QWidget *parent = 0);
    ~ScreenKey();

    QString getLetter() { return *pKeyLetter;   }
    void    setLetter(const QString &letter) { pKeyLetter = &letter; }

private:
    QPushButton *pKeyButton;
    const QString *pKeyLetter;

    HWND windowHandle;
    WId handle;
    INPUT ip;

    QTimer *timer;

signals:

public slots:
    void keyPressed();

};

#endif // SCREENKEY_H
