/*
 [名称]:09_deletecircularLinkedlist.cpp 环形链表节点的删除
 [示范]：1.设计一个C++程序，在上述的学生成绩环形链表，删除一个学生成绩数据节点
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
        class list *next;
};
typedef class list node;
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
link deletenode(link head,link del)
{
    link CurNode=NULL;
    link PreNode=NULL;
    link TailNode=NULL;
    if(head=NULL)
    {
        cout << "[环形链表已经空了]";
        return NULL;
    }
    else
    {
        if(del==head) //删除的节点是链表头部
        {
            CurNode=head;
            while(CurNode->next != head)
                CurNode=CurNode->next;
                //找到最后一个节点并记录下来
                TailNode=CurNode;
                //(1)将链表头指针移到下一个节点
                head=head->next;
                //(2)将链表最后一个节点的指针指向新的链表头部
                TailNode->next=head;
                return head;
        }
        else //要删除的节点不是链表头部
        {
            CurNode=head;
            while(CurNode->next != del)
                CurNode=CurNode->next;
            //(1)找到要删除节点的前一个节点并记录下来
            PreNode=CurNode;
            //要删除的节点
            CurNode=CurNode->next;
            //(2)将要删除节点的前一个指针指向要删除节点的下一个节点
            PreNode->next=CurNode->next;
            free(CurNode);
            return head;
        }
    }
}
int main()
{  
	link head,ptr,newnode;
	int new_num, new_score;
	char new_name[10];
	int i,j,position=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"}
    ,{"John"},{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"}
    ,{"Hanson"},{"Amy"},{"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));
    cout << "座号 成绩 座号 成绩 座号 成绩 座号 成绩"<< endl;
    cout << "==================================="<< endl;
    for(i=0;i<12;i++)
    {
        data[i][0]=i+1;
        data[i][1]=rand()%50+51;
    }
    for(i=0;i<3;i++)
    {  
		for (j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"]"<<setw(4)<<"["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
    head = new node;//建立链表头指针
    if(!head)
	{  
		cout<<"Error!! 内存分配失败!!"<<endl;
		exit(1);
	}
    head->num=data[0][0];
	for (j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
    for(i=1;i<12;i++) //建立链表
	{  
		newnode=new node;
		newnode->num=data[i][0];
		for (j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;	//将前一个节点指向新建立的节点
		ptr=newnode;			//新节点成为前一个节点
	}
    newnode->next=head;		//将最后一个节点指向头部节点就成了环形链表
	while(1)
	{  
		cout<<"请输入要删除的学生编号，结束输入-1：";
		cin>>position;
		if(position==-1) //循环中断条件
			break;
		else
		{  
			ptr=findnode(head,position);
			head=deletenode(head,ptr);
		}
	}
    ptr=head;//指向链表的开头
	cout<<"\n\t座号\t    姓名\t成绩\n";         
	cout<<"\t==============================\n";
	do
	{
	    cout<<"\t["<<ptr->num<<"]\t[ "<<setw(10)<<ptr->name<<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;//指向下一个节点
    } while(head!=ptr && head!=head->next);
    free(head);
	return 0;
}