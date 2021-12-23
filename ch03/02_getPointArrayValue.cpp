/*
 [名称]:02_getPointArrayValue.cpp
 [示范]：1.设计一个C++程序，说明指针变量获取动态分配数组的起始地址后，在程序中可以使用指针运算的
        方式来存取数组内各个元素的值，或者以数组下标的方式来存取元素值
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int no,count = 0,Total = 0;//定义整数变量count 与Total
    cout << "要输入计算的个数为: ";
    cin >> no;
    int *ptr = new int[no];//动态分配数组为n个元素
    cout << endl;
    for (count = 0; count < no;count++)
    {
        cout << "输入ptr[" << count << "]:";
        cin >> ptr[count];//采用数组下标来输入数组元素
    }
    for(count=0;count < no;count++)
        Total+=*(ptr+count);//采用指针变量运算来存取数组的元素
    cout << "---------------------------------" << endl;
    cout << no << "个数的总和= " << Total;//显示结果
    cout << endl;
    delete[] ptr;//释放分配给ptr的内存空间
    ptr = NULL;
    return 0;
}