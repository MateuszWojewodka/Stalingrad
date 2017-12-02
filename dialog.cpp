#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    draw = new Draw();
    draw->loadPixMaps();

    //ustawianie FPSOW
    fps = 60;

    //timer
    QTimer *draw_timer = new QTimer;
    connect(draw_timer, SIGNAL(timeout()), this, SLOT(update()));
    draw_timer->start( int( 1000 / fps ) );
}

Dialog::~Dialog()
{
    delete ui;
    delete draw;
}

void Dialog::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    draw->drawElements(painter, game);
}

void Dialog::connectWithGame(GameManager *g)
{
    game = g;
    this->setFixedSize(game->getSandboxPpos().x + game->getSandboxSize().x,
                       game->getSandboxPpos().y + game->getSandboxSize().y);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    Player *p = game->getPlayer();
    if (event->key() == Qt::Key_Left) p->left_spin();
    else if (event->key() == Qt::Key_Right) p->right_spin();
    else if (event->key() == Qt::Key_Space) p->attack();
}
