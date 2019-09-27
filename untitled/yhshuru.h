#ifndef YHSHURU_H
#define YHSHURU_H
#include <QApplication>
#include <QPlainTextEdit>
#endif // YHSHURU_H
using namespace std;
namespace kuang{
int main()
{
    QPlainTextEdit *plainTextEdit;
    //实例
    plainTextEdit = new QPlainTextEdit();
    //位置
    //添加内容
    plainTextEdit->setPlainText("asdf");
    plainTextEdit->show();
}
}
