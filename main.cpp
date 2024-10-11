#include "mainwindow.h"

#include <QApplication>
#include <Eigen/Dense>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Eigen::Matrix3d matrix;
    matrix << 4, 7, 2,
        3, 5, 1,
        2, 4, 6;

    // Check if the matrix is invertible by checking its determinant
    if (matrix.determinant() != 0) {
        // Calculate the inverse of the matrix
        Eigen::Matrix3d inverseMatrix = matrix.inverse();

        // Output the inverse matrix
        std::cout << "The inverse of the matrix is:\n" << inverseMatrix << std::endl;
    } else {
        std::cout << "The matrix is not invertible (determinant is 0)." << std::endl;
    }

    return a.exec();
}
