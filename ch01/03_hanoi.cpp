/*
[名称]：03_hanoi_mingxia.cpp
[示范]：用递归函数实现汉诺塔算法的求解:
       1) 利用汉诺塔函数求出不同盘子数的盘子移动步骤 
       2) 计算出盘子的移动次数 :num
       3) 计算出盘子移动的理论最小次数 :min

*/
#include <iostream>
using namespace std;
int num = 0;
void hanoi(int ,int ,int,int,int&);
void minnum(int&);
int main()
{
   int n;
   cout << "请输入盘子总的数量： " ;
   cin >> n;//支持终端直接输入计算数字
   hanoi(n,1,2,3,num);
   cout << " 移动盘子次数为： " << num << endl;
   int min = 1;
   for (int j = 0 ;j < n ;j++)
     minnum(min);
   cout << " 移动 " << n << "个盘子所需的最小移动次数为 " << min -1 << endl;
   return 0;
}
void hanoi(int n,int p1,int p2,int p3,int& num)
{
    if (n==1) //从递归出口
    cout << "盘子从 " << p1 << " 移到 " << p3 << endl;
    else
    {
        hanoi(n-1,p1,p3,p2,num);
        cout << "盘子从 " << p1 << " 移到 " << p3 << endl;
        hanoi(n-1,p2,p1,p3,num);
    }
    ++num;
}
void minnum(int& min)
{
    min = 2*min;
}