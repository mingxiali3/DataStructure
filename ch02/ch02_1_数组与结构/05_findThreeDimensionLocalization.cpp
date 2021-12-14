/*
  [名称]:05_findThreeDimensionLocalization.cpp
  [示范]:1.已知a[0][0][0]的起始地址为0023EAD0,
          通过C/C++中的&（取址运算符）求出数组元素所在的地址。
*/
#include <iostream>
using namespace std;
int main()
{
    int a[10][11][12];
    //&a[0][0][0] = 0023EAD0;
    cout << "&a[0][0][0]: " << &a[0][0][0] << endl;
    cout << "&a[3][4][6]: " << &a[3][4][6] << endl;
    return 0;
}