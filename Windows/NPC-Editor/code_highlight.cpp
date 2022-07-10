#include "code_highlight.h"

code_highlight::code_highlight(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(QColor(76,175,80));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsHead[] = {
        QStringLiteral("{{NPC"), QStringLiteral("{{NPC图鉴"), QStringLiteral("{{NPC图标")
    };
    for (const QString &pattern : keywordPatternsHead) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(33,150,243));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsBasicInfo[] = {
        QStringLiteral("|名称="), QStringLiteral("|称号="), QStringLiteral("|性别="), QStringLiteral("|职业="),
        QStringLiteral("|位置="), QStringLiteral("|所属国家="), QStringLiteral("|所属组织="), QStringLiteral("|相关系统="),
        QStringLiteral("|对话赠礼="), QStringLiteral("|实装版本=")
    };
    for (const QString &pattern : keywordPatternsBasicInfo) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(33,150,243));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsLinkStart[] = {
        QStringLiteral("[[")
    };
    for (const QString &pattern : keywordPatternsLinkStart) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(244,67,54));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsBoolNo[] = {
        QStringLiteral("否")
    };
    for (const QString &pattern : keywordPatternsBoolNo) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(76,150,80));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsBoolYes[] = {
        QStringLiteral("是")
    };
    for (const QString &pattern : keywordPatternsBoolYes) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(33,150,243));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsLinkEnd[] = {
        QStringLiteral("[["), QStringLiteral("]]")
    };
    for (const QString &pattern : keywordPatternsLinkEnd) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(0,150,136));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsStore[] = {
        QStringLiteral("|存在商店="), QStringLiteral("|商店内容="),
    };
    for (const QString &pattern : keywordPatternsStore) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(255,193,7));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsDialog[] = {
        QStringLiteral("|存在对话="), QStringLiteral("|对话内容="), QStringLiteral("{{NPC对话"),
        QStringLiteral("|标题="), QStringLiteral("|内容="), QStringLiteral("|待机语音=")
    };
    for (const QString &pattern : keywordPatternsDialog) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(255,152,0));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsDialogTwo[] = {
        QStringLiteral("{{NPC剧情"), QStringLiteral("|选项"), QStringLiteral("|剧情")
    };
    for (const QString &pattern : keywordPatternsDialogTwo) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(121,85,72));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsCV[] = {
        QStringLiteral("|中文CV="), QStringLiteral("|日文CV="), QStringLiteral("|英文CV="), QStringLiteral("|韩文CV=")
    };
    for (const QString &pattern : keywordPatternsCV) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }


    keywordFormat.setForeground(QColor(121,85,72));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsExtras[] = {
        QStringLiteral("|活动限定="), QStringLiteral("|出现时间="), QStringLiteral("|出现地点="), QStringLiteral("|出现地点="),
        QStringLiteral("|声望系统="), QStringLiteral("|居民委托="), QStringLiteral("|讨伐悬赏=")
    };
    for (const QString &pattern : keywordPatternsExtras) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }


    keywordFormat.setForeground(QColor(33,150,243));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsEdit[] = {
        QStringLiteral("|最后编辑版本="), QStringLiteral("|是否完善=")
    };
    for (const QString &pattern : keywordPatternsEdit) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor(0,188,212));
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatternsCommand[] = {
        QStringLiteral("*"), QStringLiteral("+")
    };
    for (const QString &pattern : keywordPatternsCommand) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }


classFormat.setFontWeight(QFont::Bold);
classFormat.setForeground(Qt::darkMagenta);
rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
rule.format = classFormat;
highlightingRules.append(rule);



singleLineCommentFormat.setForeground(Qt::red);
rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
rule.format = singleLineCommentFormat;
highlightingRules.append(rule);

multiLineCommentFormat.setForeground(Qt::red);



quotationFormat.setForeground(Qt::darkGreen);
rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
rule.format = quotationFormat;
highlightingRules.append(rule);



functionFormat.setFontItalic(true);
functionFormat.setForeground(Qt::blue);
rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
rule.format = functionFormat;
highlightingRules.append(rule);



commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}

void code_highlight::highlightBlock(const QString &text){
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);



    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);


    while (startIndex >= 0) {

        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
