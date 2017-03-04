#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include <QString>
#include<string>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool issaved;
    QString curfile;
    unsigned char memory[1024];
    unsigned int PC;
    unsigned int Register[32];
    unsigned int Content1;
    unsigned int Content2;
    QString IR;
    unsigned int lineindex;
    unsigned int find(int address);
    void update();
    bool RunSignal(std::string str);
    QLabel *bar;
    void showMessage(const QString& message);


public slots:
    void file_new(); //新建文件
    void file_saveornot(); //修改过的文件是否保存
    void file_save(); //保存文件
    void file_saveas(); //文件另存为
    bool savefile(const QString& fileName); //存储文件
    void file_open(); //打开文件
    bool file_load(const QString& fileName); //读取文件
    void IntoMem();
    void on_assembler_clicked();
    void on_disassembler_clicked();
    void run();
    void runall();

};

#endif // MAINWINDOW_H
