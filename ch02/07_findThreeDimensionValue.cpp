/*
  [名称]:07_findThreeDimensionValue.cpp
  [示范]:1.利用三层嵌套循环来找出此2x3x3三维数组中所存储数值中的最小值
*/
#include <iostream>
using namespace std;
int main()
{
    int num[2][3][3] = {{{33,45,67},{23,71,56},{55,38,66}},
            {{21,9,15},{38,69,18},{90,101,89}}};
    int min = 1000;
    int i,j,k;
    for(i=0; i < 2; i++) //外层循环
      for(j=0; j < 3; j++) //中层循环
       for(k=0; k<3; k++) //内层循环
         if (num[i][j][k] < min)
             min = num[i][j][k];

    cout << "结束搜索 " << endl;   
    cout << "最小值是： " << min << endl;
    return 0;
}