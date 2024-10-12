#include "buttons.h"

int const BTN_WIDTH = 60;
int const BTN_HEIGHT = 30;

Buttons::Buttons(QWidget *parent) : QWidget(parent) {
    m_add = new QPushButton("A+B", this);
    m_mul = new QPushButton("A*B", this);
    m_sub = new QPushButton("A-B", this);
    m_layout = new QGridLayout(this);

    m_add->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    m_sub->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    m_mul->setFixedSize(BTN_WIDTH, BTN_HEIGHT);

    this->setLayout(m_layout);

    m_layout->addWidget(m_add, 0, 0, 1, 1);
    m_layout->addWidget(m_sub, 1, 0, 1, 1);
    m_layout->addWidget(m_mul, 2, 0, 1, 1);

    connect(m_add, &QPushButton::clicked, this, &Buttons::addClicked);
    connect(m_mul, &QPushButton::clicked, this, &Buttons::mulClicked);
    connect(m_sub, &QPushButton::clicked, this, &Buttons::subClicked);
}
