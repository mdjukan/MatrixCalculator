#include "matrixdisplay.h"
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>

MatrixDisplay::MatrixDisplay(QWidget *parent, const QString &title) : QWidget(parent), m_title(title)
{
    m_matrix_input = new MatrixInput(this);
    QGridLayout *layout = new QGridLayout();

    QLabel *label = new QLabel(this);
    label->setText(title);

    layout->addWidget(label, 0, 0, 1, 8);

    QComboBox *rows = new QComboBox(this);
    QComboBox *cols = new QComboBox(this);

    for (int i=0; i<MAX_DIM; i++) {
        rows->addItem(QString::number(i+1));
        cols->addItem(QString::number(i+1));
    }

    //Ova tri dugmenta treba da budu u zasebnoj komponenti!
    m_inverse = new QPushButton("Inverse");
    m_det = new QPushButton("Determinant");
    m_tp = new QPushButton("Transpose");

    layout->addWidget(rows, 1, 0, 1, 4);
    layout->addWidget(cols, 1, 4, 1, 4);
    layout->addWidget(m_matrix_input, 2, 0, 8, 8);

    layout->addWidget(m_inverse, 11, 0, 1, 8);
    layout->addWidget(m_det, 12, 0, 1, 8);
    layout->addWidget(m_tp, 13, 0, 1, 8);


    connect(cols, &QComboBox::currentTextChanged, m_matrix_input, &MatrixInput::colChange);
    connect(rows, &QComboBox::currentTextChanged, m_matrix_input, &MatrixInput::rowChange);

    connect(m_inverse, &QPushButton::clicked, this, &MatrixDisplay::onInverseClick);
    connect(m_det, &QPushButton::clicked, this, &MatrixDisplay::onDetClick);
    connect(m_tp, &QPushButton::clicked, this, &MatrixDisplay::onTpClick);

    setLayout(layout);
}

Eigen::MatrixXd MatrixDisplay::getMatrix(){
    return m_matrix_input->readMatrix();
}

void MatrixDisplay::onInverseClick() {
    emit inverseClicked(this);
}

void MatrixDisplay::onDetClick() {
    emit detClicked(this);
}

void MatrixDisplay::onTpClick(){
    emit tpClicked(this);
}
