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


public slots:
    void glowButton(int buttonId, int timeToBeLit);
    //void unGlowButtons();
    void resetColors();
    void disableGameButtons();
    void enableStartButton();
    void disableStartButton();
    void enableGameOverScreen();
    void disableGameOverScreen();
    void changeStartButtonText(QString newName);
    void changeProgressBarPercentage(int newPercentage);

private:
    Ui::MainWindow *ui;
    Model model;


    void enableGameButtons();
    void recurse(std::vector<int> colorList, int currentColor);
    void wait(std::vector<int> colorList, int currentColor);
    void wait();

signals:
    void startButtonPressed();
    void buttonLightingComplete();
    void playerSelectionComplete(int selection);
};
#endif // MAINWINDOW_H
