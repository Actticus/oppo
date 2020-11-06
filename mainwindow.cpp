#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About_Lab1(){

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QTextCharFormat format;
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index + 1), format);
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index + 1));
}
