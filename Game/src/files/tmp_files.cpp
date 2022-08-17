#include "tmp_files.h"

TMP_FILES::TMP_FILES()
{

}

TMP_FILES::~TMP_FILES()
{
    for(const auto& f : files){
        QFile::remove(f);
    }
}

void TMP_FILES::Add(QString &path) noexcept
{
    files.push_back(path);
}
