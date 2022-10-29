#include "theme.h"
#include "ui_theme.h"
#include "QSettings"

QString btn_emu_selected;
QString btn_emu_released;
QString lineedit_emu;
QString box_emu;
QString text_emu = "border: none;";
bool custom_theme_enabled = false;

theme::theme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::theme)
{
    ui->setupUi(this);

    ui->groupBox_2->setVisible(0);
    ui->setTheme_Custom->setVisible(0);

    QSettings *config_theme_2 = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    QString theme_pref_read_2 = config_theme_2 -> value ( "theme/name").toString();

    if (theme_pref_read_2 == "light") {
        btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
        btn_emu_released = "QPushButton{border-radius: 5px; background-color: #F6F0E5; color: #E7BF9F;border: 6px;}";
        lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        box_emu = "border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        this->setStyleSheet("background-color: #F6F0E5; color: #E7BF9F;");
        ui->setTheme_light->setStyleSheet(btn_emu_selected);
        ui->setTheme_Dark->setStyleSheet(btn_emu_released);
        ui->setTheme_Black->setStyleSheet(btn_emu_released);
        ui->setTheme_Custom->setStyleSheet(btn_emu_released);
        ui->primary_input->setStyleSheet(lineedit_emu);
        ui->background_input->setStyleSheet(lineedit_emu);
        ui->text_input->setStyleSheet(lineedit_emu);
        ui->toolbar_input->setStyleSheet(lineedit_emu);
        ui->groupBox->setStyleSheet(box_emu);
        ui->groupBox_2->setStyleSheet(box_emu);
        ui->theme_instruction->setStyleSheet(text_emu);
        ui->apply_theme->setStyleSheet(btn_emu_selected);

    }
    else if (theme_pref_read_2 == "dark") {
        btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
        btn_emu_released = "QPushButton{border-radius: 5px; background-color: rgb(69,69,69); color: #E7BF9F;border: 6px;}";
        lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        box_emu = "border: 2px solid  solid rgb(69,69,69); border-radius: 5px;";
        this->setStyleSheet("background-color: rgb(69,69,69); color: #E7BF9F;");
        ui->setTheme_light->setStyleSheet(btn_emu_released);
        ui->setTheme_Dark->setStyleSheet(btn_emu_selected);
        ui->setTheme_Black->setStyleSheet(btn_emu_released);
        ui->setTheme_Custom->setStyleSheet(btn_emu_released);
        ui->primary_input->setStyleSheet(lineedit_emu);
        ui->background_input->setStyleSheet(lineedit_emu);
        ui->text_input->setStyleSheet(lineedit_emu);
        ui->toolbar_input->setStyleSheet(lineedit_emu);
        ui->groupBox->setStyleSheet(box_emu);
        ui->groupBox_2->setStyleSheet(box_emu);
        ui->theme_instruction->setStyleSheet(text_emu);
        ui->apply_theme->setStyleSheet(btn_emu_selected);
    }
    else if (theme_pref_read_2 == "black") {
        btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
        btn_emu_released = "QPushButton{border-radius: 5px; background-color: rgb(0,0,0); color: #E7BF9F;border: 6px;}";
        lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        box_emu = "border: 2px solid  solid rgb(0,0,0); border-radius: 5px;";
        this->setStyleSheet("background-color: rgb(0,0,0); color: #E7BF9F;");
        ui->setTheme_light->setStyleSheet(btn_emu_released);
        ui->setTheme_Dark->setStyleSheet(btn_emu_released);
        ui->setTheme_Black->setStyleSheet(btn_emu_selected);
        ui->setTheme_Custom->setStyleSheet(btn_emu_released);
        ui->primary_input->setStyleSheet(lineedit_emu);
        ui->background_input->setStyleSheet(lineedit_emu);
        ui->text_input->setStyleSheet(lineedit_emu);
        ui->toolbar_input->setStyleSheet(lineedit_emu);
        ui->groupBox->setStyleSheet(box_emu);
        ui->groupBox_2->setStyleSheet(box_emu);
        ui->theme_instruction->setStyleSheet(text_emu);
        ui->apply_theme->setStyleSheet(btn_emu_selected);
    }
    else if (theme_pref_read_2 == "custom") {
        QString primary_custom_read = config_theme_2 -> value ( "custom/primary").toString();
        QString background_custom_read = config_theme_2 -> value ( "custom/background").toString();
        QString text_color_selected_custom_read = config_theme_2 -> value ( "custom/text_color").toString();
        QString toolbar_custom_read = config_theme_2 -> value ( "custom/toolbar").toString();
        btn_emu_selected = "QPushButton{border-radius: 5px; background-color: " + primary_custom_read + "; color: " + text_color_selected_custom_read +";border: 6px;}";
        btn_emu_released = "QPushButton{border-radius: 5px; background-color: " + background_custom_read +"; color: " + primary_custom_read + ";border: 6px;}";
        lineedit_emu = "padding: 3px; border: 2px solid  solid " + primary_custom_read + "; border-radius: 5px;";
        box_emu = "border: 2px solid  solid " + background_custom_read +"; border-radius: 5px;";
        this->setStyleSheet("background-color: " + background_custom_read +"; color: " + primary_custom_read + ";");
        ui->setTheme_light->setStyleSheet(btn_emu_released);
        ui->setTheme_Dark->setStyleSheet(btn_emu_released);
        ui->setTheme_Black->setStyleSheet(btn_emu_released);
        ui->setTheme_Custom->setStyleSheet(btn_emu_selected);
        ui->primary_input->setStyleSheet(lineedit_emu);
        ui->background_input->setStyleSheet(lineedit_emu);
        ui->text_input->setStyleSheet(lineedit_emu);
        ui->toolbar_input->setStyleSheet(lineedit_emu);
        ui->groupBox->setStyleSheet(box_emu);
        ui->groupBox_2->setStyleSheet(box_emu);
        ui->theme_instruction->setStyleSheet(text_emu);
        ui->apply_theme->setStyleSheet(btn_emu_selected);
    }
    else {
        btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
        btn_emu_released = "QPushButton{border-radius: 5px; background-color: #F6F0E5; color: #E7BF9F;border: 6px;}";
        lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        box_emu = "border: 2px solid  solid #F6F0E5; border-radius: 5px;";
        this->setStyleSheet("background-color: #F6F0E5; color: #E7BF9F;");
        ui->setTheme_light->setStyleSheet(btn_emu_selected);
        ui->setTheme_Dark->setStyleSheet(btn_emu_released);
        ui->setTheme_Black->setStyleSheet(btn_emu_released);
        ui->setTheme_Custom->setStyleSheet(btn_emu_released);
        ui->primary_input->setStyleSheet(lineedit_emu);
        ui->background_input->setStyleSheet(lineedit_emu);
        ui->text_input->setStyleSheet(lineedit_emu);
        ui->toolbar_input->setStyleSheet(lineedit_emu);
        ui->groupBox->setStyleSheet(box_emu);
        ui->groupBox_2->setStyleSheet(box_emu);
        ui->theme_instruction->setStyleSheet(text_emu);
        ui->apply_theme->setStyleSheet(btn_emu_selected);
    }
    delete config_theme_2;

}

theme::~theme()
{
    delete ui;
}

void theme::on_setTheme_light_clicked()
{
    QSettings *config_theme_2 = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    config_theme_2->setValue("theme/name", "light");
    delete config_theme_2;
    btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
    btn_emu_released = "QPushButton{border-radius: 5px; background-color: #F6F0E5; color: #E7BF9F;border: 6px;}";
    lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
    box_emu = "border: 2px solid  solid #F6F0E5; border-radius: 5px;";
    this->setStyleSheet("background-color: #F6F0E5; color: #E7BF9F;");
    ui->setTheme_light->setStyleSheet(btn_emu_selected);
    ui->setTheme_Dark->setStyleSheet(btn_emu_released);
    ui->setTheme_Black->setStyleSheet(btn_emu_released);
    ui->setTheme_Custom->setStyleSheet(btn_emu_released);
    ui->primary_input->setStyleSheet(lineedit_emu);
    ui->background_input->setStyleSheet(lineedit_emu);
    ui->text_input->setStyleSheet(lineedit_emu);
    ui->toolbar_input->setStyleSheet(lineedit_emu);
    ui->groupBox->setStyleSheet(box_emu);
    ui->groupBox_2->setStyleSheet(box_emu);
    ui->theme_instruction->setStyleSheet(text_emu);
    ui->apply_theme->setStyleSheet(btn_emu_selected);
    //QWidget::close();

}

void theme::on_setTheme_Dark_clicked()
{
    QSettings *config_theme_2 = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    config_theme_2->setValue("theme/name", "dark");
    delete config_theme_2;
    btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
    btn_emu_released = "QPushButton{border-radius: 5px; background-color: rgb(69,69,69); color: #E7BF9F;border: 6px;}";
    lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
    box_emu = "border: 2px solid  solid rgb(69,69,69); border-radius: 5px;";
    this->setStyleSheet("background-color: rgb(69,69,69); color: #E7BF9F;");
    ui->setTheme_light->setStyleSheet(btn_emu_released);
    ui->setTheme_Dark->setStyleSheet(btn_emu_selected);
    ui->setTheme_Black->setStyleSheet(btn_emu_released);
    ui->setTheme_Custom->setStyleSheet(btn_emu_released);
    ui->primary_input->setStyleSheet(lineedit_emu);
    ui->background_input->setStyleSheet(lineedit_emu);
    ui->text_input->setStyleSheet(lineedit_emu);
    ui->toolbar_input->setStyleSheet(lineedit_emu);
    ui->groupBox->setStyleSheet(box_emu);
    ui->groupBox_2->setStyleSheet(box_emu);
    ui->theme_instruction->setStyleSheet(text_emu);
    ui->apply_theme->setStyleSheet(btn_emu_selected);
    //QWidget::close();
}

void theme::on_setTheme_Black_clicked()
{
    QSettings *config_theme_2 = new QSettings ( "./config/global.conf", QSettings::IniFormat);
    config_theme_2->setValue("theme/name", "black");
    delete config_theme_2;
    btn_emu_selected = "QPushButton{border-radius: 5px; background-color: #E7BF9F; color: #FFFFFF;border: 6px;}";
    btn_emu_released = "QPushButton{border-radius: 5px; background-color: rgb(0,0,0); color: #E7BF9F;border: 6px;}";
    lineedit_emu = "padding: 3px; border: 2px solid  solid #F6F0E5; border-radius: 5px;";
    box_emu = "border: 2px solid  solid rgb(0,0,0); border-radius: 5px;";
    this->setStyleSheet("background-color: rgb(0,0,0); color: #E7BF9F;");
    ui->setTheme_light->setStyleSheet(btn_emu_released);
    ui->setTheme_Dark->setStyleSheet(btn_emu_released);
    ui->setTheme_Black->setStyleSheet(btn_emu_selected);
    ui->setTheme_Custom->setStyleSheet(btn_emu_released);
    ui->primary_input->setStyleSheet(lineedit_emu);
    ui->background_input->setStyleSheet(lineedit_emu);
    ui->text_input->setStyleSheet(lineedit_emu);
    ui->toolbar_input->setStyleSheet(lineedit_emu);
    ui->groupBox->setStyleSheet(box_emu);
    ui->groupBox_2->setStyleSheet(box_emu);
    ui->theme_instruction->setStyleSheet(text_emu);
    ui->apply_theme->setStyleSheet(btn_emu_selected);
    //QWidget::close();
}

void theme::on_apply_theme_clicked()
{
    QWidget::close();
}

