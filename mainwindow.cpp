#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include "matrixdisplay.h"
#include "buttons.h"

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
    connect(m_buttons->m_add, &QPushButton::clicked, this, &MainWindow::addClicked);
    connect(m_buttons->m_sub, &QPushButton::clicked, this, &MainWindow::subClicked);
    connect(m_buttons->m_mul, &QPushButton::clicked, this, &MainWindow::mulClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::subClicked()
{
    Matrix m1 = m_disp1->getMatrix();
    Matrix m2 = m_disp2->getMatrix();
    if (m1.dimsEqual(m2)) {
        Matrix result = m1-m2;
        m_result->setText(result.toString());
    } else {
        m_result->setText("Invalid dimensions!");
    }
}

void MainWindow::addClicked()
{
    Matrix m1 = m_disp1->getMatrix();
    Matrix m2 = m_disp2->getMatrix();
    if (m1.dimsEqual(m2)) {
        Matrix result = m1+m2;
        m_result->setText(result.toString());
    } else {
        m_result->setText("Invalid dimensions!");
    }
}

void MainWindow::mulClicked()
{
    Matrix m1 = m_disp1->getMatrix();
    Matrix m2 = m_disp2->getMatrix();
    if (m1.canMul(m2)) {
        Matrix result = m1 * m2;
        m_result->setText(result.toString());
    } else {
        m_result->setText("Invalid dimensions!");
    }
}
