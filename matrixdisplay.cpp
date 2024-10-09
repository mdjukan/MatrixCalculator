#include "matrixdisplay.h"
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>

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

    layout->addWidget(rows, 1, 0, 1, 4);
    layout->addWidget(cols, 1, 4, 1, 4);
    layout->addWidget(m_matrix_input, 2, 0, 8, 8);


    connect(cols, &QComboBox::currentTextChanged, m_matrix_input, &MatrixInput::colChange);
    connect(rows, &QComboBox::currentTextChanged, m_matrix_input, &MatrixInput::rowChange);

    setLayout(layout);
}

Matrix MatrixDisplay::getMatrix(){
    return m_matrix_input->readMatrix();
}
