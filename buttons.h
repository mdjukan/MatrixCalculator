#ifndef BUTTONS_H
#define BUTTONS_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Buttons : public QWidget
{
    Q_OBJECT
public:
    Buttons(QWidget *parent=nullptr);
public:
    QPushButton *m_add;
    QPushButton *m_mul;
    QPushButton *m_sub;
private:
    QGridLayout *m_layout;
};

#endif // BUTTONS_H
