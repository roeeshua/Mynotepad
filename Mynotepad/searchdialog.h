#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr,QPlainTextEdit * textEdit=nullptr);
    ~SearchDialog();

private slots:
    void on_btFindnext_clicked();

    void on_btCancel_clicked();

private:
    Ui::SearchDialog *ui;

    QPlainTextEdit * ptextEdit;
};

#endif // SEARCHDIALOG_H
