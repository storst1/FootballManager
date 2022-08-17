#ifndef QSS_OPERATIONAL_H
#define QSS_OPERATIONAL_H

#include <QString>

class QSS_OPERATIONAL
{
public:
    static QString ExtractNameFromQtUrl(QString str);
    static QString GetFullPathToResFromQtUrl(QString str);
    static QString PackPathIntoQtUrl(QString str);
    static QString& ExtractNameFromQtUrl_Ref(QString& str);
    static QString& GetFullPathToResFromQtUrl_Ref(QString& str);
    static QString& PackPathIntoQtUrl_Ref(QString& str);
};

#endif // QSS_OPERATIONAL_H
