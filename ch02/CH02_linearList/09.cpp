
/*
  题9.线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内，要求设计一个算法，完成用最少时间
  在表中查找数值为x的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
*/
#include <stdio.h>
#define MaxSize 15 // Define maximaSize
#define arraySize 20
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
void seacherX(SqList &L,int x)
{
   int temp,temx;
   int i = 0;
   int k = 0;
   for(i=0;L.data[i] != x && i < L.length;i++);
   if(i < L.length)
    
    {
      printf("have found data[%d]=%d\n",i-1,L.data[i-1]);
      temp=L.data[i];
      L.data[i]=L.data[i-1];
      L.data[i-1] = temp;

    }
   else
     {
       for(i=0; L.data[i] < x && i<L.length;i++);//找出第一个比x大的元素对应的i
       //从i+1位开始，元素往后移一位，第i位接收x的值；注意这是一个有序表
       for(int j = L.length; j> i;j--)
        L.data[j]=L.data[j-1];
      L.data[i]=x;
      L.length++;
     }
   
}
int main()
{
    SqList L1,L2;//声明一个顺序表
    InitList(L1);//初始化顺序表
    InitList(L2);
    int A[arraySize]={0};
    //此处插入一些元素
    ListInsert(L1,1,1);
    ListInsert(L1,2,1);
    ListInsert(L1,3,3);
    ListInsert(L1,4,4);
    ListInsert(L1,5,4);
    ListInsert(L1,6,7);
    ListInsert(L1,7,7);
    ListInsert(L1,8,9);   
    ListInsert(L1,9,10);
    ListInsert(L1,10,11); 
    printf("Before..L1...\n"); 
    printList(L1); 
    seacherX(L1,5);//插入原数组里没有的5和12
    seacherX(L1,12);
    printf("After..\n");
    printList(L1);
    return 0;       


}