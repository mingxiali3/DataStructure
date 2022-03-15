/*

   题7.将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。

*/
#include <stdio.h>
#define MaxSize 12 // Define maximaSize
typedef struct{
    int data[MaxSize];
    int maxSize = MaxSize;
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
    printf("in the position %d succesful set %d\n",i,e);
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
bool merge(SqList L1,SqList L2,SqList &L3)
{
    printf("merge...\n");
    if(L1.length + L2.length > L3.maxSize)
       {
        printf("Error!\n");
        return false;
       }
    int i=0,j=0,k=0;
    while(i<L1.length && j<L2.length){
        if(L1.data[i] <= L2.data[j])
        {
            L3.data[k++]=L1.data[i++];
           
        }
        else
        {
            L3.data[k++]=L2.data[j++];
        }
    }
    while(i<L1.length)
        L3.data[k++]=L1.data[i++];
    while(j<L2.length)
        L3.data[k++]=L2.data[j++];
    L3.length = k;
    return true;


    

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
    printf("L1...\n"); 
    printList(L1);  
    printf("L2...\n");
    printList(L2);
    merge(L1,L2,L3);
    printf("After L3....\n"); 
    printList(L3); 
    return 0;       


}