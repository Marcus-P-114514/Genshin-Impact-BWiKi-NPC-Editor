#ifndef CODE_HIGHLIGHT_H
#define CODE_HIGHLIGHT_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class code_highlight : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    code_highlight(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QList<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // CODE_HIGHLIGHT_H
