#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mai.h"
#include <QtGui>
#include <fstream>
#include<string>
#include<QMessageBox>
#include<QFileDialog>
#include<Qcolor>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    issaved=0;
    curfile="未命名.mips";
    PC=0;
    IR="";
    lineindex=0;
    memset(memory, 0, 1024);
    memset(Register,0,32*4);
    memory[23]='A';

    bar=new QLabel("bar");
    statusBar()->addWidget(bar);
    bar->show();
    ui->pc->setFocusPolicy(Qt::NoFocus);
    ui->content1->setFocusPolicy(Qt::NoFocus);
    ui->content1->setFocusPolicy(Qt::NoFocus);

    ui->pc->setText(QString::number(PC));
    ui->address1->setText(QString::number(0));
    ui->address2->setText(QString::number(0));
    Content1=find(ui->address1->text().toInt());
    Content2=find(ui->address2->text().toInt());
    ui->content1->setText(QString::number(Content1,16));
    ui->content2->setText(QString::number(Content2,16));


    connect(ui->save,       SIGNAL(triggered(bool)),this,SLOT(file_save()));
    connect(ui->saveas,     SIGNAL(triggered(bool)),this,SLOT(file_saveas()));
    connect(ui->open,       SIGNAL(triggered(bool)),this,SLOT(file_open()));
    connect(ui->file_new,   SIGNAL(triggered(bool)),this,SLOT(file_new()));
    connect(ui->address1,   SIGNAL(textChanged(QString)),this,SLOT(IntoMem()));
    connect(ui->address2,   SIGNAL(textChanged(QString)),this,SLOT(IntoMem()));
    connect(ui->run,        SIGNAL(clicked(bool)),this,SLOT(run()));
    connect(ui->runall,     SIGNAL(clicked(bool)),this,SLOT(runall()));
    update();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMessage(const QString& message)
{
    bar->setText(message);
}

void MainWindow::update()
{
    ui->pc->setText(QString::number(PC));
    ui->pc->repaint();
    ui->r0->setText("0x"+QString::number(Register[0],16)); ui->r0->repaint();
    ui->r1->setText("0x"+QString::number(Register[1],16)); ui->r1->repaint();
    ui->r2->setText("0x"+QString::number(Register[2],16)); ui->r2->repaint();
    ui->r3->setText("0x"+QString::number(Register[3],16)); ui->r3->repaint();
    ui->r4->setText("0x"+QString::number(Register[4],16)); ui->r4->repaint();
    ui->r5->setText("0x"+QString::number(Register[5],16)); ui->r5->repaint();
    ui->r6->setText("0x"+QString::number(Register[6],16)); ui->r6->repaint();
    ui->r7->setText("0x"+QString::number(Register[7],16)); ui->r7->repaint();
    ui->r8->setText("0x"+QString::number(Register[8],16)); ui->r8->repaint();
    ui->r9->setText("0x"+QString::number(Register[9],16)); ui->r9->repaint();
    ui->r10->setText("0x"+QString::number(Register[10],16)); ui->r10->repaint();
    ui->r11->setText("0x"+QString::number(Register[11],16)); ui->r11->repaint();
    ui->r12->setText("0x"+QString::number(Register[12],16)); ui->r12->repaint();
    ui->r13->setText("0x"+QString::number(Register[13],16)); ui->r13->repaint();
    ui->r14->setText("0x"+QString::number(Register[14],16)); ui->r14->repaint();
    ui->r15->setText("0x"+QString::number(Register[15],16)); ui->r15->repaint();
    ui->r16->setText("0x"+QString::number(Register[16],16)); ui->r16->repaint();
    ui->r17->setText("0x"+QString::number(Register[17],16)); ui->r17->repaint();
    ui->r18->setText("0x"+QString::number(Register[18],16)); ui->r18->repaint();
    ui->r19->setText("0x"+QString::number(Register[19],16)); ui->r19->repaint();
    ui->r20->setText("0x"+QString::number(Register[20],16)); ui->r20->repaint();
    ui->r21->setText("0x"+QString::number(Register[21],16)); ui->r21->repaint();
    ui->r22->setText("0x"+QString::number(Register[22],16)); ui->r22->repaint();
    ui->r23->setText("0x"+QString::number(Register[23],16)); ui->r23->repaint();
    ui->r24->setText("0x"+QString::number(Register[24],16)); ui->r24->repaint();
    ui->r25->setText("0x"+QString::number(Register[25],16)); ui->r25->repaint();
    ui->r26->setText("0x"+QString::number(Register[26],16)); ui->r26->repaint();
    ui->r27->setText("0x"+QString::number(Register[27],16)); ui->r27->repaint();
    ui->r28->setText("0x"+QString::number(Register[28],16)); ui->r28->repaint();
    ui->r29->setText("0x"+QString::number(Register[29],16)); ui->r29->repaint();
    ui->r30->setText("0x"+QString::number(Register[30],16)); ui->r30->repaint();
    ui->r31->setText("0x"+QString::number(Register[31],16)); ui->r31->repaint();


}

void MainWindow::IntoMem()
{
    Content1=find(ui->address1->text().toInt());
    Content2=find(ui->address2->text().toInt());
    ui->content1->setText("0x"+QString::number(Content1,16));
    ui->content2->setText("0x"+QString::number(Content2,16));
    ui->content1->repaint();
    ui->content2->repaint();
}

unsigned int MainWindow::find(int address)
{
    if(address<0 || address>1020)
    {
        QMessageBox box;
        box.setWindowTitle("Invalid address");
        box.setIcon(QMessageBox::Warning);
        box.setText("Invalid address");
        box.setStandardButtons(QMessageBox::Yes);
        if(box.exec()==QMessageBox::Yes)
        {
            ui->address1->setText(QString::number(0));
            ui->address2->setText(QString::number(0));
            Content1=find(ui->address1->text().toInt());
            Content2=find(ui->address2->text().toInt());
            address=0;
        }

    }

    unsigned int res=0;
    res+=memory[address];
    res=(res<<2)+memory[address+1];
    res=(res<<2)+memory[address+2];
    res=(res<<2)+memory[address+3];
    return res;

}

void MainWindow::file_save()
{
    if(issaved)
        savefile(curfile);
    else
        file_saveas();
}

bool MainWindow::savefile(const QString& filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"save file",tr("cannot save %1:\n %2").arg(filename).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    out<<ui->text1->toPlainText();
    issaved=1;
    curfile=QFileInfo(filename).canonicalFilePath();
    setWindowTitle(curfile);
    return true;


}

void MainWindow::file_saveas()
{
    QString filename=QFileDialog::getSaveFileName(this,tr("save as"),curfile);
    //获得文件名

    if(!filename.isEmpty())
    {
        savefile(filename);
    }

}

void MainWindow::file_saveornot()
{
    if(ui->text1->document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle("save or not ?");
        box.setIcon(QMessageBox::Warning);
        box.setText(curfile + " has not saved,save now?");
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if(box.exec()==QMessageBox::Yes)
            file_save();

    }
}

void MainWindow::file_new()
{
    file_saveornot();
    issaved=false;
    curfile="未命名.mips";
    ui->text1->clear();
    ui->text2->clear();
    ui->text1->setVisible(true);
    ui->text2->setVisible(true);
}

void MainWindow::file_open()
{
    file_saveornot();
    QString filename=QFileDialog::getOpenFileName(this);
    if(!filename.isEmpty())//如果文件名不为空
         file_load(filename);

    issaved=true;
    ui->text1->setVisible(true);

}

bool MainWindow::file_load(const QString& filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"open file",tr("cannot open %1:\n %2").arg(filename).arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    ui->text1->setPlainText(in.readAll());
    curfile = QFileInfo(filename).canonicalFilePath();
    setWindowTitle(curfile);
    return true;
}

void MainWindow::on_assembler_clicked()
{
    int linenum=ui->text1->document()->lineCount();
    for(int i=0;i<linenum;i++)
    {
        QString str = ui->text1->document()->findBlockByLineNumber(i).text();
        if(!str.isEmpty())
        {
        QString q =dodo(str);

        if(!i)
            ui->text2->setPlainText(q);
        else
            ui->text2->appendPlainText(q);

        }
    }
}

void MainWindow::on_disassembler_clicked()
{
    int linenum=ui->text2->document()->lineCount();
    for(int i=0;i<linenum;i++)
    {
        QString str = ui->text2->document()->findBlockByLineNumber(i).text();
        if(!str.isEmpty())
        {
        QString q =odod(str);

        if(!i)
            ui->text1->setPlainText(q);
        else
            ui->text1->appendPlainText(q);
        }
    }
}

void MainWindow::run()
{
    if(ui->text2->toPlainText()=="" && ui->text1->toPlainText()!="")
        on_assembler_clicked();
    else if(ui->text1->toPlainText()=="")
    {
        QMessageBox::warning(this,"empty",tr("the textedit is empty"));
        return;
    }

    unsigned int linenum=ui->text2->document()->lineCount();
    QColor lineColor;
    if(lineindex==linenum)
    {
        lineColor = QColor(Qt::white);
        ui->text2->document()->findBlockByLineNumber(lineindex-1).blockFormat().setBackground(lineColor);
        lineindex=0;
        statusBar()->showMessage("正在运行行号:"+QString::number(lineindex));
        QMessageBox::warning(this,"end of running",tr("end of running"));
        return;
    }
    if(lineindex>0)
    {
        lineColor = QColor(Qt::white);
        ui->text2->document()->findBlockByLineNumber(lineindex-1).blockFormat().setBackground(lineColor);
    }

    lineColor = QColor(Qt::yellow).lighter(150);
    ui->text2->document()->findBlockByLineNumber(lineindex).blockFormat().setBackground(lineColor);
    IR = ui->text2->document()->findBlockByLineNumber(lineindex).text();
    if(!RunSignal(IR.toStdString()))
    {
        QMessageBox::warning(this,"run error",tr("cannot run %1").arg(IR));
        return;
    }
    statusBar()->showMessage("正在运行行号:"+QString::number(lineindex));
    lineindex++;
    update();
    return;
}

void MainWindow::runall()
{
    if(ui->text2->toPlainText()=="" && ui->text1->toPlainText()!="")
        on_assembler_clicked();
    else if(ui->text1->toPlainText()=="")
    {
        QMessageBox::warning(this,"empty",tr("the textedit is empty"));
        return;
    }
    unsigned int linenum=ui->text2->document()->lineCount();
    QColor lineColor;

    for(lineindex=0;lineindex<linenum;lineindex++)
    {
        if(lineindex>0)
        {
            lineColor = QColor(Qt::white);
            ui->text2->document()->findBlockByLineNumber(lineindex-1).blockFormat().setBackground(lineColor);
        }

        lineColor = QColor(Qt::yellow).lighter(150);
        ui->text2->document()->findBlockByLineNumber(lineindex).blockFormat().setBackground(lineColor);
        IR = ui->text2->document()->findBlockByLineNumber(lineindex).text();
        if(!RunSignal(IR.toStdString()))
        {
            QMessageBox::warning(this,"run error",tr("cannot run %1").arg(IR));
            return;
        }
        update();
    }

    lineColor = QColor(Qt::white);
    ui->text2->document()->findBlockByLineNumber(lineindex-1).blockFormat().setBackground(lineColor);
    update();
    QMessageBox::warning(this,"run success",tr("run success"));
    return;


}

bool MainWindow::RunSignal(std::string str)
{
    Register[1]++;
    PC+=4;
    return 1;
}
