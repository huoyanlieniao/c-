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
#include<ctime>
struct timeb timeSeed;
using namespace std;
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
    freopen("out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ���
    for(int i=0;i< 850000;i++){
           //(10); //��������̫�쵼��������в���һ������Ϊ���õ�time�ǰ���������ӽ�������Ǽ��ٵ��ô���������ʱ��
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
    fclose(stdout);//�ر��ļ�

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
        switch (rand()%4)
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
            case 3:
                temp = rand()%26 + '�ҿ������ڱ�����';
                break;
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
