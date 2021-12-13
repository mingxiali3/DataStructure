/*
 [名称]:09_calcultaeThelengthofstring.cpp
 [示范]：1.利用for循环来计算字符串长度
        2.从字符串中一个一个地取出元素内容并复制到另一个字符串中
*/
#include <iostream>
#include <cstdlib>
using namespace std;
char Str1[6]={'H','e','l','l','o','\0'};
char Str2[6];
int main()
{
    int i;
    int j = 0;
    for(i=0;i<6;i++)
    {
      Str2[i]=Str1[i];
      ++j;
    }
    cout << "The length of Str1 is : " << j << endl;
    for(i=0;i<6;i++)
    {
      cout << Str2[i] << " ";
    }
    cout << endl;
    return 0;
}