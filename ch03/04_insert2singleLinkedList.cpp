/*
 [名称]:04_insert2singleLinkedList.cpp
 [示范]：1.设计一个C++程序，在有12名学生的成绩链表中插入一个新数据节点。
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <iomanip> //操作符的头文件
using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
};
typedef class list node;
typedef node * link;
link findnode(link head,int num)
{
    link ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->num==num)
            return ptr;
        ptr=ptr->next;
    }
    return ptr;
}
link insertnode(link head,link ptr,int num,int score,char name[10])
{
    link InsertNode;
    InsertNode = new node;
    if(!InsertNode)
        return NULL;
    InsertNode->num = num;
    InsertNode->score = score;
    strcpy(InsertNode->name,name);
    InsertNode->next=NULL;
    if(ptr==NULL) //新插入第一个节点
    {
        InsertNode->next = head;
        return InsertNode;
    }
    else
    {
        if(ptr->next==NULL)//插入最后一个节点
        {
            ptr->next=InsertNode;
        }
        else //插入中间节点
        {
            InsertNode->next = ptr->next;//把ptr的伙伴给了InsertNode
            ptr->next=InsertNode;//InsertNode成为ptr的伙伴
        }
    }
    return head;
}
int main()
{
    link head,ptr,newnode;
    int new_num,new_score;
    char new_name[10];
    int i,j,position = 0,find,data[12][2];
    //char namedata[12][10]: 12个字符串，每个字符串字符数为10；
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},
    {"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout << "座号 成绩 座号 成绩 座号 成绩 座号 成绩"<< endl;
    cout << "=================================="<< endl;
    for(i=0;i<12;i++)
    {
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            cout << "[" << data[j*3+i][0] << "] [" << data[j*3+i][1] << "]  ";
        cout << endl;
    }

    head=new node;//建立链表头指针
    if(!head)
    {
        cout << "Error!!内存分配失败!!" << endl;
        exit(1);
    }
    head->num=data[0][0];
    for(j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for(i=1;i<12;i++) //建立链表
    {
        newnode=(link)malloc(sizeof(node));
        newnode->num=data[i][0];
        for(j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }
    while(1)
    {
        cout <<"请输入要插入其后的学生编号，结束输入-1: ";
        cin >> position;
        if(position==-1)//循环中断条件
            break;
        else
        {
            ptr=findnode(head,position);
            cout << "请输入新插入的学生编号： ";
            cin >> new_num;
            cout << "请输入新插入的学生成绩： ";
            cin >> new_score;
            cout << "请输入新插入的学生姓名: ";
            cin >> new_name;
            head = insertnode(head,ptr,new_num,new_score,new_name);
        }
    }
    ptr=head;
    cout << "\n\t座号\t    姓名\t成绩\n";
    cout << "\t===============================\n";
    while(ptr!=NULL)
    {
        cout << "\t[" << ptr->num << "]\t[ " << ptr->name << "]" << setw(6) << "\t[" << ptr->score << "]\n";
        ptr=ptr->next;
    }
    delete head;
    return 0;
}