#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(1000,700);

    juego.iniciarJuego();

    escena = new EscenaJuego();

    escena->inicializarEscena();

    ui->graphicsView->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete ui;
}