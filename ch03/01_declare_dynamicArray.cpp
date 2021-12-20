/*
 [名称]:01_declare_dynamicArray.cpp
 [示范]：1.设计一个C++程序，动态声明一个指向整数50的指针，与一个指向未设置存储值的浮点数
          指针，在程序中设置0.5，最后再使用delete关键词将其释放。
*/
#include <iostream>
using namespace std;
int main()
{
    //声明指向整数的指针，在该内存中存入整数值50
    int* intptr = new int(50);
    //声明指向浮点数的指针，但未指定内存中存储的数据值
    float* floatptr = new float;
    *floatptr= 0.5;
    cout << "intptr指向的数据值: " << *intptr << "\n\n";
    cout << "floatptr指向的数据值: " << *floatptr << "\n\n";
    delete intptr;
    delete floatptr;
    return 0;
}