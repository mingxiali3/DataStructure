/*
 [名称]:01_fivestudentScore.cpp
 [示范]：1.使用C++的一维数组来记录5个学生的分数
        2.使用for循环输出每位学生的成绩
        3.计算学生的总分数
        4.计算学生分数的平均值
*/
#include <iostream>
using namespace std;
int main()
{
    int Score[5]={ 90 , 67 , 87, 90, 78};
    int count = 5;
    int sum= 0;
    double averg = 0.0;
    cout << "输出成绩： " << endl;
    for(int i = 0; i< count; i++)
    {
        cout << "第"<< i+1 << "位学生的成绩 ： " << Score[i] << endl;
        sum += Score[i]; 
    }
    cout << "5位学生的总分数为： " << sum << endl;
    averg = sum / 5.0;
    cout << "学生分数的平均值： " << averg << endl;
    return 0;
}