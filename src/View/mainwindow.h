#ifndef SRC_MAINWINDOW_H_
#define SRC_MAINWINDOW_H_

#include <qcustomplot.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <string>

#include "../Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_subtracting_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_division_clicked();

    void on_pushButton_leftBracket_clicked();

    void on_pushButton_rightBracket_clicked();

    void on_pushButton_x_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_atan_clicked();

    void on_pushButton_acos_clicked();

    void on_pushButton_asin_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_AC_clicked();

    void on_pushButton_degree_clicked();

    void on_pushButton_answer_clicked();

    void on_pushButton_Graphics_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> x, y;
};
#endif  // SRC_MAINWINDOW_H_
