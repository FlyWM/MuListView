#include <QStandardItemModel>
#include <QObject>
#include "Widget.h"
#include "ui_Widget.h"
#include "MuListItemData.h"
#include "MuItemDelegate.h"

const QStringList icons = {
    ":/images/HotDog.jpg", ":/images/li.jpg", ":/images/logo.jpg",
    ":/images/PACT.jpg", ":/images/yang.jpg", ":/images/zhang.jpg",
};
const QStringList singers = {
    "MC-Hotdog", "李荣浩", "Author",
    "PACT", "杨千嬅", "张震岳",
};

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStandardItemModel *pModel = new QStandardItemModel();
    for (int i=0; i<icons.size(); ++i) {
        QStandardItem *pItem = new QStandardItem;
        MuItemData itemData;
        itemData.singer = singers.at(i);
        itemData.songsNb = QString::number(i * i) + "首";
        itemData.iconPath = icons.at(i);
        pItem->setData(QVariant::fromValue(itemData), Qt::UserRole+1);
        pModel->appendRow(pItem);
    }

    MuItemDelegate *pItemDelegate = new MuItemDelegate(this);
    ui->listView->setItemDelegate(pItemDelegate);
    ui->listView->setModel(pModel);
}

Widget::~Widget()
{
    delete ui;
}
