/*

  题14：定义三元组(a,b,c)(a,b,c均为正数)的距离D=|a-b|+|b-c|+|c-a|。
  给定3个非空整数集合S1,S2和S3，按升序分别存储在3个数组中。
  请设计一个尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)(a属于S1,b属于S2,c属于S3)中的最小距离。
  例如S1={-1,0,9},S2={-25,-10,10,11},S3={2,9,17,30,41},则最小距离为2，相应的三元组为(9,10,9)。要求：
  1）给出算法的基本设计思想；
  2）根据设计思想，采用C/C++语言描述算法，关键之处给出注释；
  3)说明你设计算法的时间复杂度和空间复杂度。


*/
/*
  condition:D=|a-b|+|b-c|+|c-a|>=0
*/
#include <stdio.h>
#define MaxSize 15 // Define maximaSize
#define INT_MAX 0x7fffffff

typedef struct{
    int data[MaxSize];
    int length;
}SqList;
int abs_(int a){
  if(a<0) return -a;
  else return a;
}
void InitList(SqList &L)
{
    for(int i = 0; i< MaxSize;i++)
        L.data[i]=0;
    L.length = 0;
}
bool ListInsert(SqList &L,int i,int e){
    if(i<1 || i > L.length+1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(int j = L.length; j>= i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    //printf("in the position %d succesful set %d\n",i,e);
    L.length++;
    return true;
}
void printList(SqList &L)
{
    for(int i = 0; i < L.length;i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
}
bool xls_min(int a,int b,int c){
  if(a<=b && a<=c) return true;
  return false;
}
int findMinoTrip(SqList L1,SqList L2,SqList L3){

  int n = L1.length;
  int m = L2.length;
  int p = L3.length;
  int i=0;int j=0;int k=0;
  int D_min = INT_MAX;
  int D;
  while(i<n && j<m && k<p && D_min >0){
    D=abs_(L1.data[i]-L2.data[j])+abs_(L2.data[j]-L3.data[k])+abs_(L3.data[k]-L1.data[i]);//calcute D
    if(D<D_min) D_min = D;//Update D
    if(xls_min(L1.data[i],L2.data[j],L3.data[k]) { i++ };//update L1
    else if(xls_min(L2.data[j],L3.data[k],L1.data[i])) j++;
    else k++;
  }
  return D_min;
}

int main()
{
    SqList L1,L2,L3;//声明一个顺序表
    InitList(L1);//初始化顺序表
    InitList(L2);
    InitList(L3);
    int major;

 
    //此处插入一些元素
    ListInsert(L1,1,-1);
    ListInsert(L1,2,0);
    ListInsert(L1,3,9);
    ListInsert(L2,1,-25);
    ListInsert(L2,2,-10);
    ListInsert(L2,3,10);
    ListInsert(L2,4,11);
    ListInsert(L3,1,2);
    ListInsert(L3,2,9);
    ListInsert(L3,3,17);
    ListInsert(L3,4,30);
    ListInsert(L3,5,41);


    printf("First is L1: \n");
    printList(L1);


    return 0;       
}