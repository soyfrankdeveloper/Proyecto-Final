#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(1000,600);

    juego.iniciarJuego();

    escena = new EscenaJuego();

    escena->inicializarEscena();

    ui->graphicsView->setScene(escena);

    ui->graphicsView->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}