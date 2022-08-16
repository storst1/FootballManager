#ifndef WIDGET_QSS_IMAGE_RESIZE_H
#define WIDGET_QSS_IMAGE_RESIZE_H

#include "files/tmp_files.h"

#include <QString>
#include <QStringList>
#include <QVector>
#include <QPixmap>
#include <QFileInfo>
#include <QDir>

class WIDGET_QSS_IMAGE_RESIZE
{
public:
    WIDGET_QSS_IMAGE_RESIZE(QString& qss, TMP_FILES* tmp_files_stack);
    ~WIDGET_QSS_IMAGE_RESIZE() = default;

    QString ResizeAllAndBindToQss(const int new_w, const int new_h) noexcept;
private:
    void FillInImagesResList() noexcept;
    QString ExtractResPathFromIdx(int idx) const noexcept;
    QString NormalizePathString(QString str) const noexcept;
    QString CreatePathForFile(const QString& orig_file_name, int new_h, int new_y) const noexcept;
    QString ExtractNameFromQtUrl(QString str) const;
    QString GetFullPathToResFromQtUrl(QString str) const;
private:
    QString qss;
    TMP_FILES* tmp_files_stack;
    QVector<QPair<int, QString>> backgrounds;
};

#endif // WIDGET_QSS_IMAGE_RESIZE_H
