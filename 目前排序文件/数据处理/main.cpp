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
    cout<<"��ʼ��ȡ����"<<endl;
     start = clock();
    ifstream infile;
    infile.open("out.txt",ios::in);   //���ļ����������ļ���������
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
    printf("��ȡ�ж�ʱ��%f\n",(r/CLOCKS_PER_SEC));
    cout<<"��ʼд������"<<endl;
     start = clock();
ofstream out("output.txt");
 for(int d=0;d<i;d++){
    out<<a[d]<<endl;
   }
    end = clock();
    w = (double)(end - start);
    printf("д��ʱ��%f\n",(w/CLOCKS_PER_SEC));
  }

