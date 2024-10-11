#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <Eigen/Dense>
#include "matrixdisplay.h"
#include "buttons.h"
#include "utils.h"

int const DISP_HEIGHT = 250;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *central_widget = new QWidget();
    QGridLayout *layout = new QGridLayout();
    central_widget->setLayout(layout);

    m_disp1 = new MatrixDisplay(this, "Matrix A");
    m_disp1->setFixedHeight(DISP_HEIGHT);
    m_disp2 = new MatrixDisplay(this, "Matrix B");
    m_disp2->setFixedHeight(DISP_HEIGHT);

    m_buttons = new Buttons(this);

    m_result = new QTextEdit(this);
    m_result->setReadOnly(true);

    layout->addWidget(m_disp1, 0, 0, 1, 1);
    layout->addWidget(m_buttons, 0, 1, 1, 1);
    layout->addWidget(m_disp2, 0, 2, 1, 1);

    layout->addWidget(m_result, 1, 0, 4, 3);

    setCentralWidget(central_widget);
    //Ovo bi trebalo prepraviti da prosledjuje signale
    connect(m_buttons->m_add, &QPushButton::clicked, this, &MainWindow::addClicked);
    connect(m_buttons->m_sub, &QPushButton::clicked, this, &MainWindow::subClicked);
    connect(m_buttons->m_mul, &QPushButton::clicked, this, &MainWindow::mulClicked);

    connect(m_disp1, &MatrixDisplay::detClicked, this, &MainWindow::detClicked);
    connect(m_disp2, &MatrixDisplay::detClicked, this, &MainWindow::detClicked);
    connect(m_disp1, &MatrixDisplay::inverseClicked, this, &MainWindow::inverseClicked);
    connect(m_disp2, &MatrixDisplay::inverseClicked, this, &MainWindow::inverseClicked);
    connect(m_disp1, &MatrixDisplay::tpClicked, this, &MainWindow::tpClicked);
    connect(m_disp2, &MatrixDisplay::tpClicked, this, &MainWindow::tpClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::inverseClicked(MatrixDisplay *md)
{
    Eigen::MatrixXd m = md->getMatrix();
    if (m.rows()==m.cols()) {
        m_result->setText(Utils::matrixToString(m.inverse()));
    } else {
        m_result->setText("Matrix is not square!");
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
