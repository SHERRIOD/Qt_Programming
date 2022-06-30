#ifndef EXTENDEDQTREEWIDGET_H
#define EXTENDEDQTREEWIDGET_H

#include <QWidget>
#include<QTreeWidgetItem>
#include<QTreeWidget>
class extendedQTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    explicit extendedQTreeWidget(QWidget *parent = nullptr);
    QTreeWidgetItem *addGroup(QString name);
    QTreeWidgetItem * addSubItem(QString name,QTreeWidgetItem * father);
    void TreeItemChanged(QTreeWidgetItem* item,int col);
    void updateParent(QTreeWidgetItem* item);
signals:

};

#endif // EXTENDEDQTREEWIDGET_H
