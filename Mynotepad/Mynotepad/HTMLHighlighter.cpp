#include "htmlhighlighter.h"

HTMLHighlighter::HTMLHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // 标签格式
    tagFormat.setForeground(Qt::darkBlue);
    tagFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("<\\s*\\/?(\\w+)");
    rule.format = tagFormat;
    highlightingRules.append(rule);

    // 属性格式
    attributeFormat.setForeground(Qt::darkRed);
    rule.pattern = QRegularExpression("\\b[A-Za-z0-9_]+(?=\\=)");
    rule.format = attributeFormat;
    highlightingRules.append(rule);

    // 属性值格式
    valueFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\".*?\"");
    rule.format = valueFormat;
    highlightingRules.append(rule);

    // 注释格式
    commentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression("<!--.*?-->");
    rule.format = commentFormat;
    highlightingRules.append(rule);
}

void HTMLHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
