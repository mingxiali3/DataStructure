/*
 [名称]:18_matrixMultiply.cpp
 [示范]：1.设计一个C++程序实现2个可自行输入矩阵维数的矩阵相乘，并显示相乘后的结果；
        2.A是一个m*n的矩阵，B是一个n*p的矩阵
        3.A*B之后的结果为一个m*p的矩阵C
        矩阵相乘的方法：
        C11=a11*b11+a12*b21+....+a1n*bn1
        ...
        C1p=a11*b1p+a12*b2p+....+a1n*bnp
        ...
        Cmp=am1*b1p+am2*b2p+....+amn*bnp

*/
#include <iostream>
using namespace std;
void MatrixMultiply(int*,int*,int*,int,int,int);
int main()
{
   int i,j;
   int M,N,P,row,col;
    cout << "[输入A矩阵的维数MXN]" << endl;
    cout << "请输入维数M: ";
    cin >> M;
    cout << "请输入维数N: ";
    cin >> N;
    
    int *A = new int [M*N];//声明动态数组
    int *B = new int [N*P];
  

    cout << "请输入矩阵A的内容" << endl;
    for(row=0;row <M;row++)
    {
        for(col=0;col<N;col++)
        {
            cout << "a" << row << col << "=";
            cin >> A[row*N+col];
        }
    }


    cout << "请输入矩阵B的内容" << endl;
    cout << "[输入B矩阵的维数NXP]" << endl;
    cout << "请输入维数P: ";
    cin >> P;  
    for(row=0;row <N;row++)
    {
        for(col=0;col<P;col++)
        {
            cout << "b" << row << col << "=";
            cin >> B[row*N+col];
        }
    }
    int *C = new int [M*P];
    //调用矩阵相乘函数
    MatrixMultiply(A,B,C,M,N,P);
    cout << "[AXB的结果是]" << endl;
    for(i=0 ; i<M;i++)
    {
        for(j=0;j<P;j++)
            cout << C[i*P+j] << "\t";
        cout << endl;
    }
    return 0;
}
void MatrixMultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P)
{
    if(M<=0 || N<=0 || P<=0)
    {
        cout << "[错误：维数M，N，P必须大于0]" << endl;
        return;
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<P;j++)
        {
            int Temp;
            Temp = 0;
            for(int k = 0; k< N;k++)
                Temp = Temp + arrA[i*N+k]*arrB[k*P+j];
            arrC[i*P+j] = Temp;
        }
    }
}