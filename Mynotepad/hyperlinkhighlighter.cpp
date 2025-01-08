// hyperlinkhighlighter.cpp
#include "hyperlinkhighlighter.h"
#include <QTextCharFormat>
#include <QTextCursor>
#include <QUrl>

HyperlinkHighlighter::HyperlinkHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
}

void HyperlinkHighlighter::highlightBlock(const QString &text)
{
    QRegularExpression urlPattern("(https?://|ftp://|mailto:)[^\\s]+");
    QRegularExpressionMatchIterator matchIterator = urlPattern.globalMatch(text);
    while (matchIterator.hasNext()) {
        QRegularExpressionMatch match = matchIterator.next();
        QTextCharFormat linkFormat;
        linkFormat.setForeground(Qt::blue);
        linkFormat.setFontUnderline(true);
        setFormat(match.capturedStart(), match.capturedLength(), linkFormat);

        // 发出信号
        QTextCursor cursor(document());
        cursor.setPosition(match.capturedStart() + currentBlock().position());
        cursor.setPosition(match.capturedStart() + currentBlock().position() + match.capturedLength(), QTextCursor::KeepAnchor);
        emit hyperlinkActivated(QUrl(match.captured()));
    }
}
