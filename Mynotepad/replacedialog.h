#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr,QPlainTextEdit *textEdit=nullptr);
    ~ReplaceDialog();

private slots:
    void on_btFindnext_clicked();

    void on_btReplace_clicked();

    void on_btReplaceAll_clicked();

    void on_btCancel_clicked();

private:
    Ui::ReplaceDialog *ui;

    QPlainTextEdit * ptextEdit;
};

#endif // REPLACEDIALOG_H
