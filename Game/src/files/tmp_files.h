#ifndef TMP_FILES_H
#define TMP_FILES_H

#include <QStringList>
#include <QFile>

class TMP_FILES
{
public:
    TMP_FILES();
    ~TMP_FILES();

    void Add(QString& path) noexcept;
    void DeleteAllFiles() noexcept;
private:
    QStringList files;
};

#endif // TMP_FILES_H
