#ifndef FILEPROPERTIES_H
#define FILEPROPERTIES_H

#include <QDialog>
#include "QFileSystemModel"
#include "QAbstractButton"

namespace Ui {
class FileProperties;
}

class FileProperties : public QDialog
{
    Q_OBJECT

public:
    explicit FileProperties(QWidget *parent = 0, QList<QFileInfo> *files = NULL);
    ~FileProperties();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::FileProperties *ui;
    QList<QFileInfo> *fileInfoList;
    void setFormData();
};

#endif // FILEPROPERTIES_H
