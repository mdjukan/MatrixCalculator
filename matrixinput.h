#ifndef MATRIXINPUT_H
#define MATRIXINPUT_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QVector>
#include "matrix.h"

int const MAX_DIM = 5;

class MatrixInput : public QWidget
{
    Q_OBJECT
public:
    MatrixInput(QWidget *parent);
    void setDims(int newRows, int newCols);
    Matrix readMatrix();

private:
    int m_rows;
    int m_cols;
    QGridLayout *m_layout;
    QVector<QVector<QLineEdit*>> m_line_edits;

public slots:
    void rowChange(const QString &newRows);
    void colChange(const QString &newCols);
};

#endif // MATRIXINPUT_H
