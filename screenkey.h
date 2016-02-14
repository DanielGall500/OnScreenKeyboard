#ifndef SCREENKEY_H
#define SCREENKEY_H

#include <QObject>
#include <QPushButton>

class ScreenKey : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenKey(const QString &letter , QWidget *parent = 0);
    ~ScreenKey();

private:
    QPushButton *pKeyButton;
    const QString *pKeyLetter;

signals:

public slots:
};

#endif // SCREENKEY_H
