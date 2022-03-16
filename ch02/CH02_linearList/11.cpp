/*
  题11.一个长度为L（L>= 1）的升序序列S，处在第[L/2]个位置的数称为S的中位数。例如，若序列S1=(11,13,15,17,19),
  则S1的中位数是15，两个序列的中位数是含它们所有元素的升序序列的中位数。
  例如，若S2 = （2，4，6，8，20），则S1和S2的中位数是11，现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能
  高效的算法，找出两个序列A和B的中位数，要求：
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
void sequence(SqList L1,SqList L2,SqList &L3,int& mid)
{
    int i,j,k;
    for(i=0,j=0,k=0;i<L1.length && j < L2.length;)
    {
      if(L1.data[i] < L2.data[j])
      {
        L3.data[k++]=L1.data[i++];
        //printf("i=%d\n",i);
      }
      else if(L1.data[i] > L2.data[j])
      {
        L3.data[k++]=L2.data[j++];
        //printf("j=%d\n",j);
      }
      else
      {
        L3.data[k++]=L1.data[i++];
        //printf("i=%d\n",i);
      }
    }
    while(i>j)
    {
      L3.data[k++] = L2.data[j++];
    }
    while(i<j)
    {
      L3.data[k++] = L1.data[i++];
    }
    L3.length += k;
    mid = L3.data[L3.length/2];
  
}
int main()
{
    SqList L1,L2,L3;//声明一个顺序表
    InitList(L1);//初始化顺序表
    InitList(L2);
    InitList(L3);
 
    //此处插入一些元素
    ListInsert(L1,1,1);
    ListInsert(L1,2,1);
    ListInsert(L1,3,3);
    ListInsert(L1,4,4);
    ListInsert(L1,5,4);

    ListInsert(L2,1,2);
    ListInsert(L2,2,7);
    ListInsert(L2,3,9);   
    ListInsert(L2,4,10);
    ListInsert(L2,5,11); 
    printf("First is L1: \n");
    printList(L1);
    printf("Second is L2: \n");
    printList(L2);
    int mid=-1;
    sequence(L1,L2,L3,mid);
    printf("Third is L3: \n");
    printList(L3);
    printf("两个序列的中位数=%d\n",mid);
    return 0;       
}