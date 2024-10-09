#ifndef MATRIXDISPLAY_H
#define MATRIXDISPLAY_H

#include "matrixinput.h"
#include <QWidget>

class MatrixDisplay : public QWidget {
    Q_OBJECT
public:
    MatrixDisplay(QWidget *parent, const QString &title);
    Matrix getMatrix();
private:
    QString m_title;
    MatrixInput *m_matrix_input;
};

#endif // MATRIXDISPLAY_H
