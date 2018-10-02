#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_play_clicked()
{

}

void MainWindow::on_pushButton_select_filepath_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select BVH file"), "/home", tr("BVH Files (*.bvh *.BVH *.Bvh)"));
    ui->lineEdit_filepath->setText(fileName);
}
