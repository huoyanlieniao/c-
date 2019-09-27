#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_random_clicked();

    void on_pushButton_clicked();

    void on_btn_sToB_clicked();

    void on_btn_bToS_clicked();

    void on_btn_cancel_clicked();

    void on_txt_inputTxt_inputRejected();

    void on_pushButton_4_clicked();

    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H




