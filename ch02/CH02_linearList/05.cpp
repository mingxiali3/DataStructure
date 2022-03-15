/*

   题5：从顺序表中删除其值在给定值s与t之间（包含s和t,要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错误信息并退出运行；


*/
#include <stdio.h>
#define MaxSize 10 // Define maximaSize
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
bool del_s2t(SqList &L,int s,int t)
{
   int i,k = 0;
   if(L.length == 0 || s >= t)
     return false;
   for(i=0;i<L.length;i++){
      if(L.data[i]>=s && L.data[i] <= t)
         k++;
      else
      L.data[i-k]=L.data[i];
   } 
   L.length-=k;
   return false;
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
    ListInsert(L1,5,5);
    ListInsert(L1,6,6);
    ListInsert(L1,7,7);
    ListInsert(L1,8,9);   
    ListInsert(L1,9,10);
    ListInsert(L1,10,11); 
    printf("Before....\n"); 
    printList(L1);   
    del_s2t(L1,3,9);
    printf("After....\n"); 
    printList(L1); 
    return 0;       


}