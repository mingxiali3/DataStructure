/*

    题10.设将n(n>1)个整数存放到一堆数组R中，设计一个在时间和空间两方面都高效的算法。将R中保存的序列循环左移p
    (0<p<n)个位置，即将R中的数据由(X0,X1,...Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)。要求：
    1）给出算法的基本设计思想；
    2)根据设计思想，采用C/C++语言描述算法，关键之出给出注释
    3)说明你设计算法的时间和空间复杂度

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
void exchange(SqList &L,int p)
{
    /*
    交换的算法思想：将这个题看作是前p个元素组成的list  与后n-p个元素组成的list 交换一下位置就可以了
    In array A[p + n-p],from 0 to p-1 locate list (a1,a2,a3,..,ap-1),in total:p elements;
    from p to n-1 locate (ap,ap+1,ap+2,..,an-1),in total:n-p elements;this algorithm change this two list
    */
    int m = p;
    int n = L.length-p;
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
    exchange(L1,3);
    //
    
    return 0;       
}