// bookmarkdialog.h
#ifndef BOOKMARKDIALOG_H
#define BOOKMARKDIALOG_H

#include <QDialog>
#include <QMap>
#include <QListWidget>

class BookmarkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookmarkDialog(const QMap<QString, int> &bookmarks, QWidget *parent = nullptr);
    int selectedLineNumber() const;

private slots:
    void onItemClicked(QListWidgetItem *item);

private:
    QListWidget *listWidget;
    int lineNumber;
};

#endif // BOOKMARKDIALOG_H
