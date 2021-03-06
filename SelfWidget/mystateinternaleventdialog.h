/*************************************************
**版  权：RenGu Company
**文件名: mystateinternaleventdialog.h
**作  者: wey       Version: 1.0       Date: 2016.11.08
**描  述: 状态内部事件设置
**Others:
**
**修改历史:
**
*************************************************/
#ifndef MYSTATEINTERNALEVENTDIALOG_H
#define MYSTATEINTERNALEVENTDIALOG_H

#include <QDialog>

#include "Header.h"

class MyChooseBar;

namespace Ui {
class MyStateInternalEventDialog;
}

class MyStateInternalEventDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MyStateInternalEventDialog(QWidget *parent = 0);
    ~MyStateInternalEventDialog();

    bool getResult(StatInnerProperty & property);
    void showDesc(StatInnerProperty property);

private slots:
    void respConfirm();
    void respCancel();
    
private:
    Ui::MyStateInternalEventDialog *ui;

    MyChooseBar * chooseBar;
    StatInnerProperty  prop;
    bool isOkPressed;
};

#endif // MYSTATEINTERNALEVENTDIALOG_H
