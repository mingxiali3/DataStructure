/*
  [名称]:06_findThreeDimensionValue.cpp
  [示范]:1.计算此数组中所有元素值的总和，并将值为负数的元素值都换为0
         2.输出新数组的所有内容
*/
#include <iostream>
using namespace std;
int main()
{
    int A[4][3][3] = {{{1,-2,3},{4,5,-6},{8,9,2}},{{7,-8,9},{10,11,12},{-1,3,2}},
                   {{-13,14,15},{16,17,18},{3,6,7}},{{19,20,21},{-22,23,24},{-6,9,12}}};
     int i,j,k;
     int total = 0;
     for(i=0; i < 4; i++) //外层循环
      for(j=0; j < 3; j++) //中层循环
       for(k=0; k<3; k++) //内层循环
          total += A[i][j][k];
          if (A[i][j][k] < 0)
             A[i][j][k] = 0;
     cout << "原数组所有元素值的总和： " << total << endl;
     for(i=0; i < 4; i++) //外层循环
      for(j=0; j < 3; j++) //中层循环
       for(k=0; k<3; k++) //内层循环
         cout << A[i][j][k] << " " ;
      cout << endl;
     return 0;  
}