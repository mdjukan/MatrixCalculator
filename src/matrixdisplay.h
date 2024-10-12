#ifndef MATRIXDISPLAY_H
#define MATRIXDISPLAY_H

#include "matrixinput.h"
#include <QWidget>
#include <QPushButton>
#include <Eigen/Dense>

class MatrixDisplay : public QWidget {
    Q_OBJECT
public:
    MatrixDisplay(QWidget *parent, const QString &title);
    Eigen::MatrixXd getMatrix();
private:
    QString m_title;
    MatrixInput *m_matrix_input;

    QPushButton *m_inverse;
    QPushButton *m_det;
    QPushButton *m_tp;

public:
signals:
    void inverseClicked(MatrixDisplay *md);
    void detClicked(MatrixDisplay *md);
    void tpClicked(MatrixDisplay *md);

private slots:
    void onInverseClick();
    void onDetClick();
    void onTpClick();
};

#endif // MATRIXDISPLAY_H
