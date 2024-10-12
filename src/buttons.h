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
private:
    QPushButton *m_add;
    QPushButton *m_mul;
    QPushButton *m_sub;
    QGridLayout *m_layout;
public:
signals:
    void addClicked();
    void mulClicked();
    void subClicked();
};

#endif // BUTTONS_H
