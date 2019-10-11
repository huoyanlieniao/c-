#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <functional>
#include <cstdlib>

using namespace std;
void ShellSort(vector<double> &array, int n)  //ϣ��������
{
	int i, j, step;
	for (step = n / 2; step > 0; step = step / 2)  //�����step�����Ǹ���10��Ԫ��������������
	{
		for (i = 0; i < step; i++)  //i��������ı��
		{
			for (j = i + step; j < n; j = j + step)  //�����±�j�����鲽���±�j+step
			{
				if (array[j] < array[j - step])
				{
					int temp = array[j];  //�������±�j��ֵ�ŵ�temp��
					int k = j - step;

					while (k >= 0 && temp < array[k])
					{
						array[k + step] = array[k];  //�Ѵ��ֵ�������
						k = k - step;
					}
					array[k + step] = temp;  //��С��ֵ��ǰ����
				}
			}
		}
	}

}



int main()
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
     a3 = clock();
 ShellSort(array,array.size());
     a4 = clock();
      c = (double)(a4 - a3);
    printf("����:%f\n",(c/CLOCKS_PER_SEC));
     cout<<"���"<<endl;
     a5 = clock();
  ofstream out("out.txt");
  int i=0;
     for(i;i<array.size();i++){
        out <<array[i] << endl;
}
 a6 = clock();
     d = (double)(a6 - a5);
    printf("���:%f\n",(d/CLOCKS_PER_SEC));

    return 0;
}

