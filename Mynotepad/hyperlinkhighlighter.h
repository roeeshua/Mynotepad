// hyperlinkhighlighter.h
#ifndef HYPERLINKHIGHLIGHTER_H
#define HYPERLINKHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class HyperlinkHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    HyperlinkHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

signals:
    void hyperlinkActivated(const QUrl &url);
};

#endif // HYPERLINKHIGHLIGHTER_H
