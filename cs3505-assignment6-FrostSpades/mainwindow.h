/*
 * Interface for the main window.
 *
 * CS3505
 * @date 03/13/2024
 * @author Ethan Andrews
 * @author Vasil Vassilev
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/** Class that represents the view and controller
 *  of the application.
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** QT constructor;
     * @brief MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    // Default deconstructor
    ~MainWindow();


private slots:
    /**
     * @brief on_redButton_clicked
     * Slot that gets triggered when red button is clicked.
     */
    void on_redButton_clicked();

    /**
     * @brief on_blueButton_clicked
     * Slot that is triggered when blue button is clicked.
     */
    void on_blueButton_clicked();

    /**
     * @brief on_startButton_clicked
     * Slot that is triggered when start button is clicked
     */
    void on_startButton_clicked();

    /**
     * @brief on_brRadioButton_clicked
     * Slot that is triggered when blue/red radio button is clicked
     */
    void on_brRadioButton_clicked();

    /**
     * @brief on_ypRadioButton_clicked
     * Slot that is triggered when yellow/purple radio button is clicked
     */
    void on_ypRadioButton_clicked();

public slots:
    /**
     * @brief glowButton
     * Causes a button to glow up
     *
     * @param buttonId the id of the button to glow
     * @param timeToBeLit the amount of time for it to glow
     */
    void glowButton(int buttonId, int timeToBeLit);

    /**
     * @brief resetColors
     * Resets the button colors.
     */
    void resetColors();

    /**
     * @brief disableGameButtons
     * Disables the game buttons.
     */
    void disableGameButtons();

    /**
     * @brief enableStartButton
     * Enables the start button.
     */
    void enableStartButton();

    /**
     * @brief disableStartButton
     * Disables the start button.
     */
    void disableStartButton();

    /**
     * @brief enableGameOverScreen
     * Enables the game over graphic.
     */
    void enableGameOverScreen();

    /**
     * @brief disableGameOverScreen
     * Disables the game over graphic.
     */
    void disableGameOverScreen();

    /**
     * @brief changeStartButtonText
     * Changes the text of the start button.
     *
     * @param newName the text to change it to
     */
    void changeStartButtonText(QString newName);

    /**
     * @brief changeProgressBarPercentage
     * Changes the percentage of the progress bar.
     *
     * @param newPercentage the new percentage
     */
    void changeProgressBarPercentage(int newPercentage);

private:
    Ui::MainWindow *ui;
    Model model;
    // stores the current color scheme
    int currentColors;

    /**
     * @brief enableGameButtons
     * Enables the current game buttons.
     */
    void enableGameButtons();

signals:
    /**
     * @brief startButtonPressed
     * Signal when start button is pressed
     */
    void startButtonPressed();

    /**
     * @brief playerSelectionComplete
     * Signals when player selection is complete
     * @param selection the player's selection button id
     */
    void playerSelectionComplete(int selection);
};
#endif // MAINWINDOW_H
