/*
 [名称]:21_TriangularMatrix.cpp
 [示范]：1.设计一个C++程序,计算各种三角形矩阵映射到一维数组后的数组索引值k。   
*/
#include <iostream>
using namespace std;
//上三角形矩阵就是一种对角线以下元素都为0的n*n矩阵。
int calc_rightUpperTriangularMatrix(int,int,int,bool);
//下三角形矩阵就是一种对角线以上元素都为0的n*n矩阵，其中也可分为左下三角形矩阵和右下三角形矩阵。
int calc_leftLowerTriangularMatrix(int,int,int,bool);
int calc_rightLowerTriangularMatrix(int,int,int,bool);
int calc_bandMatrix(int,int,int,bool);
int main()
{
  //1.假如有一个5x5的右上三角形矩阵A，以列为主映射到一维数组B，请问a23所对应B(k)的k值是多少？
  calc_rightUpperTriangularMatrix(2,3,5,false); 
  //2.有一个6x6的左下三角形矩阵，以列为主的方式映射到一维数组B，求元素a32所对应B(k)的k值是多少?
  calc_leftLowerTriangularMatrix(3,2,6,false);
  //3.假设有一个4x4的右下三角形矩阵，以列为主映射到一维数组B，求元素a32所对应B(k)的k值是多少?
  calc_rightLowerTriangularMatrix(3,2,4,false);
  //4.一个下三角数组(lower triangualr array),B是一个nxn的数组，其中B[i,j]=0,i<j。
  //1.求B数组中不为0的最大个数。
  //2.如何将B数组以最经济的方式存储在内存中。
  //3.写出在2的存储方式中，如何求得B[i,j],i>=j。
  /* 
  解:由题意得知B为左下三角形矩阵，因此不为0的个数为n*(n+1)/2
  可将B数组非零项的值以行为主(row-major)映射到一维数组A中:bij=A(k)
  以行为主的映射方式,bij=A(k);其中k=i*(i-1)/2 + j;
  */
 //5.已知有一个5x5的带状矩阵，以行为主映射到一维数组B，请问a32所对应B(k)的k值是多少？
   calc_bandMatrix(3,2,5,true);
}

int calc_rightUpperTriangularMatrix(int i,int j,int n,bool IsRow)
{
  int k = 0;
  cout << "这里计算的是右上三角形矩阵..." << endl;
  if (IsRow)
   {
    cout << "以行为主存储：" << endl;
    k = n*(i-1)-i*(i-1)/2 + j;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
   }
  else
   {
    cout << "以列为主存储：" << endl;
    k = j*(j-1)/2 + i;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
   }
}
int calc_leftLowerTriangularMatrix(int i,int j,int n,bool IsRow)
{
    int k = 0;
    cout << "这里计算的是左下三角形矩阵..." << endl;
    if (IsRow)
    {
        cout << "以行为主存储：" << endl;
    k = i*(i-1)/2 + j;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
    }
    else
    {
    cout << "以列为主存储：" << endl;
    k = n*(j-1)+i-j*(j-1)/2;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
    }
}
int calc_rightLowerTriangularMatrix(int i,int j,int n,bool IsRow)
{
    int k=0;
    cout << "这里计算的是右下三角形矩阵..." << endl;
    if (IsRow)
    {
         cout << "以行为主存储：" << endl;
    k = i*(i+1)/2 + j - n;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
    }
    else
    {
    cout << "以列为主存储：" << endl;
    k = j*(j+1)/2 + i - n;
    cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
    }
}
int calc_bandMatrix(int i,int j,int n,bool IsRow)
{
    cout << "这里计算的是带状矩阵..." << endl;
    int k=0;
    if (IsRow)
     {
     cout << "以行为主存储：" << endl;
     k = 2*i+j-2;
     cout << "a"<<i<<j<<"所对应的是B(" << k << ")" << endl;
     }
}