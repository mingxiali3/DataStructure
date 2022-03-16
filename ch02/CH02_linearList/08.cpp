/*
    *题8.已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,a3,...,am)和(b1,b2,b3,...,bn)。
    编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)的前面。
    NOT have finished yet...
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
void reverse(SqList &L,int left,int right)
{
    //reverse (aleft,aleft+1,aleft+2...,aright) to (aright,aright-1,...,aleft)
    if(left >=right || right >= L.length)
        return;
    int mid = (left+right)/2;
    for(int i = 0; i <= mid-left;i++)
    {
        int temp =L.data[left+i];
        L.data[left+i]=L.data[right-i];
        L.data[right-i] = temp;
    }
}
void exchange(SqList &L,int m,int n)
{
    //In array A[m+n],from 0 to m-1 locate list (a1,a2,a3,..,am),from m to m+n-1 locate (b1,b2,b3,..,bn),this algorithm change this two list
    reverse(L,0,m+n-1);
    printf("The first : \n ");
    printList(L);
    reverse(L,0,n-1);
    printf("The second : \n");
    printList(L);
    reverse(L,n,m+n-1);
    printf("The third : \n");
    printList(L);
}
int main()
{
    SqList L1;//声明一个顺序表
    InitList(L1);//初始化顺序表
    
 
    //此处插入一些元素
    ListInsert(L1,1,1);
    ListInsert(L1,2,1);
    ListInsert(L1,3,3);
    ListInsert(L1,4,4);
    ListInsert(L1,5,4);
    ListInsert(L1,6,2);
    ListInsert(L1,7,7);
    ListInsert(L1,8,9);   
    ListInsert(L1,9,10);
    ListInsert(L1,10,11); 
    printf("Before..L1...\n"); 
    printList(L1); 
    printf("After exchange...\n"); 
    exchange(L1,3,7);
    //
    
    return 0;       


}