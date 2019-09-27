#ifndef SHUJUCHULI_H
#define SHUJUCHULI_H

#endif // SHUJUCHULI_H


#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
using namespace std;


namespace chuli{

bool isNum(string str)
{
    stringstream sin(str);
    double d;
    char c;
    if(!(sin >> d))
    {
        return false;
    }
    if (sin >> c)
    {
        return false;
    }
    return true;
}




int main()
{
    ifstream infile;
    infile.open("out.txt",ios::in);   //将文件流对象与文件连接起来

    //assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
   static string a[900000];
    string s;
    int i=0;
    while(getline(infile,s))
    {
         if(isNum(s))  {
         a[i]=s;
         i++;
     }
    }
    //infile.close();             //关闭文件输入流

ofstream out("output.txt");
 for(int d=0;d<i;d++){
    out<<a[d]<<endl;
   }
  }

}
