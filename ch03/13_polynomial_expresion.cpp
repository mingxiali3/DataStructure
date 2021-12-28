/*
 [名称]:13_polynomial_expresion.cpp 
 [示范]：1.设计一个C++程序，计算两个已知多项式的和，并输出最后的结果。
         A=3X^3 + 4X + 2
         B=6X^3 + 8X^2 + 6X + 9
*/
#include <iostream>
using namespace std;
class list //声明链表结构
{
    public:
        int coef,exp;
        class list *next;
};
typedef class list node;
typedef node *link;
link create_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);
int main()
{
    link a,b,c;
    int data1[4] = {3,0,4,2};//多项式A的系数
    int data2[4] = {6,8,6,9};//多项式B的系数
    cout << "原始多项式: " << endl << "A= ";
    a=create_link(data1);//建立多项式A
    b=create_link(data2);//建立多项式B
    print_link(a);//打印多项式
    cout << "B=";
    print_link(b);//打印多项式B
    cout << "多项式相加的结果: \nC= ";
    c=sum_link(a,b);//C为A，B多项式相加的结果
    print_link(c);//打印多项式C

}
link create_link(int data[4]) //建立多项式子程序
{
    link head,newnode,ptr;
    for(int i=0;i<4;i++)
    {
        newnode = new node;
        if(!newnode)
        {
            cout << "Error!!内存分配失败!!" << endl;
            exit(1);
        }
        if(i==0)
        {
            newnode->coef=data[i];
            newnode->exp=3-i;
            newnode->next=NULL;
            head=newnode;
            ptr=head;
        }
        else if(data[i]!=0)
        {
            newnode->coef=data[i];
            newnode->exp=3-i;
            newnode->next=NULL;
            ptr->next=newnode;
            ptr=newnode;
        }
    }
    return head;
}
void print_link(link head) //打印多项式子程序
{
    while(head !=NULL)
    {
        if(head->exp==1 && head->coef != 0) //X^1 时不显示指数
            cout << head->coef << "X + ";
        else if (head->exp != 0 && head->coef != 0)
            cout << head->coef << "X^ " << head->exp << " + ";
        else if (head->coef != 0) //X^0时不显示变量
            cout << head->coef;
        head=head->next;
    }
    cout << endl;
}
link sum_link(link a,link b) //多项式相加子程序
{
    int sum[4],i=0;
    link ptr;
    ptr = b;
    while(a !=NULL) //判断多项式1
    {
        b=ptr;//重复比较A和B的指数
        while(b!=NULL)
        {
            if(a->exp==b->exp) //指数相等，系数相加
            {
                sum[i]=a->coef+b->coef;
                a=a->next;
                b=b->next;
                i++;
            }
            else if (b->exp > a->exp ) //B指数较大，指定系数给C
            {
                sum[i]=b->coef;
                b=b->next;
                i++;
            }
            else if(a->exp > b->exp) //A指数较大，指定系数给C
            {
                sum[i]=a->coef;
                a=a->next;
                i++;
            }
        }
    }
    return create_link(sum);//建立相加结果的链表C
}