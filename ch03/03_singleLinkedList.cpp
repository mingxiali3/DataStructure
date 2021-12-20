/*
 [名称]:03_singleLinkedList.cpp
 [示范]：1.设计一个C++程序，建立5个学生成绩的单向链表，然后遍历每一个节点来输出成绩。
*/
#include <iostream>
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
int main()
{
   link newnode,ptr,delptr;//声明三个链表结构的指针
   cout << "请输入5位学生的数据: " << endl;
   delptr = new node;//delptr暂当链表头指针
   if(!delptr)
   {
        cout << "[Error!!内存分配失败！]" << endl;
        exit(1);
   }
   cout << "请输入座号: " ;
   cin >> delptr->num;
   cout << "请输入姓名： ";
   cin >> delptr->name;
   cout << "请输入成绩： ";
   cin >> delptr->score;
   ptr = delptr;//保留链表头指针，以ptr为指向当前节点的指针
   for(int i=1;i<5;i++)
   {
        newnode = new node;//创建新节点
        if(!newnode)
        {
          cout << "[Error !!内存分配失败！]" << endl;
          exit(1);
        }
        cout << "请输入座号: ";
        cin >> newnode->num;
        cout << "请输入姓名： ";
        cin >> newnode->name;
        cout << "请输入成绩： ";
        cin >> newnode->score;
        newnode->next = NULL;
        ptr->next = newnode;//把新节点加在链表后面
        ptr = ptr->next;//让ptr保持在链表的最后面
   }
   cout << "\n 学生成绩 " << endl;
   cout << "座号\t 姓名 \t 成绩 \n ========================" << endl;
   ptr = delptr;//让ptr回到链表头
   while(ptr!=NULL)
   {
     cout << ptr->num << "\t" << ptr->name << "\t" << ptr->score << endl;
     delptr= ptr;
     ptr=ptr->next;//ptr按序往后遍历整个链表
     delete delptr;//释放内存空间
   }


  return 0;
}