#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog *w;
    w = new Dialog;

    GameManager *game = new GameManager();
    w->connectWithGame(game);

    w->show();

    return a.exec();
}
