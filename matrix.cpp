#include "matrix.h"

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
    m_data.resize(m_rows);
    for (int i=0; i<m_rows; i++) {
        m_data[i].resize(m_cols);
    }
}

int Matrix::rows() const
{
    return m_rows;
}

int Matrix::cols() const
{
    return m_cols;
}

bool Matrix::dimsEqual(const Matrix &m) const {
    return m_rows==m.rows() && m_cols==m.cols();
}

bool Matrix::canMul(const Matrix &m) const {
    return m_cols==m.rows();
}

void Matrix::setElement(int i, int j, int x)
{
    m_data[i][j] = x;
}

int Matrix::getElement(int i, int j) const
{
    return m_data[i][j];
}

QString Matrix::toString() const
{
    QString s("");
    for (int i=0; i<m_rows; i++) {
        for (int j=0; j<m_cols; j++) {
            s += QString::number(m_data[i][j]) + QString("  ");
        }

        s += QString("\n");
    }

    return s;
}

Matrix operator-(const Matrix &m1, const Matrix &m2) {
    Matrix result(m1.rows(), m1.cols());
    for (int i=0; i<m1.rows(); i++) {
        for (int j=0; j<m1.cols(); j++) {
            int v1 = m1.getElement(i ,j);
            int v2 = m2.getElement(i, j);
            result.setElement(i, j, v1 - v2);
        }
    }

    return result;
}

Matrix operator+(const Matrix &m1, const Matrix &m2) {
    Matrix result(m1.rows(), m1.cols());
    for (int i=0; i<m1.rows(); i++) {
        for (int j=0; j<m1.cols(); j++) {
            int v1 = m1.getElement(i ,j);
            int v2 = m2.getElement(i, j);
            result.setElement(i, j, v1 + v2);
        }
    }

    return result;
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
    Matrix result(m1.rows(), m2.cols());
    for (int i=0; i<m1.rows(); i++) {
        for (int j=0; j<m2.cols(); j++) {
            int val = 0;
            for (int k = 0; k<m1.cols(); k++) {
                val += m1.getElement(i, k) * m2.getElement(k, j);
            }
            result.setElement(i, j, val);
        }
    }

    return result;
}
