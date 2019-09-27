#ifndef PAIXUMAX_H
#define PAIXUMAX_H

#endif // PAIXUMAX_H
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
namespace  paixumax{


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
    printArray(m_array);
    creatHeap(comp);                    //建堆
    vector<Type> array;
    for (int i = m_array.size() - 1; i >= 0; i--)
    {
        array.push_back(m_array[0]);    //保留堆顶
        swap(m_array[0], m_array[i]);    //交换
        m_array.pop_back();                //去掉最后一个元素
        downElement(0,comp);            //将新的首元素下沉
    }
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
    ofstream out("output.txt");
    for (int i=0; i<a_array.size(); i++)
    {
        out << a_array[i] << endl;
    }
}

int main()
{
    vector<double> array;
    ifstream infile;
    infile.open("output.txt",ios::in);   //将文件流对象与文件连接起来
    string s;
    while(getline(infile,s))
    {
        array.push_back(atof(s.c_str()));
    }
    Heap<double> heap(array);
    //heap.sort(less<double>());
    heap.sort(greater<double>());
    return 0;
}
}
