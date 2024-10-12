#include "mainwindow.h"
#include <QGridLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <Eigen/Dense>
#include "matrixdisplay.h"
#include "buttons.h"
#include "utils.h"

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 700;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle("MatrixCalcuator");
    QWidget *central_widget = new QWidget();
    QGridLayout *layout = new QGridLayout();
    central_widget->setLayout(layout);

    m_disp1 = new MatrixDisplay(this, "Matrix A");
    m_disp2 = new MatrixDisplay(this, "Matrix B");

    m_buttons = new Buttons(this);

    m_result = new QTextEdit(this);
    m_result->setReadOnly(true);

    layout->addWidget(m_disp1, 0, 0, 1, 1);
    layout->addWidget(m_buttons, 0, 1, 1, 1);
    layout->addWidget(m_disp2, 0, 2, 1, 1);
    layout->addWidget(m_result, 1, 0, 4, 3);
    setCentralWidget(central_widget);

    connect(m_buttons, &Buttons::addClicked, this, &MainWindow::addClicked);
    connect(m_buttons, &Buttons::subClicked, this, &MainWindow::subClicked);
    connect(m_buttons, &Buttons::mulClicked, this, &MainWindow::mulClicked);

    connect(m_disp1, &MatrixDisplay::detClicked, this, &MainWindow::detClicked);
    connect(m_disp2, &MatrixDisplay::detClicked, this, &MainWindow::detClicked);
    connect(m_disp1, &MatrixDisplay::inverseClicked, this, &MainWindow::inverseClicked);
    connect(m_disp2, &MatrixDisplay::inverseClicked, this, &MainWindow::inverseClicked);
    connect(m_disp1, &MatrixDisplay::tpClicked, this, &MainWindow::tpClicked);
    connect(m_disp2, &MatrixDisplay::tpClicked, this, &MainWindow::tpClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::subClicked()
{
    Eigen::MatrixXd m1 = m_disp1->getMatrix();
    Eigen::MatrixXd m2 = m_disp2->getMatrix();
    if (m1.rows()==m2.rows() && m1.cols()==m2.cols()) {
        m_result->setText(Utils::matrixToString(m1-m2));
    } else {
        m_result->setText("Invalid dimensions!");
    }
}

void MainWindow::detClicked(MatrixDisplay *md)
{
    Eigen::MatrixXd m = md->getMatrix();
    if (m.rows()==m.cols()) {
        m_result->setText(QString::number(m.determinant()));
    } else {
        m_result->setText("Matrix is not square!");
    }
}

const double EPSILON = 1e-5;
void MainWindow::inverseClicked(MatrixDisplay *md)
{
    Eigen::MatrixXd m = md->getMatrix();
    if (m.rows()==m.cols() && abs(m.determinant())>EPSILON) {
        m_result->setText(Utils::matrixToString(m.inverse()));
    } else {
        m_result->setText("Matrix is not invertable!");
    }
}

void MainWindow::tpClicked(MatrixDisplay *md)
{
    Eigen::MatrixXd m = md->getMatrix();
    m_result->setText(Utils::matrixToString(m.transpose()));
}

void MainWindow::addClicked()
{
    Eigen::MatrixXd m1 = m_disp1->getMatrix();
    Eigen::MatrixXd m2 = m_disp2->getMatrix();
    if (m1.rows()==m2.rows() && m1.cols()==m2.cols()) {
        m_result->setText(Utils::matrixToString(m1+m2));
    } else {
        m_result->setText("Invalid dimensions!");
    }
}

void MainWindow::mulClicked()
{
    Eigen::MatrixXd m1 = m_disp1->getMatrix();
    Eigen::MatrixXd m2 = m_disp2->getMatrix();
    if (m1.cols()==m2.rows()) {
        m_result->setText(Utils::matrixToString(m1*m2));
    } else {
        m_result->setText("Invalid dimensions!");
    }
}
