#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter> //painter
#include <QKeyEvent>
#include "draw.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //--------------------------------------
    void paintEvent(QPaintEvent*);
    void connectWithGame(GameManager *g);

    void keyPressEvent(QKeyEvent *event);
private:
    GameManager *game;
    Draw *draw;
    Ui::Dialog *ui;
    int fps;
};

#endif // DIALOG_H
