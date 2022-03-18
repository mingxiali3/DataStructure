#include "stdlib.h"
#include "stdio.h"
//单链表的插入,查找(按位查找，按值查找)，删除


typedef struct LNode{//定义单链表节点类型
    int data;//每个节点存放一个数据元素
    struct LNode *next;//指针指向下一个节点
}LNode,*LinkList;


//初始化一个单链表(带头结点)
bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));//分配一个头结点,头结点不存储数据
    if(L==NULL) //内存不足，分配失败
        return false;
    L->next = NULL;//头结点之后暂时还没有结点
    return true;
}
//后插操作(头插法建立单链表):在p结点之后插入元素e
/*
头插法建立单链表:
初始化单链表
while 循环{
    每次取一个数据元素e;
    InsertNextNode(L,e);
}
*/
LinkList List_HeadInsert(LinkList &L){//逆向建立单链表
   LNode *s;
   int x;
   L = (LinkList)malloc(sizeof(LNode));//创建头结点
   L->next = NULL;//初始为空链表,只要是初始化单链表，都先把头指针指向NULL
   scanf("%d",&x);//输入结点的值
   while(x!=-1){//输入-1表示结束
    s=(LNode*)malloc(sizeof(LNode));//创建新结点
    s->data = x;
    s->next = L->next;
    L->next = s;//将新结点插入表中，L为头指针
    scanf("%d",&x);
   }
   return L;

}
//后插操作:在p结点之后插入元素e
bool InsertNextNode(LNode *p,int e){
    //考虑到非法情况:健壮性
    if(p==NULL)
        return false;
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if(s==NULL) //内存分配失败
        return false;

    printf("在p结点之后插入元素e: \n");
    s->data = e;//用结点s保存数组元素e
    printf("new data is %d \n",e);
    s->next = p->next;
    p->next = s;//将结点s连到p之后
    return true;
}
/*
尾插法建立单链表:
初始化单链表
设置变量length 记录链表长度
while 循环{
    每次取一个数据元素e;
    ListInsert(L,length+1,e)插到尾部;
    length++;
}
时间复杂度分析:每次都从头开始之后遍历，时间复杂度为O(n^2)
*/
LinkList List_TailInsert(LinkList &L){//正向建立单链表
int x;//设ElemType建立单链表
L=(LinkList)malloc(sizeof(LNode));//建立头节点 初始化空表
LNode *s,*r = L;//r为表尾指针
scanf("%d",&x);//输入结点的值
while(x!=-1){//输入-1表示结束
    //在r结点之后插入元素x
    s=(LNode*)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;//r指向新的表尾结点 ；永远保持r指向最后一个结点
    scanf("%d",&x);
}
   r->next = NULL;//尾结点指针置空
   return L;

}


//按值查找
LNode* LocateElem(LinkList L,int e){
    LNode *p = L->next;
    //从第1个结点开始查找数据域为e的终点
    while(p!=NULL && p->data != e)
        p=p->next;
    printf("按值查找，值：%d在位序:%d\n",e,p->data);
    return p;//找到后返回该结点指针，否则返回NULL
}

//按位查找(带头结点)
//按位查找，返回第i个元素(带头结点)
LNode* GetElem(LinkList L,int i){
    if(i<0)
        return NULL;
    LNode *p;//指针p指向当前扫描到的终点
    int j = 0;//当前p指向的是第几个结点
    p = L;//L指向头结点，头结点是第0个结点(不存数据)
    while(p!=NULL && j< i){//循环找到第i个结点
       p=p->next;
       j++;
       printf("j=%d\n",j);
    }
    printf("按位查找，返回第%d个元素:%d\n",i,p->data);
    return p;
}
//按位序插入(带头结点)
// ListInsert(&L,i,e):插入操作，在表L中的第i个位置上插入指定元素e

bool ListInsert(LinkList &L,int i,int e){
    if(i<1)
        return false;
    // LNode *p;//指针p指向当前扫描到的结点
    // int j=0;//当前p指向的是第几个结点
    // p=L;//L指向头结点，头结点是第0个结点(不存数据)
    // while(p!=NULL && j < i-1){ //循环找到第i-1个结点
    // p=p->next;
    // j++;
    // printf("j=%d\n",j);
    // }
    LNode *p = GetElem(L,i-1);//找到第i-1个结点；上面注释的部分等同于GetElem(L,i-1);
    // if(p==NULL) //i值不合法
    //     return false;
    // LNode *s = (LNode*)malloc(sizeof(LNode));
    // s->data = e;
    // printf("s->data=%d\n",s->data);
    // s->next = p->next;
    // p->next = s;//将结点s连到p之后
    // return true;//插入成功
    return InsertNextNode(p,e);//上面注释的部分等同于后插操作：InsertNextNode(p,e);
}
//前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode *p,int e)
{  printf("前插操作：\n");
    if(p==NULL)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s==NULL) //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;//新结点s连到p之后
    s->data = p->data;//将p中元素复制到s中
    p->data = e;//p中元素覆盖为e
    return true;
}
//前插操作:在p结点之前插入结点s
bool InsertPriorNode(LNode *p,LNode *s){
    if(p==NULL || s==NULL)
        return false;
    s->next = p->next;
    p->next = s;//s连到p之后
    int temp = p->data;//交换数据域部分
    p->data = s->data;
    s->data = temp;
    return true;
}
//按位序删除(带头结点)
bool ListDelete(LinkList &L,int i,int &e){
    if(i<1)
        return false;
    // LNode *p;//指针指向p 指向当前扫描到的结点
    // int j = 0;//当前p指向的是第几个结点
    // p =L;//L指向头结点，头结点是第0个结点(不存数据)
    // while(p!=NULL && j < i-1){//循环找到第i-1个结点
    //     p = p->next;
    //     j++;
    // }
    LNode *p = GetElem(L,i-1);//找到第i-1个结点；上面的注释等同于GetElem(L,i-1);
    if(p==NULL) //i值不合法
        return false;
    if(p->next == NULL) //第i-1个结点之后已无其它结点
        return false;
    LNode *q = p->next;
    e = q->data;//用e返回元素的值
    p->next = q->next;//将*q结点从链中"断开"
    free(q);//释放结点的存储空间
    printf("已成功删除e=%d\n",e);
    return true;//删除成功
}
//指定结点的删除，这个不知道怎么测试？
bool DeleteNode(LNode *p)
{
    if(p==NULL)
        return false;
    LNode *q = p->next;//令q指向*p的后继结点
    p->data = p->next->data;//和后继结点交换数据域
    p->next = q->next;//将*q结点从链中"断开"
    free(q); //释放后继结点的存储空间
    return true;
}
//求表的长度,这个测试失败？
int Length(LinkList L){
    int len = 0;//统计表长
    LNode *p;
    p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    }
    
    printf("len=%d\n",len);
    return len;
}

int main()
{
    LinkList L1;
    ListInsert(L1,1,1);
    ListInsert(L1,2,2);
    ListInsert(L1,3,13);
    ListInsert(L1,4,4);
    ListInsert(L1,5,5);
    ListInsert(L1,6,15);
    int e = -1;
    ListDelete(L1,3,e);
    GetElem(L1,4);
    LocateElem(L1,1);
    Length(L1);
    return 0;
}