/*
 [名称]:08_fivestudentStructure.cpp
 [示范]：1.声明5个学生的结构数组
        2.其中每个学生的结构中又有成绩的数组成员
        3.最后存取并输出学生结构数组的数组成员元素
*/
#include <iostream>
using namespace std;
struct student
{
    char name[10];
    int score[3];
};//声明student结构

//声明5个学生的结构数组
struct student class1[5] = {{"Justin",90,76,54},{"momor",95,88,54},
                           {"Becky",98,66,90},{"Bush",75,54,100},
                           {"Snoopy",80,88,97}};//设置5个成员的初始值
int main()
{
int i;
for (i = 0; i < 5 ; i++)
{
    cout << "姓名： " << class1[i].name << '\t' << "成绩： "
    << class1[i].score[0] << '\t' << class1[i].score[1] << '\t'
    << class1[i].score[2] << endl;
    //存取并输出student结构数组的成员元素
    cout << "------------------------------------------" << endl;
}
return 0;
}