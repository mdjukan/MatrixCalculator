#ifndef MATRIX_H
#define MATRIX_H
#include <QVector>

class Matrix
{
public:
    Matrix(int rows, int cols);
    int rows() const;
    int cols() const;
    bool dimsEqual(const Matrix &m) const;
    void setElement(int i, int j, int x);
    int getElement(int i, int j) const;
    QString toString() const;
    bool canMul(const Matrix &m) const;
private:
    int m_rows;
    int m_cols;
    QVector<QVector<int>> m_data;
};

Matrix operator*(const Matrix &m1, const Matrix &m2);
Matrix operator+(const Matrix &m1, const Matrix &m2);
Matrix operator-(const Matrix &m1, const Matrix &m2);


#endif // MATRIX_H
