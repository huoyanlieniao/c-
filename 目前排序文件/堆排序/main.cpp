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

    //comp Ϊless<Type> ������³���������С�ѣ���С��������
    //comp Ϊgreater<Type> ��С���³����������ѣ��Ӵ�С����
    template<typename Compare>
    void creatHeap(Compare comp);                //������

    template<typename Compare>
    void downElement(int a_elem, Compare comp);    //�³�Ԫ��
};

template<typename Type>
template<typename Compare>
void Heap<Type>::sort(Compare comp)
{

   // printArray(m_array);
    creatHeap(comp);                    //����
    vector<Type> array;
     double a1,b1;
     double c;
      cout<<"����"<<endl;
     a1 = clock();
    for (int i = m_array.size() - 1; i >= 0; i--)
    {
        array.push_back(m_array[0]);    //�����Ѷ�
        swap(m_array[0], m_array[i]);    //����
        m_array.pop_back();                //ȥ�����һ��Ԫ��
        downElement(0,comp);            //���µ���Ԫ���³�
    }
    b1= clock();
    c = (double)(b1 - a1);
    printf("����%f\n",(c/CLOCKS_PER_SEC));
    printArray(array);
    m_array.assign(array.begin(),array.end());

}

template<typename Type>
template<typename Compare>
void Heap<Type>::creatHeap(Compare comp)
{
    //�����һ����Ҷ�ӽڵ㿪ʼ����ÿ�����ڵ㶼����Ϊ��С��
    for (int i=m_array.size()/2-1; i>=0; i--)
    {
        downElement(i, comp);
    }
}

template<typename Type>
template<typename Compare>
void Heap<Type>::downElement(int a_elem, Compare comp)    //�³�Ԫ��
{
    int min;            //������СԪ���±�
    int index = a_elem;    //��ǰ�³���Ԫ���±�
    while (index*2+1 < m_array.size())//������ڵ�
    {
        min = index*2+1;
        if (index*2+2 < m_array.size())//�����ҽڵ�
        {
            //���ҽڵ�Ƚϣ�ѡ����С��
            if (comp(m_array[index*2+2],m_array[min]))
            {
                min = index*2+2;
            }
        }
        //ͬ�ӽڵ�Ƚϣ������ڵ���С�����
        if (comp(m_array[index],m_array[min]))
        {
            break;
        }
        else//ѡ��СԪ�ص����ڵ�
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
    cout<<"�������"<<endl;
     e1 = clock();
    ofstream out("out.txt");
    for (int i=0; i<a_array.size(); i++)
    {
        out << a_array[i] << endl;
    }
     f1= clock();
    c = (double)(f1 - e1);
    printf("���%f\n",(c/CLOCKS_PER_SEC));
}

int main()
{
    double a,b,c;
    clock_t a1,b1,c1,d1,e1,f1;
    cout<<"��ʼ���Ѷ�ȡ����"<<endl;
    vector<double> array;
    ifstream infile;
    infile.open("output.txt",ios::in);   //���ļ����������ļ���������
    string s;
    a1 = clock();
    while(getline(infile,s))
    {
        array.push_back(atof(s.c_str()));
    }
     b1 = clock();
    a = (double)(b1 - a1);
    printf("��ȡ:%f\n",(a/CLOCKS_PER_SEC));
    cout<<"��������"<<endl;
    c1= clock();
    Heap<double> heap(array);
    d1 = clock();
     b= (double)(d1 - c1);
    printf("����%f\n",(b/CLOCKS_PER_SEC));

    heap.sort(less<double>());

   // heap.sort(greater<double>());
    return 0;
}

