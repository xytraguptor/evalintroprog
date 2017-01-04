#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QDialog>
#include "QFileSystemModel"
#include "qfexsearch.h"
#include <QObject>

namespace Ui {
class SearchForm;
}

class SearchForm : public QDialog
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = 0);
    ~SearchForm();
    void setCurrentPath(QString);

private slots:
    void enableButtons(bool);
    void on_btnCancel_pressed();

    void on_btnStartSearch_released();

private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
