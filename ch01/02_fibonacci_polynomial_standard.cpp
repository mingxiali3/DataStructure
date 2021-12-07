/*
[名称]：02_fibonacci_polynomial_standard.cpp
[示范]: 斐波拉契数列的递归程序
*/
#include <iostream>
using namespace std;

int fib(int);
int main()
{
  int i,n;
  cout << "请输入要计算前几个斐波拉契数列： ";
  cin >> n;
  for(i=0;i<=n;i++) //计算前n个斐波拉契数列
    cout << "第 "<< i << " 个斐波拉契数列的元素： " << fib(i) << endl;
}
int fib(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    return fib(n-1)+fib(n-2);

}