#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>

SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit * textEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    ptextEdit=textEdit;

    ui->rbDown->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btFindnext_clicked()
{
    QString target=ui->lineEdit->text();

    if(target==""||ptextEdit==nullptr)
        return;

    QString text=ptextEdit->toPlainText();
    QTextCursor c=ptextEdit->textCursor();
    int index=-1;

    if(ui->rbDown->isChecked()){
        index=text.indexOf(target,c.position(),ui->sen->isChecked()? Qt::CaseSensitive :Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);

            ptextEdit->setTextCursor(c);
        }
    }else if(ui->rbUp->isChecked()){
        index=text.lastIndexOf(target,c.position()-text.length()-1,ui->sen->isChecked()? Qt::CaseSensitive :Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index+target.length());
            c.setPosition(index,QTextCursor::KeepAnchor);

            ptextEdit->setTextCursor(c);
        }
    }

    if(index<0){
        QMessageBox msg(this);
        msg.setWindowTitle("..");
        msg.setText("找不到"+target);
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
}


void SearchDialog::on_btCancel_clicked()
{
    accept();
}

