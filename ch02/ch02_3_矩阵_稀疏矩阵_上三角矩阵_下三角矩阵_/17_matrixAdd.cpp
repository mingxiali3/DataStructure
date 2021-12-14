/*
 [名称]:17_matrixAdd.cpp
 [示范]：1.设计一个C++程序实现2个mxn矩阵相加
*/
#include <iostream>
using namespace std;
int main()
{
    int ROWS = 3;
    int COLS = 3;
    int i,j;
    int A[ROWS][COLS] = {{1,3,5},{7,9,11},{13,15,17}};
    int B[ROWS][COLS] = {{9,8,7},{6,5,4},{3,2,1}};
    int C[ROWS][COLS];
    
    /*2个mxn矩阵相加的C++算法*/
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
      {
         C[i][j] = A[i][j]+B[i][j];//矩阵C = 矩阵A +矩阵B
         cout << C[i][j] << "\t";
      }
      cout << endl;
    }
    return 0;
}