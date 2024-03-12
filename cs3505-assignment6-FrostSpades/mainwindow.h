#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

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
    void on_redButton_clicked();

    void on_blueButton_clicked();

    void on_startButton_clicked();

    void resetColors();

    void showSequence(std::vector<int> colorList);

private:
    Ui::MainWindow *ui;
    Model model;

    void glowButton(int buttonID);
    void enableGameButtons();
    void disableGameButtons();
    void recurse(std::vector<int> colorList, int currentColor);
    void wait(std::vector<int> colorList, int currentColor);
};
#endif // MAINWINDOW_H
