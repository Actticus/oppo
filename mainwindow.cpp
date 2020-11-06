#include "mainwindow.h"
#include "auth.h"
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

    auth *dg = new auth();
    dg->show();

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QTextCharFormat format;
    format.setForeground(qvariant_cast<QColor>("black"));
    for (int i = 1; i <= 5; i++) {
        ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i), format);
    }
    format.setForeground(qvariant_cast<QColor>("red"));
    for (int i = 6; i <= 7; i++) {
        ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i), format);
    }
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index + 1), format);
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index + 1));
}
