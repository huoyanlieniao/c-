#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
#include<time.h>
using namespace std;
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
     double r,w;
     clock_t start,end;
    cout<<"开始读取数据"<<endl;
     start = clock();
    ifstream infile;
    infile.open("out.txt",ios::in);   //将文件流对象与文件连接起来
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
    end = clock();
    r = (double)(end - start);
    printf("读取判定时间%f\n",(r/CLOCKS_PER_SEC));
    cout<<"开始写入数据"<<endl;
     start = clock();
ofstream out("output.txt");
 for(int d=0;d<i;d++){
    out<<a[d]<<endl;
   }
    end = clock();
    w = (double)(end - start);
    printf("写入时间%f\n",(w/CLOCKS_PER_SEC));
  }

