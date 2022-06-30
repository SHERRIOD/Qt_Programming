#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"extendedqtreewidget.h"
#include<QTreeWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    extendedQTreeWidget* treeWidget=new extendedQTreeWidget(this);
    QTreeWidgetItem* group1=treeWidget->addGroup("老八");
    treeWidget->addSubItem("蜜汁",group1);
    treeWidget->addSubItem("小汉堡",group1);
    QTreeWidgetItem* group2=treeWidget->addGroup("老八");

}

MainWindow::~MainWindow()
{
    delete ui;
}

