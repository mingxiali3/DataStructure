/*

    题1：从顺序表中删除具有最小值(假设唯一)并由函数返回被删元素的值，空出的位置由
    最后一个元素填补，若顺序表为空，则显示出错误信息并退出返回。

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
void sequence(SqList &L,int &index)
{
    int min = 100;
    
    for(int i = 0; i < L.length;i++)
    {
       if(L.data[i] < min)
       {
           min = L.data[i];
           printf("The minimum value is : data[%d]=%d\n",i,L.data[i]);
           index = i;    
       } 
    }
    //L.data[index]=L.data[L.length-1];
    //L.length--;


}
bool ListDelete(SqList &L,int i,int &e){
    if(i<1 || i>L.length) //判断i的范围是否有效
        return false;
    e=L.data[i-1];//将被删除的元素赋值给e
    L.data[i-1] = L.data[L.length-1];
    // for(int j=i;j<L.length;j++)//将第i个位置后的元素前移
    //     L.data[j-1]=L.data[j];//问题规模n =L.length
    L.length--;
    return true;
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
    printf("Before...\n");
    printList(L);
    int index = 1;//声明index 是为了把那个值最小的元素的索引带回来
    sequence(L,index);
    printf("The deleted value is data[%d]=%d\n",index,L.data[index]);
    int e = -1;
    ListDelete(L,index+1,e);
    printf("After...\n");
    printList(L);
    return 0;       
    
}