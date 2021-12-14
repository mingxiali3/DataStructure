/*
 [名称]:13_showString.cpp
 [示范]：1.设计一个C++程序示范String类的字符串声明
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
int main()
{
    char ch[] = " , ";
    string firstname;//声明字符串类
    string lastname;//声明字符串类
    string input1("请输入姓氏: ");
    string input2="请输入名字: ";
    cout << input1;
    cin >> lastname;//输入字符串
    cout << input2;
    cin >> firstname;//输入字符串
    string fullname = firstname + ch + lastname;// 以运算符进行字符串的串接
    cout << "您的全名为: " << fullname << endl;
    return 0;
}