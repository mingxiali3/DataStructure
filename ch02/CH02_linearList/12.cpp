/*

  题12：已知一个整数序列A=(a0,a1,...,an-1)，其中0<=a1<n(0<= a1 < n),若存在ap1=ap2=...=apm=x 且 m > n/2 
  (0<= pk < n,1 <= k <= m),则称x为A的主元素，例如A=(0,5,5,3,7,5,5),则5为主元素；
  例如A=(0,5,5,3,5,7,5,5)则5为主元素；又如A=(0,5,5,3,5,1,5,7),则A中没有主元素，假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，求出A的主元素，若存在
  主元素，则输出该主元素，否则输出-1，要求：
  1）给出算法的基本设计思想；
  2）根据设计思想，采用C/C++语言描述算法，关键之处给出注释；
  3)说明你设计算法的时间复杂度和空间复杂度。


*/
#include <stdio.h>
#define MaxSize 15 // Define maximaSize

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
//算法思想：
int Majority(SqList &L)
{
  int i,c,count = 1;
  int n = L.length;
  c=L.data[0];
  for(i=1;i<n;i++)
  {
    if(L.data[i]==c)
      count++;
    else
      if(count > 0)
        count--;
      else
      {
        c=L.data[i];
        count = 1;
      }
  }
  if(count > 0)
  {
    for(i=count=0;i<n;i++)
      if(L.data[i]==c)
      {
        count++;
      }
  }
  if(count>n/2)
    return c;
  else
    return -1;
}

int main()
{
    SqList L1;//声明一个顺序表
    InitList(L1);//初始化顺序表
    int major;

 
    //此处插入一些元素
    ListInsert(L1,1,2);
    ListInsert(L1,2,1);
    ListInsert(L1,3,2);
    ListInsert(L1,4,1);
    ListInsert(L1,5,2);


    printf("First is L1: \n");
    printList(L1);
    
    major=Majority(L1);
    printf("major:%d\n",major);

    return 0;       
}