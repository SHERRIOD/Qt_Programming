#include "extendedqtreewidget.h"

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

void extendedQTreeWidget::TreeItemChanged(QTreeWidgetItem *item)
{
    //QString itemText=item->text(0);
    if(Qt::Checked==item->checkState(0)){
        int cnt=item->childCount();
        if(cnt>0){
            for(int i=0;i<cnt;i++){
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else{
            updateParent(item);
        }
    }
    else{
        int cnt=item->childCount();
        if(cnt>0){
            for(int i=0;i<cnt;i++){
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else{
            updateParent(item);
        }
    }
}

void extendedQTreeWidget::updateParent(QTreeWidgetItem *item)
{
    if(item->parent()==NULL)  return;
    int selectedCnt=0;
    for(int i=0;i<item->parent()->childCount();i++){
        if(item->parent()->child(i)->checkState(0)==Qt::Checked){
            selectedCnt++;
        }
    }
    if(selectedCnt<=0){
        item->parent()->setCheckState(0,Qt::Unchecked);
    }
    else if(selectedCnt>0&&selectedCnt<item->parent()->childCount()){
        item->parent()->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectedCnt==item->parent()->childCount()){
        item->parent()->setCheckState(0,Qt::Checked);
    }
}




