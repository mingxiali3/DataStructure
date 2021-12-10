/*
  [名称]:04_calculateThreeDimension.cpp
  [示范]:1.计算三维数组，同时设置初始值
         2.将数组中的所有元素利用循环输出
*/
#include <iostream>
using namespace std;
int main()
{
int A[2][2][2]={{{1,2},{5,6}},{{3,4},{7,8}}};
int i,j,k;
for(i=0; i < 2; i++) //外层循环
for(j=0; j < 2; j++) //中层循环
   for(k=0;k<2;k++) //内层循环
      cout << "A[" << i  << "]" <<"[" << j << "]" << "[" << k << "] = " << A[i][j][k] << endl;

}