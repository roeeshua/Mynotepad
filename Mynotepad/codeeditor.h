#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QSyntaxHighlighter>
#include <QString>
#include<QPlainTextEdit>
#include "cxxhighlighter.h"
#include <QTextCursor>
#include <QTextBlock>
#include "hyperlinkhighlighter.h"
#include <QMap>

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = nullptr, const QString &fileType = "");

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

    void addBookmark(const QString &name, int lineNumber);
    void removeBookmark(const QString &name);
    int getBookmarkLineNumber(const QString &name);
    QMap<QString, int> getBookmarks();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override; // 重写鼠标点击事件

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

public slots:
    void HLNA(bool flag);

private:
    QWidget *lineNumberArea;
    QSyntaxHighlighter *highlighter; // 添加语法高亮器
    HyperlinkHighlighter *hyperlinkHighlighter; // 添加超链接高亮器

    QMap<QString, int> bookmarks; // 书签管理器

signals:
    void hyperlinkActivated(const QUrl &url); // 添加信号声明
};

class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};

#endif // CODEEDITOR_H
