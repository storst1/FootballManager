#include "tmp_files.h"

TMP_FILES::TMP_FILES()
{

}

TMP_FILES::~TMP_FILES()
{

}

void TMP_FILES::Add(QString &path) noexcept
{
    files.push_back(path);
}
