/** Provides our implementation of the simon game.
 *
 *  Our github usernames are:
 *  FrostSpades
 *  vsicle
 *
 *  Github Repository: https://github.com/UofU-CS3505/cs3505-assignment6-FrostSpades.git
 *
 *  Creative Element: Our creative element is
 *  an addition of a new element, the radio buttons. There are two
 *  radio buttons that control the color scheme
 *  of the buttons. You can change between color
 *  schemes by changing between the buttons.
 *
 *  @author Ethan Andrews
 *  @author Vasil Vassilev
 *  @date 3/13/2024
*/

#include "mainwindow.h"
#include <QApplication>

/**Application entry point.
 *
 * @brief qMain application entry point
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
