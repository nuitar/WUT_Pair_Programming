#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resource.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    time.setInterval(250);
    ui->setupUi(this);
    connect(this->ui->btnNext, &QPushButton::clicked, this->ui->widget, &gridMap::updateNext);
    connect(this->ui->btnStart, &QPushButton::clicked, [&] {
        if (time.isActive()) {
            time.stop();
            this->ui->btnStart->setText("Start");
        }
            
        else {
            time.start();
            this->ui->btnStart->setText("End");
        }
    });
    connect(this->ui->btnReset, &QPushButton::clicked, this->ui->widget, &gridMap::reset);
    connect(this->ui->btnRandom, &QPushButton::clicked, this->ui->widget, &gridMap::random);
    connect(&this->time, &QTimer::timeout, this->ui->widget, &gridMap::updateNext);
    this->setWindowTitle("Game of life");
    this->setWindowIcon(QIcon("res/font.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}



