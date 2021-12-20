/*
  [名称]:02_calculateLocalziation.cpp
  [示范]:1.计算一维数组指定元素的地址
         一维数组不必考虑是以行为主，或是以列为主
        2.计算二维数组指定元素的地址
         a.以行为主
         b.以列为主
        3.计算三维数组指定元素的地址
         a.以行为主
         b.以列为主

*/
#include <iostream>
using namespace std;

//i 为下标数，a 为首地址，d为单位空间(这里默认为整型),m为A(m:n)的索引起始值,n为A(m:n)的索引终止值
int calc_oneDim(int i,int a,int d,int m);
//i,j 为下标数，a 为首地址，d为单位空间(这里默认为整型),m1,n1为A(m1:m2,n1:n2)的索引起始值,m2,n2为A(m1:m2,n1:n2)的索引末端值
//那么此数组共有m=(m2-m1+1)行,n=(n2-n1+1)列
int calc_twoDim(int i,int j,int a,int d,int m1,int m2,int n1,int n2, bool IsRow);
//i,j,k 为下标数，a 为首地址，d为单位空间(这里默认为整型),l1,l2,l3为A(l1:u1,l2:u2,l3:u3)的索引起始值，u1,u2,u3为A(l1:u1,l2:u2,l3:u3)的索引末端值
int calc_threeDim(int i,int j,int k,int a,int d,int l1,int u1,int l2,int u2,int l3,int u3,bool IsRow);

int main()
{

  /*******************************************计算一维数组********************************************/

   //1.假设A为一个具有1000个元素的数组，每个元素为4个字节的实数，A[500]的位置为4096，请问A[1000]的地址是多少？
   //calc_oneDim(1000,4096,4,500);

   //2.有一个PASCAL数组 A:ARRAY[6...99] of REAL(假设REAL元素存储空间的大小有4)，如果已知数组A的起始地址为500，
   //则元素A[30]的地址是多少？
   //calc_oneDim(30,500,4,6);


  /*******************************************计算二维数组********************************************/
   //1.现有一个二维数组A，有3x5个元素，数组的起始地址A(1,1)是100，以行为主(row-major)排列，每个元素占2个字节，
   //A(2,3)的地址是多少？
   //calc_twoDim(2,3,100,2,1,3,1,5,true);

   //2.二维数组A[1:5,1:6],如果是以列为主(colimn-major)方式存放，则A(4,5)排在此数组的第几个位置？(a=0,d=1)
   //false时，求列数，调转i,j输入
   //calc_twoDim(5,4,0,1,1,5,1,6,false);

   //3.数组(Array)是以PASCAL语言来声明，每个数组元素占用4个单位的内存。若起始地址是255，在下列声明中，
   //所列元素存放的位置在哪里？
   //VarA=array[-55..1,1..55]，求A[1,12]的地址
   //calc_twoDim(1,12,255,4,-55,1,1,55,true);
   //VarA=array[5..20,-10..40],求A[5,-5]的地址
   //calc_twoDim(5,-5,255,4,5,20,-10,40,true);

   //4.A(-3:5,-4:2)的起始地址A(-3,-4)=1200，以行为主(row-major)排列，每个元素占1个字节，请问Loc(A(1,1))=?
   //calc_twoDim(1,1,1200,1,-3,5,-4,2,true);

   //5.假设我们以FORTRAN语言来声明浮点数的数组A[8][10],且每个数组元素占用4个单位的内存，如果A[0][0]的起始地址是200，
   //那么元素A[5][6]的地址是多少？
   //false时，求列数，调转i,j输入
   //calc_twoDim(6,5,200,4,1,8,1,10,false);
   
   //6.A(-3:5,-4:2)数组的起始地址A(-3,-4) = 100,以行排列为主，请问Loc(A(1,1))=?
   calc_twoDim(1,1,100,1,-3,5,-4,2,true);

  /*******************************************计算三维数组********************************************/
  //1.有一个三维数组A(-3:2,-2:3,0:4)，以行为主(Row-major)方式排列，数组的起始地址是1118，试求Loc(A(1,3,3))=? (d=1)
   //calc_threeDim(1,3,3,1118,1,-3,2,-2,3,0,4,true);

  //2.假设有一个三维数组声明为A(-3:2,-2:3,0:4),A(1,1,1)=300,且d=2,试问以列为主的排列方式下，求出A(2,2,3)所在的地址。
  // calc_threeDim(2,2,3,300,2,-3,2,-2,3,0,4,false);
  
  //3.假设有以行为主排列的程序设计语言，声明A(1:3,1:4,1:5)数组，且Loc(A(1,1,1)) = 100,请求出Loc(A(1,2,3)) = ? (d =1 )
   //calc_threeDim(1,2,3,100,1,1,3,1,4,1,5,true);

  //4.A(6,4,2)是以列为主方式排列，若a = 300，且d =1,求A(4,4,1)的地址
   //calc_threeDim(4,4,1,300,1,1,6,1,4,1,2,false);
  
  //5.假设有一个三维数组声明为A(1:3,1:4,1:5),A(1,1,1)=300,且d=1,试问以列为主的排列方式下，求出A(2,2,3)的所在地址
   //calc_threeDim(2,2,3,300,1,1,3,1,4,1,5,false);

}
int calc_oneDim(int i,int a,int d,int m)
{
  cout << "一维数组:A" <<"(" << i << ")" << "\"\t";
  int loc = 0;
  //loc = a + (i-m)*d;
  loc = a + (i-m)*d;
  cout << "地址 loc: " << loc << endl;
  //cout << "排在这个数组的第 " << loc + 1 << " 个位置 " << endl;
  return loc;
}
int calc_twoDim(int i,int j,int a,int d,int m1,int m2,int n1,int n2, bool IsRow)
{
 
  cout << "二维数组:A" <<"(" << i <<"," << j << ")" << "\"\t";
  int m,n,loc_h,loc_l = 0;
  m = m2-m1+1;
  n = n2-n1+1;
  //以行为主
  //loc_h = a + ((i-m1+1)-1)*n*d + ((j-n1+1)-1)*d;
  loc_h = a + (i-m1)*n*d + (j-n1)*d;
  
  //以列为主
  //loc_l = a + ((i-m1+1)-1)*d + ((j-n1+1)-1)*m*d;
  loc_l = a + (i-m1)*d + (j-n1)*m*d;
  
  if (IsRow)
    {
    cout << "地址 loc_h: " << loc_h << endl;
    //cout << "排在这个数组的第 " << loc_h + 1 << " 个位置 " << endl;
    return loc_h;
    }
  else 
    {
    cout << "地址 loc_l: " << loc_l << endl;
    //cout << "排在这个数组的第 " << loc_l + 1 << " 个位置 " << endl; 
    return loc_l;
    }

}
int calc_threeDim(int i,int j,int k,int a,int d,int l1,int u1,int l2,int u2,int l3,int u3,bool IsRow)
{
  cout << "三维数组:A" <<"(" << i <<"," << j << ","<< k << ")" << "\"\t";
  int m,n,o,loc_h,loc_l = 0;
  m = u1-l1+1;
  n = u2-l2+1;
  o = u3-l3+1;
  //以行为主
  loc_h = a + (i-l1)*n*o*d + (j-l2)*o*d + (k-l3)*d;
  //以列为主
  loc_l = a + (k-l3)*m*n*d + (j-l2)*m*d + (i-l1)*d;

  if(IsRow)
  {
    cout << "地址 loc_h: " << loc_h << endl;
    //cout << "排在这个数组的第 " << loc_h + 1 << " 个位置 " << endl;
    return loc_h;
  }
  else
  {
    cout << "地址 loc_l: " << loc_l << endl;
    //cout << "排在这个数组的第 " << loc_l + 1 << " 个位置 " << endl;
    return loc_l;
  }

}
