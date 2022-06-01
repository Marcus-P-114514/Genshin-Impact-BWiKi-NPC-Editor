#ifndef LICENSE_H
#define LICENSE_H

#include <QWidget>

namespace Ui {
class License;
}

class License : public QWidget
{
    Q_OBJECT

public:
    explicit License(QWidget *parent = nullptr);
    ~License();

private:
    Ui::License *ui;
};

#endif // LICENSE_H
