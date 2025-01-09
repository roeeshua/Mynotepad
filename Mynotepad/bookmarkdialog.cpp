// bookmarkdialog.cpp
#include "bookmarkdialog.h"
#include <QVBoxLayout>

BookmarkDialog::BookmarkDialog(const QMap<QString, int> &bookmarks, QWidget *parent)
    : QDialog(parent), lineNumber(-1)
{
    setWindowTitle("选择书签");

    listWidget = new QListWidget(this);
    for (auto it = bookmarks.begin(); it != bookmarks.end(); ++it) {
        listWidget->addItem(QString("%1: 第 %2 行").arg(it.key()).arg(it.value() + 1));
    }

    connect(listWidget, &QListWidget::itemClicked, this, &BookmarkDialog::onItemClicked);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
}

int BookmarkDialog::selectedLineNumber() const
{
    return lineNumber;
}

void BookmarkDialog::onItemClicked(QListWidgetItem *item)
{
    if (item) {
        QString text = item->text();
        int colonPos = text.indexOf(':');
        if (colonPos != -1) {
            bool ok;
            lineNumber = text.mid(colonPos + 1).trimmed().split(' ')[1].toInt(&ok);
            if (ok) {
                accept(); // 关闭对话框并返回
            }
        }
    }
}
