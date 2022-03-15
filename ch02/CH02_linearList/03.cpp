/*

    题3*： 对长度为n的顺序表L，编写一个时间复杂度O(n),空间复杂度为O(1)的算法，该算法删除线性表中所有值
为x的数据元素。虽然做对了，但还是疑惑。

*/
#include <stdio.h>
#define MaxSize 10 //定义最大长度
typedef struct{
    int data[MaxSize];//用静态的“数组”存放数据元素
    int length;//顺序表的当前长度
}SqList;//顺序表的类型定义

void InitList(SqList &L)
{
    for(int i=0;i<MaxSize;i++)
        
       L.data[i]=0;
    
    L.length = 0;
}
bool ListInsert(SqList &L,int i,int e){
    if(i<1 || i >L.length+1) //判断i的范围是否有效
        return false;
    if(L.length >= MaxSize) //当前存储空间已满,不能插入
        return false;

    for(int j=L.length;j>=i;j--) //将第i个元素及之后的元素后移
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;//在位置i处放入e
    printf("在位置%d处成功放入%d\n",i,e);
    L.length++;//长度加1
    return true;
}
void printList(SqList &L)
{
    for(int i = 0; i < L.length;i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
}
/*
First method:

void sequence(SqList &L,int value)
{
    SqList _L;
    InitList(_L);
    //这里特意这么写的 将第i个元素及之后的元素后移
    for(int i = L.length-1; i >= 0;i--)
    {
    
       int j = 0;
       if(L.data[i] != value)
       {
         ++j;
         ListInsert(_L,j,L.data[i]);
         
       }  
    }
    printf("After....\n"); 
    printList(_L);
    
}
*/
/*
Second Method:
*/
void sequence(SqList &L,int value)
{
    int k = 0,i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]!= value)
        {
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length = k;
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
    sequence(L1,1);
    printf("After....\n"); 
    printList(L1); 
    return 0;       


}