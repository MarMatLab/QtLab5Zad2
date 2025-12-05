#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

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

private slots:
    void calculateSquare(double val);
    void left_clicked();
    void right_clicked();
    void dateEdit_changed(const QDate &date);
    void calendar_date_changed(const QDate &date);
    void radio_clicked(int id);

    void change_red_spin(int val);
    void change_green_spin(int val);
    void change_blue_spin(int val);

    void change_red_slider_and_pixmap(int val);
    void change_green_slider_and_pixmap(int val);
    void change_blue_slider_and_pixmap(int val);

private:
    Ui::MainWindow *ui;
    void updateColor();
};
#endif // MAINWINDOW_H
