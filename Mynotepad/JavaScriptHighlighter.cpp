#include "javascripthighlighter.h"

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // 关键字格式
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bvar\\b" << "\\blet\\b" << "\\bconst\\b"
                    << "\\bfunction\\b" << "\\bif\\b" << "\\belse\\b"
                    << "\\bfor\\b" << "\\bwhile\\b" << "\\breturn\\b"
                    << "\\bbreak\\b" << "\\bcontinue\\b" << "\\bnew\\b"
                    << "\\btry\\b" << "\\bcatch\\b" << "\\bfinally\\b"
                    << "\\bthrow\\b" << "\\bdelete\\b" << "\\btypeof\\b"
                    << "\\binstanceof\\b" << "\\bdefault\\b" << "\\bimport\\b"
                    << "\\bexport\\b" << "\\bclass\\b" << "\\bextends\\b"
                    << "\\bstatic\\b" << "\\bsuper\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    // 类名格式
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression("\\bclass\\b\\s+([A-Za-z_][A-Za-z0-9_]*)");
    rule.format = classFormat;
    highlightingRules.append(rule);

    // 函数名格式
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("\\bfunction\\b\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*\\(");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // 单行注释格式
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // 多行注释格式
    multiLineCommentFormat.setForeground(Qt::red);

    // 字符串格式
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
}

void JavaScriptHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    // 多行注释
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(QRegularExpression("/\\*"));

    while (startIndex >= 0) {
        QRegularExpressionMatch match = QRegularExpression("\\*/").match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(QRegularExpression("/\\*"), startIndex + commentLength);
    }
}
