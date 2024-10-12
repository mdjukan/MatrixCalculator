#include "matrixinput.h"
#include <Eigen/Dense>

const int LE_WIDTH = 30;
const int LE_HEIGHT = 30;
const int WIDTH = 200;
const int HEIGHT = 200;

MatrixInput::MatrixInput(QWidget *parent) : QWidget(parent) {
    this->setFixedHeight(HEIGHT);
    m_layout = new QGridLayout(this);
    setLayout(m_layout);
    m_line_edits.resize(MAX_DIM);
    for (int i=0; i<MAX_DIM; i++) {
        m_line_edits[i].resize(MAX_DIM);
    }
    m_rows = 0;
    m_cols = 0;
    setDims(1, 1);
}

void MatrixInput::setDims(int newRows, int newCols)
{
    Q_ASSERT(1<=newRows && newRows<=MAX_DIM);
    Q_ASSERT(1<=newCols && newCols<=MAX_DIM);

    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            delete m_line_edits[i][j];
        }
    }

    m_rows = newRows;
    m_cols = newCols;

    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            m_line_edits[i][j] = new QLineEdit();
        }
    }

    delete m_layout;
    m_layout = new QGridLayout(this);
    setLayout(m_layout);

    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            m_line_edits[i][j]->setText("0");
            m_line_edits[i][j]->setFixedSize(LE_WIDTH, LE_HEIGHT);
            m_layout->addWidget(m_line_edits[i][j], i, j, 1 , 1);
        }
    }
}

void MatrixInput::rowChange(const QString &newRows)
{
    setDims(newRows.toInt(), m_cols);
}

void MatrixInput::colChange(const QString &newCols)
{
    setDims(m_rows, newCols.toInt());
}

Eigen::MatrixXd MatrixInput::readMatrix() {
    Eigen::MatrixXd matrix(m_rows, m_cols);

    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            matrix(i,j) = m_line_edits[i][j]->text().toDouble();
        }
    }

    return matrix;
}
