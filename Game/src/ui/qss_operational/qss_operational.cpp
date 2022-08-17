#include "qss_operational.h"
#include "main/mainwindow.h"

//Assumes that provided string is in fact qt url
//ex: url(:/greenLay280x100.png)
QString &QSS_OPERATIONAL::ExtractNameFromQtUrl_Ref(QString &str)
{
    //Erase "url(:/" from front
    str.erase(str.cbegin(), std::next(str.cbegin(), 6));

    //Remove extra closing brace and file format from the string
    int cnt = 0;
    for(int i = str.size() - 1; ; --i){
        if(str[i] == '.'){
            break;
        }
        ++cnt;
    }
    str.erase(std::prev(str.cend(), cnt + 1), str.cend());
    return str;
}

QString& QSS_OPERATIONAL::GetFullPathToResFromQtUrl_Ref(QString& str)
{
    str = MainWindow::GeneralResDir() + "/" + ExtractNameFromQtUrl(str);
    return str;
}

QString& QSS_OPERATIONAL::PackPathIntoQtUrl_Ref(QString& str)
{
    str.insert(0, "url(");
    str.push_back(")");
    return str;
}

QString QSS_OPERATIONAL::ExtractNameFromQtUrl(QString str)
{
    return ExtractNameFromQtUrl_Ref(str);
}

QString QSS_OPERATIONAL::GetFullPathToResFromQtUrl(QString str)
{
    return GetFullPathToResFromQtUrl_Ref(str);
}

QString QSS_OPERATIONAL::PackPathIntoQtUrl(QString str)
{
    return PackPathIntoQtUrl_Ref(str);
}
