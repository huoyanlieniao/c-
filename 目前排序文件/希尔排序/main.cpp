#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <functional>
#include <cstdlib>

using namespace std;
void ShellSort(vector<double> &array, int n)  //希尔排序函数
{
	int i, j, step;
	for (step = n / 2; step > 0; step = step / 2)  //这里的step步长是根据10个元素这种情况定义的
	{
		for (i = 0; i < step; i++)  //i是子数组的编号
		{
			for (j = i + step; j < n; j = j + step)  //数组下标j，数组步长下标j+step
			{
				if (array[j] < array[j - step])
				{
					int temp = array[j];  //把数组下标j的值放到temp中
					int k = j - step;

					while (k >= 0 && temp < array[k])
					{
						array[k + step] = array[k];  //把大的值往后插入
						k = k - step;
					}
					array[k + step] = temp;  //把小的值往前插入
				}
			}
		}
	}

}



int main()
{
    double a1,a2,a3,a4,a5,a6;
    double b,c,d;
    cout<<"开始读取数据"<<endl;
    vector<double> array;
    ifstream infile;
    infile.open("output.txt",ios::in);   //将文件流对象与文件连接起来
    string s;
    a1= clock();
     while(getline(infile,s))
    {
        array.push_back(atof(s.c_str()));
    }
    a2 = clock();
    b = (double)(a2 - a1);
    printf("读取:%f\n",(b/CLOCKS_PER_SEC));
    cout<<"排序"<<endl;
     a3 = clock();
 ShellSort(array,array.size());
     a4 = clock();
      c = (double)(a4 - a3);
    printf("排序:%f\n",(c/CLOCKS_PER_SEC));
     cout<<"输出"<<endl;
     a5 = clock();
  ofstream out("out.txt");
  int i=0;
     for(i;i<array.size();i++){
        out <<array[i] << endl;
}
 a6 = clock();
     d = (double)(a6 - a5);
    printf("输出:%f\n",(d/CLOCKS_PER_SEC));

    return 0;
}

