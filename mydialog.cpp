#include "mydialog.h"
#include "ui_mydialog.h"
#include <QSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QTextStream>
#include <QFileDialog>

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MyDialog)
{
    setWindowTitle("Анкета");
    QHBoxLayout *Hlay = new QHBoxLayout;

    pButton->setText("Сохранить");
    cBox->addItem("Да");
    cBox->addItem("Нет");
    cBox->addItem("Не знаю");

    Hlay->addWidget(sBox);
    Hlay->addWidget(tEdit);
    Hlay->addWidget(cBox);
    Hlay->addWidget(pButton);
    this->setLayout(Hlay);
    ui->setupUi(this);
    QObject::connect(pButton, SIGNAL(clicked()), this, SLOT(Wrf()));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::Wrf(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Notebook As"), QString());
    if (fileName.isEmpty())
    {
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    QTextStream out(&file);
    out << this->sBox->value() << QString("\n" )<< this->tEdit->toPlainText() << QString("\n" ) << this->cBox->currentText() << QString("\n");

    file.close();

}

