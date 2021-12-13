/*
 [名称]:10_inverseoutput.cpp
 [示范]：1.设计一个C++程序，将用户输入的原始字符串数据以反向排列输出。
        如"holiday"，会输出"yadiloh"。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
char Str1[8] = "holiday";
char Str2[8];
int main()
{
    int i,j;
for (i = 8, j=0; i >= 0 ;i--,j++)
    {
      Str2[j] = Str1[i];
    }
    for (int i = 0 ; i <= 8 ; i++)
    {
        cout << Str2[i]; 
    }
    cout << endl;
    return 0;
}