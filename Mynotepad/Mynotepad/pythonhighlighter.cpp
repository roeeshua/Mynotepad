
#include "pythonhighlighter.h"

PythonHighlighter::PythonHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // 关键字格式
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\band\\b" << "\\bas\\b" << "\\bassert\\b"
                    << "\\bbreak\\b" << "\\bclass\\b" << "\\bcontinue\\b"
                    << "\\bdef\\b" << "\\bdel\\b" << "\\belif\\b"
                    << "\\belse\\b" << "\\bexcept\\b" << "\\bexec\\b"
                    << "\\bfinally\\b" << "\\bfor\\b" << "\\bfrom\\b"
                    << "\\bglobal\\b" << "\\bif\\b" << "\\bimport\\b"
                    << "\\bin\\b" << "\\bis\\b" << "\\blambda\\b"
                    << "\\bnot\\b" << "\\bor\\b" << "\\bpass\\b"
                    << "\\bprint\\b" << "\\braise\\b" << "\\breturn\\b"
                    << "\\btry\\b" << "\\bwhile\\b" << "\\bwith\\b"
                    << "\\byield\\b";
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
    rule.pattern = QRegularExpression("\\bdef\\b\\s+([A-Za-z_][A-Za-z0-9_]*)\\s*\\(");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    // 单行注释格式
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression("#[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // 字符串格式
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
}

void PythonHighlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
