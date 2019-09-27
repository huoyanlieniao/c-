#ifndef TEST_H
#define TEST_H

#endif // TEST_H

#include<QTextBlock>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include <ctime>
#define random(x) rand()%(x)
#define randf() ((double)rand()/RAND_MAX)*(10000000-(-10000000)) +(-10000000)
#include <vector>
#include<math.h>
#include <windows.h>
#include<QPlainTextEdit>


struct timeb timeSeed;
using namespace std;

namespace suiji{

int main()
{


    LARGE_INTEGER nFrequency;
    if(QueryPerformanceFrequency(&nFrequency))
    {
    LARGE_INTEGER nStartCounter;
    ::QueryPerformanceCounter(&nStartCounter);
    ::srand((unsigned)nStartCounter.LowPart);
    }
    int zheng();
    float floa();
    float xiao();
    string suiji();
    int c;
    freopen("in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    for(int i=0;i< 850000;i++){
           //(10); //电脑运行太快导致随机的有部分一样，因为设置的time是按秒算的种子解决方法是减少调用次数，增加时间
     c=random(100);
     if ((c==7)||(c==9)){
     cout<< floa();
     }
     if (c==8){
         cout<< suiji();
     }
      if (c==10){
         cout<< xiao();
     }
     else cout<< zheng();
     cout<<endl;
     }
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件

    cout << "完成";

    return 0;
}
int zheng()
{
    int a;
    int b;
      a= random(47483);
      b=random(2);
     if(b==0){
        a=-a;
     }
    return a;
}
float floa()
{
    float a;
    a=randf();
    return a;
}
void RandStr(vector<char>&vec, const int len)
{
    LARGE_INTEGER nFrequency;
    if(QueryPerformanceFrequency(&nFrequency))
    {
    LARGE_INTEGER nStartCounter;
    ::QueryPerformanceCounter(&nStartCounter);
    ::srand((unsigned)nStartCounter.LowPart);
    }
    char temp;
    for (int i = 0; i < len; i++)
    {
        switch (rand()%3)
        {
            case 0:
                temp= rand()%10 + '0';
                break;

            case 1:
                temp = rand()%26 + 'a';
                break;

            case 2:
                temp = rand()%26 + 'A';
                break;
//            case 3:
//                temp = rand()%26 + "我靠，终于编完了";
//                break;
        }
        vec.push_back(temp);
    }
}
string suiji()
{
    vector<char>vec;
    string lala="";
    int len = random(15);
    RandStr(vec, len);
    for (int i = 0; i < len; i++)
    {
         lala+=vec[i];
    }
    return lala;
}
 float xiao()
{
    int a;
    int b;
    int d;
    float c=0;
    int sum=0;
    a= random(21470);
    d=a;
    while(d){
        sum++;
        d/=10;
    }
    sum=sum/2;
    sum=pow(10,sum);
    c=(double)a/sum;
    b=random(2);
     if(b==0){
        c=-c;
     }
     return c;

}
}
