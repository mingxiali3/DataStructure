/*
 [名称]:12_delete4doubleLinkedList.cpp (运行不稳定)
 [示范]：1.设计一个C++程序，从上述学生成绩的双向链表，删除一个学生成绩数据的节点。
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *llink;
        class list *rlink;
};
typedef class list node;
typedef node *link;

link findnode(link head,int num)
{
    link ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->num==num)
            return ptr;
        ptr = ptr->rlink;
    }
    return ptr;
}
link deletenode(link head,link del)
{
    if(head==NULL) //双向链表是空的
    {
        cout << "[链表是空的]" << endl;
        return NULL;
    }
    if(del==NULL)
    {
        cout << "[错误:不是链表中的节点]" << endl;
        return NULL;
    }
    if(del==head)
    {
        head=head->rlink;
        head->llink=NULL;
    }
    else
    {
        if(del->rlink=NULL) //删除链表尾
        {
            del->llink->rlink=NULL;
        }
        else //删除中间节点
        {
            del->llink->rlink=del->rlink;
            del->rlink->llink=del->llink;
        }
    }
    free(del);
    return head;
}
int main()
{
    link head,ptr;
    link llinknode=NULL;
    link newnode=NULL;
    int new_num,new_score;
    char new_name[10];
    int i,j,position = 0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},
    {"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},{"Hanson"},{"Amy"},
    {"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));
    cout << "座号 成绩 座号 成绩 座号 成绩 座号 成绩 "<< endl;
    cout << "===================================="<< endl;
    for(i=0;i<12;i++)
    {
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            cout << "[" << setw(2) << data[j*3+i][0]
            << "] [ " << setw(3) << data[j*3+i][1] << "] ";
        cout << endl;
    }
    head=new node;//建立链表头指针
    if(head==NULL)
    {
        cout << "Error!! 内存分配失败!!" << endl;
        exit(1);
    }
    else
    {
        head=new node;
        head->num=data[0][0];
        for(j=0;j<10;j++)
            head->name[j]=namedata[0][j];
        head->score=data[0][1];
        llinknode=head;
        for(i=1;i<12;i++) //建立链表
        {
            newnode=new node;
            newnode->llink = NULL;
            newnode->rlink = NULL;
            newnode->num = data[i][0];
            for(j=0;j<10;j++)
                newnode->name[j]=namedata[i][j];
            newnode->score=data[i][1];
            llinknode->rlink=newnode;
            newnode->llink=llinknode;
            llinknode=newnode;
        }
    }
    while(1)
    {
        cout <<"请输入删除的学生编号，结束输入-1: ";
        cin >> position;
        if(position==-1) //循环中断条件
            break;
        else
        {
            ptr=findnode(head,position);
            head=deletenode(head,ptr);
        }
    }
    cout<<endl << "\t座号\t     姓名\t成绩" <<endl;
    cout<< "\t==========================="<<endl;
    ptr=head;
    while(ptr!=NULL)
    {
        cout << "\t[" << setiosflags(ios::right)
        << setw(2) << ptr->num << "]\t[ "
        << setiosflags(ios::left) << setw(10)
        << ptr->name << "]\t[ " << setw(3) << ptr->score << "] " << endl;
        ptr=ptr->rlink;
    }
    system("pause");
    return 0;
}