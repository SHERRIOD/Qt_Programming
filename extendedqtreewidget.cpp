#include "extendedqtreewidget.h"
#include<QDebug>
#include<iostream>
#include<QTreeWidgetItem>
extendedQTreeWidget::extendedQTreeWidget(QWidget *parent) : QTreeWidget(parent)
{
    this->clear();
    this->setFixedSize(256,192);
    connect(this,&QTreeWidget::itemChanged,this,&extendedQTreeWidget::TreeItemChanged);
}

QTreeWidgetItem *extendedQTreeWidget::addGroup(QString name)
{
    QTreeWidgetItem* temp=new QTreeWidgetItem(this);
    temp->setText(0,name);
    temp->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    temp->setCheckState(0,Qt::Unchecked);
    return temp;
}

QTreeWidgetItem *extendedQTreeWidget::addSubItem(QString name, QTreeWidgetItem *father)
{
    QTreeWidgetItem* temp=new QTreeWidgetItem(father);
    temp->setText(0,name);
    temp->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    temp->setCheckState(0,Qt::Unchecked);
    return temp;
}

void extendedQTreeWidget::TreeItemChanged(QTreeWidgetItem *item,int col)
{
    QString itemText=item->text(0);
    //选中时
    static int ii=0;
    qDebug()<<QString("%1 time in the TreeItemChanged").arg(ii++);
    if(Qt::Checked==item->checkState(0)){
        QTreeWidgetItem* parent=item->parent();
        int count=item->childCount();//判断是否是子节点
        if(count>0){
            for(int i=0;i<count;i++){
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else{
            //child
            updateParent(item);
        }
    }
    else{
        if(Qt::Unchecked==item->checkState(0)){
            int count=item->childCount();
            if(count>0){
                for(int i=0;i<count;i++){
                    item->child(i)->setCheckState(0,Qt::Unchecked);
                }
            }
            else{
                updateParent(item);
            }
        }

    }
}

void extendedQTreeWidget::updateParent(QTreeWidgetItem *item)
{
    QTreeWidgetItem* parent=item->parent();
    if(parent==NULL){
        return;
    }
    static int ii=0;
    qDebug()<<QString("%1 time in the updateParent").arg(ii++);
    int selectedCount=0;
    int childCount=parent->childCount();
    for(int i=0;i<childCount;i++){
        QTreeWidgetItem* childItem=parent->child(i);
        if(childItem->checkState(0)==Qt::Checked){
            selectedCount++;
        }
    }
    if(selectedCount<=0){
        parent->setCheckState(0,Qt::Unchecked);

    }
    else if(selectedCount>0&&selectedCount<childCount){
        //部分选中
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectedCount==childCount){
        //选中状态
        parent->setCheckState(0,Qt::Checked);
    }
}




