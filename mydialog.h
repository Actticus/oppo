#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MyDialog; }
QT_END_NAMESPACE

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = 0);
    ~MyDialog();
private slots:
    void Wrf();

private:
    Ui::MyDialog *ui;
    QSpinBox *sBox = new QSpinBox;
    QTextEdit *tEdit = new QTextEdit;
    QPushButton *pButton = new QPushButton;
    QComboBox *cBox = new QComboBox;
};
#endif // MYDIALOG_H
