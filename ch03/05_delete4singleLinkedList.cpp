/*
 [名称]:05_delete4singleLinkedList.cpp
 [示范]：1.设计一个C++程序，实现建立一组学生成绩的链表，包含了座号，姓名与成绩三种数据。
 只要输入想要删除的成绩，就开始遍历该链表，找到并删除该位学生的节点。
 要结束时，请输入"-1"，则此时会列出此链表未删除的所有学生的数据。
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib> //使用随机数的头文件
using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
};
list del_ptr(list *head,list *ptr);
int main()
{
    list *ptr;
    int findword=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Moko"},{"Lean"},{"Melissa"},{"Angel"},
    {"Sabrina"},{"Joyce"},{"Jasica"},{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
    srand((unsigned)time(NULL));//以时间为随机数的种子
    cout << "座号 成绩 座号 成绩 座号 成绩 座号 成绩 " << endl;
    cout << "==========================================" << endl;
    for(int i=0;i<12;i++)
    {
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;//随机生成成绩
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            cout << "[" << data[j*3+i][0] << "]  [" << data[j*3+i][1] << "] ";
        cout << endl;
    }
    list *head = new list;//建立链表头指针
    if(!head)
    {
        cout << "Error!!内存分配失败！！" << endl;
        exit(1);
    }
    head->num = data[0][0];
    for(int j=0;j<10;j++)
        head->name[j]=namedata[0][j];
    head->score=data[0][1];
    head->next=NULL;
    ptr=head;
    for(int i=1;i<12;i++)
    {
        list *newnode=new list;//建立链表
        newnode->num=data[i][0];
        for(int j=0;j<10;j++)
            newnode->name[j]=namedata[i][j];
        newnode->score=data[i][1];
        newnode->next=NULL;
        ptr->next=newnode;
        ptr=ptr->next;
    }
    while (1)
{
        cout << "请输入要删除的成绩，结束输入-1: ";
        cin >> findword;
        if(findword==-1) //循环中断条件
            break;
        else
        {
            ptr=head;
            find=0;
            while (ptr!=NULL)
            {
                if(ptr->score==findword)
                {
                    *ptr=del_ptr(head,ptr);//删除数据
                    find++;
                }
                ptr=ptr->next;
            }
            if(find==0)
            cout << "########没有找到###########"<< endl;
        }   
    }
    ptr=head;
    cout << "\n\t座号\t 姓名\t成绩"<< endl;//输出剩余链表中的数据
    cout << "\t==========================="<<endl;
    while(ptr!=NULL)
    {
        cout << "\t[" << ptr->num << "]\t[" << setw(10) << ptr->name << "]\t[" << ptr->score << "]" << endl;
        ptr=ptr->next;
    }
    
}
list del_ptr(list *head,list *ptr) //删除节点子程序
{
    list *top;
    top=head;
    if(ptr==head)//[情形1]:删除节点在链表头部
    {
        head = head->next;
        cout << "已删除第 " << ptr->num << " 号学生!!姓名: " << ptr->name << endl;
    }
    else
    {
        while(top->next!=ptr) //找到删除节点的前一个位置
            top=top->next;
        if(ptr->next==NULL) //[情形2]:删除节点在链表尾部
        {
            top->next=NULL;
            cout << "已删除第 "<< ptr->num << " 号学生!!姓名： " << ptr->name << endl;
        }
        else //[情形3]:删除节点在链表中间的任一节点
        {
            top->next=ptr->next;
            cout << "已删除第 "<< ptr->num << " 号学生!!姓名： " << ptr->name << endl;
        }
    }
    delete[] ptr;//释放内存空间
    return *head;//返回链表
}