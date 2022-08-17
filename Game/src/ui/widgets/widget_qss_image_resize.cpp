#include "widget_qss_image_resize.h"
#include "main/mainwindow.h"

WIDGET_QSS_IMAGE_RESIZE::WIDGET_QSS_IMAGE_RESIZE(QString &qss, TMP_FILES *tmp_files_stack) : qss(qss), tmp_files_stack(tmp_files_stack)
{
    FillInImagesResList();
}

QString WIDGET_QSS_IMAGE_RESIZE::ResizeAllAndBindToQss(const int new_w, const int new_h) noexcept
{
    QString new_qss = qss;
    int idx_extra_diff = 0;
    for(const auto& [idx, brg_path]: backgrounds){
        //TO DO: Check if such image already exists here

        //Create new file with scaled pixmap
        QString full_path_to_orig = GetFullPathToResFromQtUrl(brg_path) + ".png";
        QPixmap orig_pixmap(full_path_to_orig);
        QPixmap new_pixmap = orig_pixmap.scaled(new_w, new_h);
        QString orig_file_name = ExtractNameFromQtUrl(brg_path);
        QString new_file_path = CreatePathForFile(orig_file_name, new_w, new_h);

        QFile new_file(new_file_path);
        if(!new_file.open(QIODevice::WriteOnly)){
            qDebug() << "File wasn't open in WIDGET_QSS_IMAGE_RESIZE::ResizeAllAndBindToQss(), path: " << new_file.fileName() << ", error: " << new_file.errorString();
        }
        //QDataStream out(&new_file);
        //out << new_pixmap;
        new_pixmap.save(&new_file, "PNG");
        new_file.close();

        //Adjust qss
        int cur_url_length = 0;
        int correct_idx = idx + idx_extra_diff;
        for(int i = correct_idx; ; ++i){
            if(new_qss[i] == ';'){
                break;
            }
            ++cur_url_length;
        }
        new_qss.erase(std::next(new_qss.cbegin(), correct_idx), std::next(new_qss.cbegin(), correct_idx + cur_url_length));
        QString string_to_insert_into_qss = " " + PackPathIntoQtUrl(new_file_path);
        new_qss.insert(correct_idx, string_to_insert_into_qss);
        idx_extra_diff += (string_to_insert_into_qss.size() - cur_url_length);

        //Save new file path to stack of temporary files
        tmp_files_stack->Add(new_file_path);
    }

    return new_qss;
}

void WIDGET_QSS_IMAGE_RESIZE::FillInImagesResList() noexcept
{
    const QString qss_background_str = " background-image:";
    int last_idx = 0;
    while(true){
        int cur_idx = qss.indexOf(qss_background_str, last_idx);
        if(cur_idx == -1){
            break;
        }
        int cur_idx_for_res = qss_background_str.length() + cur_idx;
        last_idx = cur_idx_for_res;
        QString cur_res = ExtractResPathFromIdx(cur_idx_for_res);
        cur_res = NormalizePathString(cur_res);
        backgrounds.push_back({cur_idx_for_res, cur_res});
    }
}

QString WIDGET_QSS_IMAGE_RESIZE::ExtractResPathFromIdx(int idx) const noexcept
{
    QString path;
    for(int i = idx; ;++i){
        if(qss[i] == ';'){
            break;
        }
        path += qss[i];
    }
    return path;
}

QString WIDGET_QSS_IMAGE_RESIZE::NormalizePathString(QString str) const noexcept
{
    while(str.front() == ' '){
        str.erase(str.cbegin(), std::next(str.cbegin()));
    }
    return str;
}

QString WIDGET_QSS_IMAGE_RESIZE::CreatePathForFile(const QString &orig_file_name, int new_h, int new_y) const noexcept
{
    QString new_path = MainWindow::ProjectDir();
    //qDebug() << "path:; " << core_dir;
    new_path += "/Resources/tmp_images/" + orig_file_name + "_" + QString::number(new_h) + "x" + QString::number(new_y) + ".png";
    return new_path;
}

//Assumes that provided string is in fact qt url
//ex: url(:/greenLay280x100.png)
QString WIDGET_QSS_IMAGE_RESIZE::ExtractNameFromQtUrl(QString str) const
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

QString WIDGET_QSS_IMAGE_RESIZE::GetFullPathToResFromQtUrl(QString str) const
{
    return MainWindow::GeneralResDir() + "/" + ExtractNameFromQtUrl(str);
}

QString WIDGET_QSS_IMAGE_RESIZE::PackPathIntoQtUrl(QString str) const
{
    str.insert(0, "url(");
    str.push_back(")");
    return str;
}
