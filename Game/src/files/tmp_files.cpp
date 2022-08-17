#include "tmp_files.h"

TMP_FILES::TMP_FILES()
{

}

TMP_FILES::~TMP_FILES()
{
    DeleteAllFiles();
}

void TMP_FILES::Add(QString &path) noexcept
{
    files.push_back(path);
}

void TMP_FILES::DeleteAllFiles() noexcept
{
    for(const auto& f : files){
        QFile::remove(f);
    }
    files.clear();
}
