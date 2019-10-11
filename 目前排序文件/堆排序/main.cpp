#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include<time.h>
using namespace std;
template<typename Type>
class Heap
{
public:
    Heap(const vector<Type>& a_array)
    {
        m_array.assign(a_array.begin(),a_array.end());
    }

    template<typename Compare>
    void sort(Compare comp);

    void printArray(const vector<Type>& a_array);

private:
    vector<Type> m_array;

    //comp 为less<Type> 则大数下沉，创建最小堆，从小到大排序
    //comp 为greater<Type> 则小数下沉，创建最大堆，从大到小排序
    template<typename Compare>
    void creatHeap(Compare comp);                //创建堆

    template<typename Compare>
    void downElement(int a_elem, Compare comp);    //下沉元素
};

template<typename Type>
template<typename Compare>
void Heap<Type>::sort(Compare comp)
{

   // printArray(m_array);
    creatHeap(comp);                    //建堆
    vector<Type> array;
     double a1,b1;
     double c;
      cout<<"排序"<<endl;
     a1 = clock();
    for (int i = m_array.size() - 1; i >= 0; i--)
    {
        array.push_back(m_array[0]);    //保留堆顶
        swap(m_array[0], m_array[i]);    //交换
        m_array.pop_back();                //去掉最后一个元素
        downElement(0,comp);            //将新的首元素下沉
    }
    b1= clock();
    c = (double)(b1 - a1);
    printf("排序%f\n",(c/CLOCKS_PER_SEC));
    printArray(array);
    m_array.assign(array.begin(),array.end());

}

template<typename Type>
template<typename Compare>
void Heap<Type>::creatHeap(Compare comp)
{
    //从最后一个非叶子节点开始，将每个父节点都调整为最小堆
    for (int i=m_array.size()/2-1; i>=0; i--)
    {
        downElement(i, comp);
    }
}

template<typename Type>
template<typename Compare>
void Heap<Type>::downElement(int a_elem, Compare comp)    //下沉元素
{
    int min;            //设置最小元素下标
    int index = a_elem;    //当前下沉的元素下标
    while (index*2+1 < m_array.size())//存在左节点
    {
        min = index*2+1;
        if (index*2+2 < m_array.size())//存在右节点
        {
            //左右节点比较，选出最小的
            if (comp(m_array[index*2+2],m_array[min]))
            {
                min = index*2+2;
            }
        }
        //同子节点比较，若父节点最小则结束
        if (comp(m_array[index],m_array[min]))
        {
            break;
        }
        else//选最小元素到父节点
        {
            swap(m_array[min],m_array[index]);
            index = min;
        }
    }
}

template<typename Type>
void Heap<Type>::printArray(const vector<Type>& a_array)
{
    double e1,f1;
    double c;
    cout<<"输出数据"<<endl;
     e1 = clock();
    ofstream out("out.txt");
    for (int i=0; i<a_array.size(); i++)
    {
        out << a_array[i] << endl;
    }
     f1= clock();
    c = (double)(f1 - e1);
    printf("输出%f\n",(c/CLOCKS_PER_SEC));
}

int main()
{
    double a,b,c;
    clock_t a1,b1,c1,d1,e1,f1;
    cout<<"开始建堆读取数据"<<endl;
    vector<double> array;
    ifstream infile;
    infile.open("output.txt",ios::in);   //将文件流对象与文件连接起来
    string s;
    a1 = clock();
    while(getline(infile,s))
    {
        array.push_back(atof(s.c_str()));
    }
     b1 = clock();
    a = (double)(b1 - a1);
    printf("读取:%f\n",(a/CLOCKS_PER_SEC));
    cout<<"放入数据"<<endl;
    c1= clock();
    Heap<double> heap(array);
    d1 = clock();
     b= (double)(d1 - c1);
    printf("放入%f\n",(b/CLOCKS_PER_SEC));

    heap.sort(less<double>());

   // heap.sort(greater<double>());
    return 0;
}

