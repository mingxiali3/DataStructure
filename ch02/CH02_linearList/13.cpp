/*

  题13：给定一个含n(n>=1)个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组{-5,3,2,3}中未出现的最小正整数是1；数组{1,2,3}中未出现的最小
  正整数是4，要求：
  1）给出算法的基本设计思想；
  2）根据设计思想，采用C/C++语言描述算法，关键之处给出注释；
  3)说明你设计算法的时间复杂度和空间复杂度。


*/
#include <stdio.h>
#define MaxSize 15 // Define maximaSize
#include "stdlib.h"

typedef struct{
    int data[MaxSize];
    int length;
}SqList;
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
int findMissMin(SqList L,int n)
{
   int i,*B;
   B=(int*)malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
   {
     if(L.data[i]>0 && L.data[i]<=n) //if L.data[i]between 1~n,then marked array B
      B[L.data[i]-1]=1;
   }
   for(i=0;i<n;i++) //scan array B,find the target value
   {
     if(B[i]==0)
      break;
   }
   return i+1;
}
int main()
{
    SqList L1;//声明一个顺序表
    InitList(L1);//初始化顺序表
    int missMin;

 
    //此处插入一些元素
    ListInsert(L1,1,2);
    ListInsert(L1,2,1);
    ListInsert(L1,3,2);
    ListInsert(L1,4,1);
    ListInsert(L1,5,2);


    printf("First is L1: \n");
    printList(L1);
    
    missMin= findMissMin(L1,10);
    printf("missMan:%d\n",missMin);

    return 0;       
}