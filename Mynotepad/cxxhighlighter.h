#ifndef CXXHIGHLIGHTER_H
#define CXXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class CxxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    CxxHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // CXXHIGHLIGHTER_H
