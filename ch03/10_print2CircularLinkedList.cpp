/*
 [名称]:10_print2CircularLinkedList.cpp 
 [示范]：1.设计一个C++程序，将两个学生成绩的环形链表连接起来，然后打印出连接后的链表内容
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
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
link create_link(int data[10][2],int num);
void print_link(link head);
link concat(link ptr1,link ptr2);
int main()
{
    link ptr1,ptr2,ptr;
	int i,data1[6][2],data2[6][2];
	srand(time(NULL));
    for (i=1;i<=6;i++)
	{  
		data1[i-1][0]=i*2-1;
		data1[i-1][1]=rand()%49+52;
		data2[i-1][0]=i*2;
		data2[i-1][1]=rand()%49+52;
	}
    ptr1=create_link(data1,6);//建立串行1
	ptr2=create_link(data2,6);//建立串行2
    i=0;
	cout<<"\t\t       原 链 表 数 据："<<endl;
	cout<<"\t    座号 成绩   座号 成绩   座号 成绩"<<endl;
	cout<<"\t    =================================="<<endl;
	cout<<"环形链表1 ：";
    print_link(ptr1);
    cout<<"环形链表2 ：";
	print_link(ptr2);
	cout<<"\t    =================================="<<endl;
	cout<<"连接后的链表：";
	ptr=concat(ptr1,ptr2);			//连接环形链表
	print_link(ptr);
}
link create_link(int data[10][2],int num) //建立链表子程序
{  
	link head,ptr,newnode;
	for(int i=0;i<num;i++)
	{  
		newnode=new node;
		if(!newnode)
		{  
			cout<<"Error!! 内存分配失败!!"<<endl;
			exit(i);
		}
		if(i==0)//建立链表头部
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else //建立链表其他节点
		{  
			newnode->num=data[i][0];
			newnode->score=data[i][1];
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
		newnode->next=head;
	}
	return ptr;//返回链表
}
void print_link(link head)//打印链表子程序
{  
	link ptr;
	int i=0;
	ptr=head->next;
	do 
	{  
		cout<<"["<<setw(2)<<ptr->num<<"-"<<setw(3)
            <<ptr->score<<"] -> ";
		i++;
		if(i>=3)//每行打印三个元素
		{  
			cout<<"\n\t    ";
			i=0;
		}
		ptr=ptr->next;
	}while(ptr!=head->next);
	cout<<endl;
}
link concat(link ptr1,link ptr2)		//连接链表子程序
{  
	link head;
	head=ptr1->next;		//在ptr1和ptr2中，各找任意一个节点
	ptr1->next=ptr2->next;	//把两个节点的next对调即可
	ptr2->next=head;
	return ptr2;
}