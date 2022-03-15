/*

    题2：设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。


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
void sequence(SqList &L)
{
    int temp;
    printf("开始逆置....\n");
    for(int i=0; i< L.length / 2;i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}

int main()
{
    SqList L;//声明一个顺序表
    InitList(L);//初始化顺序表
    //此处插入一些元素
    ListInsert(L,1,10);
    ListInsert(L,2,9);
    ListInsert(L,3,90);
    ListInsert(L,4,11);
    ListInsert(L,5,1);
    ListInsert(L,6,19);
    ListInsert(L,7,81);
    ListInsert(L,8,29);   
    ListInsert(L,9,13);
    ListInsert(L,10,18);  
    printList(L);
    sequence(L);
    printList(L);
    return 0;       


}