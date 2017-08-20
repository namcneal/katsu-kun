#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Verb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Testing by accessing the UI elements created in the Design Tab
    QFont japaneseFont = QFont("Resources/Source Han Serif", 20);
    Verb testVerb = Verb("i", "勉強する", "べんきょうする");
    QString testString = QString("Testing Japanese text display\n") + QString("カツく～～んで")+testVerb.getDictionary()[0];
    ui->testLabel->setText(testString);
    ui->testLabel->setFont(japaneseFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}
