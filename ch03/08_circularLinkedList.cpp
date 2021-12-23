/*
 [名称]:08_circularLinkedlist.cpp 环形链表节点的创建与插入
 [示范]：1.设计一个C++程序，将前面的学生成绩链表改成环形链表的形式，并插入一个学生成绩数据
 的新节点。
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <iomanip>
using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
};
typedef struct list node;
typedef node *link;

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
link insertnode(link head,link after,int num,int score,char name[10])
{
    link InsertNode;
    InsertNode = new node;
    link CurNode = NULL;
    InsertNode->num = num;
    InsertNode->score = score;
    strcpy(InsertNode->name,name);
    InsertNode->next = NULL;
    if(InsertNode == NULL)
    {
        cout << "内存分配失败" << endl;
        return NULL;
    }
    else
    {
        if(head==NULL) //链表是空的
        {
            head = InsertNode;
            InsertNode->next=head;
            return head;
        }
        else
        {
            if(after==NULL) //新增节点到链表头部的位置
            {
                //(1)将新增节点的指针指向链表头部
                InsertNode->next=head;
                CurNode=head;
                while(CurNode->next!=head)
                    CurNode=CurNode->next;
                //(2)找到链表尾部，将它的指针指向新增节点
                CurNode->next=InsertNode;
                //(3)将链表头指针指向新增节点
                head=InsertNode;
                return head;
            }
            else //新增节点到链表头部以外的地方
            {
                //(1)将新增节点的指针指向after的下一个节点
                InsertNode->next=after->next;
                //(2)将节点after的指针指向新增节点
                after->next=InsertNode;
                return head;
            }
        }
    }

}
int main()
{
    link head,ptr,newnode;
    int new_num,new_score;
    char new_name[10];
    int i,j,position=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
                            {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout << "座号  成绩 座号 成绩 座号 成绩 座号  成绩" << endl;
    cout << "====================================" << endl;
    for(i=0;i<12;i++)
    {
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            cout << "[" << data[j*3+i][0] << "] [" << data[j*3][1] << "] ";
        cout << endl;
    }
    head = new node;//建立链表的头指针
    if(!head)
    {
        cout << "Error !!内存分配失败!! " << endl;
        exit(1);
    }
    head->num = data[0][0];
    for(j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next = NULL;
    ptr=head;
    for(i=1;i<12;i++) //建立链表
    {
        newnode = new node;
        newnode->num = data[i][0];
        for(j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->next=NULL;
        ptr->next=newnode;//将前一个节点指向新创建的节点
        ptr=newnode;//新节点成为前一个节点
    }
    newnode->next = head;//将最后一个节点指向头部节点就成了环形链表
    while (1)
    {
        cout << "请输入要插入其后的学生编号，结束输入-1:";
        cin >> position;
        if(position==-1)
            break;
        else
        {
            ptr=findnode(head,position);
            cout << "请输入新插入的学生编号: ";
            cin >> new_num;
            cout << "请输入新插入的学生成绩: ";
            cin >> new_score;
            cout << "请输入新插入的学生姓名: ";
            cin >> new_name;
            head=insertnode(head,ptr,new_num,new_score,new_name);
        }
    }
    ptr=head;
    cout << "\n\t座号\t 姓名\t成绩\n";
    cout << "\t==================\n";
    do
    {
        cout << "\t["<<ptr->num << "]\t[ " << setw(10) << ptr->name << "]\t[" << ptr->score << "]\n";
        ptr=ptr->next;//指向下一个节点
    } while (head!= ptr && head!= head->next);
    delete newnode;
    return 0;
}