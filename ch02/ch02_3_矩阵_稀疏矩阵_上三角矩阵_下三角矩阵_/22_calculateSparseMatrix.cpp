/*
 [名称]:22_calculateSparseMatrix.cpp
 [示范]：1.已知稀疏矩阵A={{0,0,0,0,3},{1,0,0,0,0},{0,0,0,4,0},{6,0,0,0,7},{0,5,0,0,0}}；
        求它的压缩矩阵
*/
#include <iostream>
using namespace std;
void sparsematrix();
const int _ROWS = 5;//定义行数
const int _COLS = 5;//定义列数
const int _NOTZERO = 6;//定义稀疏矩阵中不为0的个数
int main()
{
    int i,j,tmpRW,tmpCL,tmpNZ;
    int tmp =1;
    int Sparse[_ROWS][_COLS]={{0,0,0,0,3},{1,0,0,0,0},{0,0,0,4,0},{6,0,0,0,7},{0,5,0,0,0}};//声明稀疏矩阵
    int Compress[_NOTZERO][3];//声明压缩矩阵

    cout << "[稀疏矩阵的各个元素]" << endl;//输出稀疏矩阵的各个元素
    for(i=0;i<_ROWS;i++)
    {
        for(j=0;j<_COLS;j++)
            cout << "[" << Sparse[i][j] << "]";
        cout << endl;
    }
    cout << "开始压缩稀疏矩阵..." << endl;

    Compress[0][0] = _ROWS;//此稀疏矩阵的行数
    Compress[0][1] = _COLS;//此稀疏矩阵的列数
    Compress[0][2] = _NOTZERO;//此稀疏矩阵非零项的总数
    for(i = 0; i < _ROWS; i++)
        for(j = 0 ;j < _COLS ; j++)
            if(Sparse[i][j] != 0)
            {
                Compress[tmp][0] = i+1;
                Compress[tmp][1] = j+1;
                Compress[tmp][2] = Sparse[i][j];
                tmp++;
            }
    cout << "[稀疏矩阵压缩后的内容]" << endl;//输出压缩矩阵的各个元素
    for(i=0;i<_NOTZERO+1;i++)
    {
        for(j=0;j< 3;j++)
            cout << "[" << Compress[i][j] << "]";
        cout << endl;
    }
    return 0;
}