#ifndef MULISTITEMDATA_H
#define MULISTITEMDATA_H

#include <QMetaType>

typedef struct {
    QString iconPath;
    QString singer;
    QString songsNb;
} MuItemData;

Q_DECLARE_METATYPE(MuItemData)

#endif // MULISTITEMDATA_H
