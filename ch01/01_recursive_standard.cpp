/*
[名称]：01_recursive_satndard.cpp
[示范]：用递归函数求0-4阶乘的值
*/
#include <iostream>
using namespace std;
int recursive(int);
int main()
{
    for(int i=0;i<5;i++)
        cout << i << " 阶乘值为 "<< recursive(i) << endl;
    return 0;
}
int recursive(int i)
{
    int sum;
    if(i == 0)
        return(1);
    else
     sum = i*recursive(i-1);
    return sum;
}