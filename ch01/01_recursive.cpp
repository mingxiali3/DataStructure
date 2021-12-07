/*
[名称]：01_recursive_mingxia.cpp
[示范]：1.用递归函数求 终端输入的数字 计算的递归结果
       2.用递归函数求 0-i 阶乘的值
       
*/
#include <iostream>
using namespace std;
int factorial(int i);
int main()
{
   int i;
   cout << "请输入 0-100 的整数 i： " << endl;
   cin >> i;//支持终端直接输入计算数字
   cout << "输出 0 ~ i-1的阶乘值 " << endl;
   for(int j=0;j<i;j++)
   cout<< j << "阶乘值为 " << factorial(j) << endl;
   return 0;
}
int factorial(int i)
{
    int sum;
    if(i == 0)  //跳出执行过程的出口
        return(1);
    else
        sum = i * factorial(i-1);//反复执行的递归过程
    return sum;
}