/*
 [名称]:12_showStringArray.cpp
 [示范]：1.设计一个C++程序，来展示字符串数组的声明与输出方式
        2.并省略每个元素之间的大括号，以此说明字符与字符串之间的关联
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    char Str[6][30] = { "张继  枫桥夜泊",
                        "=============",
                        "月落乌啼霜满天",
                        "江枫渔火对愁眠",
                        "姑苏城外寒山寺",
                        "夜半钟声到客船"
                      };
    int i;
    for(i=0;i<6;i++)
        cout << Str[i] << endl;//这里只输出字符串数组的内容哦
    return 0;
}