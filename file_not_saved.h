#ifndef FILE_NOT_SAVED_H
#define FILE_NOT_SAVED_H

#include <QWidget>

namespace Ui {
class File_Not_Saved;
}

class File_Not_Saved : public QWidget
{
    Q_OBJECT

public:
    explicit File_Not_Saved(QWidget *parent = nullptr);
    ~File_Not_Saved();

private slots:
    void on_return_to_editor_from_file_no_saved_dialog_clicked();

    void on_discard_changes_from_file_not_saved_dialog_clicked();

private:
    Ui::File_Not_Saved *ui;
};

#endif // FILE_NOT_SAVED_H
