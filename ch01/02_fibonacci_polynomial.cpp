/*
[名称]：02_fibonacci_polynomial_mingxia.cpp
[示范]：1.用递归函数求斐波拉契数列    
*/
#include <iostream>
using namespace std;
int fib(int n);
int main()
{
   int i;
   cout << "请输入 要计算前几个斐波拉契数列： " ;
   cin >> i;//支持终端直接输入计算数字
   cout << "输出 0 ~ i的斐波拉契数列 " << endl;
   for(int j=0;j<=i;j++)
   cout<< "第 " << j << "个斐波拉契数列元素为： " << fib(j) << endl;
   return 0;
}
int fib(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    return fib(n-1) + fib(n-2);//递归调用自身2次
}