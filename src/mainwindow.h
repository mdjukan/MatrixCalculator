#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "matrixdisplay.h"
#include "buttons.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MatrixDisplay *m_disp1;
    MatrixDisplay *m_disp2;
    Buttons *m_buttons;
    QTextEdit *m_result;

public slots:
    void mulClicked();
    void addClicked();
    void subClicked();

    void detClicked(MatrixDisplay *md);
    void inverseClicked(MatrixDisplay *md);
    void tpClicked(MatrixDisplay *md);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
