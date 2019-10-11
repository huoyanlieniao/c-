#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <functional>
#include <cstdlib>
using namespace std;
double partition(vector<double> &data,double left,double right)     //�һ�׼�� ����
{
     double pivot=data[left],pivotpos=left;
	for(int i=left+1;i<=right;i++)
	{
		if(data[i]<pivot)
		{
			pivotpos++;
			double temp=data[i];
			data[i]=data[pivotpos];
			data[pivotpos]=temp;
		}
	}
	data[left]=data[pivotpos];
	data[pivotpos]=pivot;
	return pivotpos;
}
void quick_sorting(vector<double> &data,double start,double end)
{
	if(start<end)
	{
		double pivotpos;
		pivotpos=partition(data,start,end);
		quick_sorting(data,start,pivotpos-1);
		quick_sorting(data,pivotpos+1,end);
	}
}
int main( )
{
    double a1,a2,a3,a4,a5,a6;
    double b,c,d;
    cout<<"��ʼ��ȡ����"<<endl;
    vector<double> array;
    ifstream infile;
    infile.open("output.txt",ios::in);   //���ļ����������ļ���������
    string s;
     a1= clock();
     while(getline(infile,s))
    {
        array.push_back(atof(s.c_str()));
    }
    a2 = clock();
    b = (double)(a2 - a1);
    printf("��ȡ:%f\n",(b/CLOCKS_PER_SEC));
   cout<<"����"<<endl;
    a3= clock();
    quick_sorting(array, 0, array.size() - 1);
    a4= clock();
     c = (double)(a4 - a3);
    printf("����:%f\n",(c/CLOCKS_PER_SEC));
    cout<<"���"<<endl;
     a5= clock();
     ofstream out("out.txt");
     for(int i=array.size()-1;i>=0;i--){
        out <<array[i] << endl;
     }
    // for (int i=0; i<array.size(); i++)
    //{
      //  out <<array[i] << endl;
    //}
     a6= clock();
     d = (double)(a6 - a5);
    printf("���:%f\n",(d/CLOCKS_PER_SEC));

    return 0;
}

