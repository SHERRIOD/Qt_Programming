#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"extendedqtreewidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTreeWidgetItem* group1=ui->treeWidget->addGroup("老八");
    ui->treeWidget->addSubItem("蜜汁",group1);
    ui->treeWidget->addSubItem("小汉堡",group1);
    QTreeWidgetItem* group2=ui->treeWidget->addGroup("老八");

}

MainWindow::~MainWindow()
{
    delete ui;
}

